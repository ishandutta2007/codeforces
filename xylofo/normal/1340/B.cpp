#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

using bs = bitset<7>;
vector<string> Q = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  vi q(10), v(n);
  rep(i,0,10) q[i] = bs(Q[i]).to_ulong();
  rep(i,0,n) {
    string s;
    cin>>s;
    v[i] = bs(s).to_ulong();
  }
  //debug(q); debug(v);
  vector<vi> vis(n, vi(k+1,0));
  vi ans(n);
  function<void(int,int)> f = [&](int pos, int k) {
    //debug(pos, k);
    if(k < 0) return;
    if(pos == n) {
      if(k != 0) return;
      rep(i,0,n) cout << ans[i];
      cout << endl;
      exit(0);
    }
    if(vis[pos][k]) return;
    vis[pos][k] = 1;
    int s = v[pos];
    for(int i = 9; i >= 0; --i) {
      if((s & q[i]) == s) {
        ans[pos] = i;
        int t = __builtin_popcount(s ^ q[i]);
        f(pos+1, k-t);
      }
    }
  };
  f(0,k);
  cout << -1 << endl;
}