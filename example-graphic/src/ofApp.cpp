#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    _tween = tweeny::from(0, 0) // starting position
                 .to(ofGetWidth(), ofGetHeight())
                 .during(120) // first keyframe, at 120 steps (2s, 60fps)
                 .to(ofGetWidth() / 2, ofGetHeight() / 2)
                 .during(60) // second keyframe, at 120 + 60 steps
                 .to(ofGetWidth() / 2, 0)
                 .during(30)
                 .via(tweeny::easing::circularInOut) // last keyframe at 120 + 60 + 30 steps
                 // finally add a callbacks, multiple callbacks are possible
                 .onStep([this](int x, int y) {
                     _x = x;
                     _y = y;
                     ofLogNotice() << "callback: " << x << " " << y;

                     if (_tween.progress() <= 0.001f)
                     {
                         _tween.forward();
                     }
                     if (_tween.progress() >= 1.0f)
                     {
                         _tween.backward();
                     }

                     return false;
                 });
}

//--------------------------------------------------------------
void ofApp::update()
{
    _tween.step(1);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(ofColor::lightSalmon);
    ofDrawCircle(_x, _y, 24);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
