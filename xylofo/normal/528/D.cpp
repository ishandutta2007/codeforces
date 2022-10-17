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

const ll mod = (119 << 23) + 1, root = 62; // = 998244353

ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}

typedef vector<ll> vl;
void ntt(vl& a, vl& rt, vl& rev, int n) {
  rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
      ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
      a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
      ai += (ai + z >= mod ? z - mod : z);
    }
}

vl conv(const vl& a, const vl& b) {
  if (a.empty() || b.empty())
    return {};
  int s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
  vl L(a), R(b), out(n), rt(n, 1), rev(n);
  L.resize(n), R.resize(n);
  rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
  ll curL = mod / 2, inv = modpow(n, mod - 2);
  for (int k = 2; k < n; k *= 2) {
    ll z[] = {1, modpow(root, curL /= 2)};
    rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  ntt(L, rt, rev, n); ntt(R, rt, rev, n);
  rep(i,0,n) out[-i & (n-1)] = L[i] * R[i] % mod * inv % mod;
  ntt(out, rt, rev, n);
  return {out.begin(), out.begin() + s};
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  uniform_int_distribution<> uid(0,mod-1);

  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int sn, st, k;
  string s, t;
  cin >> sn >> st >> k >> s >> t;
  reverse(all(t));

  map<char,int> cnt;
  int l = 0, r=-1;

  // f(x,a,b,c,d) = (x-a)(x-b)(x-c)(x-d)c
  // f = 0 iff x=a,b,c,d
  vector<vl> qs(5,vl(sz(s))), qt(5,vl(sz(t)));
  rep(i,0,sz(s)) {
    while(r < min(i+k,sz(s))) cnt[s[++r]]++;
    while(l < i-k) cnt[s[l++]]--;
    vi a(4);
    a[0] = cnt['A'] ? 'A' : s[i];
    a[1] = cnt['C'] ? 'C' : s[i];
    a[2] = cnt['G'] ? 'G' : s[i];
    a[3] = cnt['T'] ? 'T' : s[i];
    qs[0][i] = uid(rng);
    rep(j,0,4) {
      for(int ii = 4; ii >= 0; --ii) {
        qs[ii][i] = ((ii ? qs[ii-1][i] : 0) - a[j]*qs[ii][i]);
        qs[ii][i] = (qs[ii][i]%mod + mod)%mod;
      }
    }
  }
  rep(i,0,sz(t)) {
    ll x = t[i], c = uid(rng);
    qt[0][i] = c % mod;
    qt[1][i] = x % mod * c % mod;
    qt[2][i] = x*x % mod * c % mod;
    qt[3][i] = x*x*x % mod * c % mod;
    qt[4][i] = x*x*x*x % mod * c % mod;
  }
  vl ans(sz(t)+sz(s));
  rep(j,0,5) {
    auto r = conv(qs[j], qt[j]);
    rep(i,0,min(sz(ans),sz(r))) ans[i] = (ans[i] + r[i] + mod)%mod;
  }
  //debug(ans);

  int res = 0;
  rep(i,sz(t)-1,sz(s)) if(ans[i] == 0) ++res;
  cout << res << endl;
}