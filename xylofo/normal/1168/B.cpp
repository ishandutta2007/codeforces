#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  string s;
  cin>>s;
  int n = sz(s);
  s = "#" + s + "$";
  ll ans = 0;
  int r = 1, k = 1;
#define x (r-2*k)
  rep(l,1,n+1) {
    while(x < l && r <= n) {
      ++r;
      for(k = 1; x >= l; ++k)
        if(s[x] == s[x+k] && s[x] == s[x+2*k]) break;
    }
    ans += n-r+1;
  }
  cout << ans << endl;
}