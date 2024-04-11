#include<bits/stdc++.h> 
using namespace std; 
int main() { 
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  int rx=abs(x1-x2)+1;
  rx=max(rx,2);
  int ry=abs(y1-y2)+1;
  ry=max(ry,2);
  cout<<rx*2+ry*2;
}