#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    int mxL[n+1], mxR[n+1];
    mxL[0] = 0, mxR[0] = 0;
    for(int i=1;i<=n;i++) {
      if(s[i-1]=='L') {
        mxR[i] = 0, mxL[i] = 1+mxR[i-1];
      }
      else {
        mxL[i] =0 , mxR[i] = 1+mxL[i-1];
      }
    }
    int sufmxL[n+2], sufmxR[n+2];
    sufmxL[n+1] = 0, sufmxR[n+1] = 0;
    for(int i=n;i>=1;i--) {
      if(s[i-1]=='L') {
        sufmxL[i] = 1+sufmxR[i+1], sufmxR[i] = 0;
      }
      else {
        sufmxR[i] = 1+sufmxL[i+1], sufmxL[i] = 0;
      }
    }
    for(int i=1;i<=n+1;i++) {
      cout << mxL[i-1] + sufmxR[i] + 1 << "\n";
    }
  }
}