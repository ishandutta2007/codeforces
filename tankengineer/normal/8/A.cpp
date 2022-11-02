//CF 8A
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int p1, p2;
string s1, s2, s3, s4, s5;
bool fan, fow, baw;

int main() {
  cin>>s1>>s2>>s3;
  p1 = s1.find(s2);
  p2 = s1.rfind(s3);
  if (p1 == string::npos || p2 == string::npos || p1 + s2.size() > p2) {
    fow = false;
  } else {
    fow = true;
  }
  
  for (int i = s2.size() - 1; i >= 0; i--) {
    s4 = s4 + s2[i];
  }
  for (int i = s3.size() - 1; i >= 0; i--) {
    s5 = s5 + s3[i];
  }
  
  p1 = s1.rfind(s4);
  p2 = s1.find(s5);
  if (p1 == string::npos || p2 == string::npos || p2 + s5.size() > p1) {
    baw = false;
  } else {
    baw = true;
  }

  fan = !fow && !baw;
  
  if (fan) {
    cout<<"fantasy"<<endl;
  } else if (fow && baw) {
    cout<<"both"<<endl;
  } else if (fow) {
    cout<<"forward"<<endl;
  } else if (baw) {
    cout<<"backward"<<endl;
  }
  return 0;
}