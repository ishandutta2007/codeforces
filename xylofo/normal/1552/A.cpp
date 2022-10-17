#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=int(b); a<int(c); ++a)
using namespace std;

void solve() {
  int n; cin >> n;
  string s;
  cin >> s;
  string s2=s;
  sort(s2.begin(), s2.end());
  int ans=0;
  rep(i,0,s.size()) {
    if(s[i]!=s2[i]) ++ans;
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  rep(i,0,t) solve();
}