#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int y, b, r; cin >> y >> b >> r;
  int ans = 0;
  for(int a=0;a<=100;a++) {
    if(a<=y && a+1<=b && a+2<=r) {
      ans = 3*a+3;
    }
  }
  cout << ans;
}