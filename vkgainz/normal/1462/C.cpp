#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e6+5;
int main() {
  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    if(x>45) cout << -1 << "\n";
    else {
      int l  = 0;
      for(int len=9;len>=1;len--) {
        int lo= len*(len+1)/2;
        int up = (18-len+1)*len/2;
        if(lo<=x && x<=up)
          l = len;
      }
      int mn = 0;
      int ans = 0;
      for(int i=0;i<l;i++) {
        for(int j=mn+1;j<=9;j++) {
          if(i==l-1) {
            if(j==x) ans+=j;
          }
          else {
            int len = l-i-1;
            int lo = (2*j+1+len)*len/2;
            int hi = (18-len+1)*len/2;
            if(lo<=(x-j) && (x-j)<=hi) {
              x-=j;
              ans+=pow(10, l-i-1)*j;
              mn = j;
              break;
            }
          }
        }
      }
      cout << ans << "\n";
    }
  }
}