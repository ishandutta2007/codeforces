#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<vector<vi>> pref(3, vector<vi>(3, vi(n+1,0))); // pref[char][mod][pos]
  rep(i,0,n) {
    rep(a,0,3) rep(b,0,3) pref[a][b][i+1] = pref[a][b][i];
    ++pref[(s[i]-'a')][i%3][i+1];
  }
  auto ival = [&](int l, int r, int ch, int md) {
    return pref[ch][md][r] - pref[ch][md][l];
  };
  
  rep(i,0,m) {
    int l, r;
    cin>>l>>r;
    --l;

    ll ans = 0;

    auto I = [&](int ch, int md) { return ival(l,r,ch,md); };
    vi p = {0,1,2};

    do {
      ans = max<ll>(ans, I(0,p[0])+I(1,p[1])+I(2,p[2]));
    } while(next_permutation(all(p)));
    cout << r-l-ans << endl;
  }
}