#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1'000'000'007;
const ll inv2 = (mod+1)/2;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  string s, t;
  cin >> s >> t;

  vector<ll> pw2(n+9), ipw2(n+9);
  pw2[0] = ipw2[0] = 1;
  rep(i,1,n+9) {
    pw2[i] = (2*pw2[i-1]) % mod;
    ipw2[i] = (inv2*ipw2[i-1]) % mod;
  }

  vector<vector<ll>> occ(30, vector<ll>(n+10));
  rep(i,0,30) {
    for(int j = n; j--;) {
      if(t[j] == 'a'+i) occ[i][j] = (occ[i][j+1] + pw2[n-j-1]) % mod;
      else occ[i][j] = occ[i][j+1];
    }
  }

  function<ll(const string&,int,int)> solve = [&](const string& w, int k, int v) -> ll {
    if(v > k) return 0;
    if(sz(w) == 0) return (pw2[k-v]) % mod;
    if(sz(w) == 1)
      return ipw2[n-k] * (occ[w[0]-'a'][v] - occ[w[0]-'a'][k] + mod) % mod;

    ll ans = 0;
    rep(off,0,2) {
      string q;
      rep(i,0,sz(w)) {
        if((i+off) % 2 == 1) q.push_back(w[i]);
        else if(w[i] != t[v]) goto bad;
      }
      ans = (ans + solve(q,k,v+1)) % mod;
bad:;
    }
    return ans;
  };

  rep(i,0,q) {
    int k;
    string w;
    cin >> k >> w;

    ll ans = 0;
    rep(off,0,sz(s)+1) {
      string q;
      rep(i,0,sz(w)) {
        int j = (i+off) % (sz(s)+1);
        if(j == sz(s)) q.push_back(w[i]);
        else if(w[i] != s[j]) goto bad;
      }
      ans = (ans + solve(q,k,0)) % mod;
bad:;
    }

    cout << ans << "\n";
  }
}