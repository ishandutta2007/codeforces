#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main() {
  long long a=0;
  long long mn=0;
  cin >> a;
  long long pos=0;
  while(a--) {
    long long x, y;
    cin >> x >> y;
    pos-=x;
    mn=max(mn,pos);
    pos+=y;
    mn=max(mn,pos);
  }
  cout << mn;
}