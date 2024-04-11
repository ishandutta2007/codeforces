#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  string s;
  cin >> s;
  ll ans = 0;
  vi pre(30,0), suf(30,0);
  rep(a,0,30) {
    ll q = count(all(s), 'a'+a);
    suf[a] = q;
    smax(ans, q*(q-1)/2);
    smax(ans, q);
  }
  vector<vi> res(30, vi(30,0));
  trav(c, s) {
    int k = c-'a';
    pre[k]++;
    suf[k]--;
    rep(a,0,30) res[k][a] += suf[a];
  }
  rep(a,0,30) rep(b,0,30) smax(ans, res[a][b]);
  cout << ans << endl;
}