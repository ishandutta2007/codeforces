#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = (119 << 23) + 1, root = 62;

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
uniform_int_distribution<> uid(0,mod-1);

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  vi p(26);
  trav(x, p) { cin >> x; --x; }
  string s, t;
  cin >> s >> t;
  reverse(all(s));

  // f(x,y,z) = (x-z)(y-z)c
  // f = 0 iff z=x,y
  vector<vl> qs(3,vl(sz(s))), qt(3,vl(sz(t)));
  rep(i,0,sz(s)) {
    ll x = s[i]-'a', y = p[s[i]-'a'], c = uid(rng);
    c = 1;
    qs[0][i] = x*y*c % mod;
    qs[1][i] = (mod-(x+y))*c % mod;
    qs[2][i] = c % mod;
  }
  rep(i,0,sz(t)) {
    ll z = t[i]-'a', c = uid(rng);
    qt[0][i] = c % mod;
    qt[1][i] = c*z % mod;
    qt[2][i] = c*z*z % mod;
  }
  vl ans(sz(t)+sz(s));
  rep(j,0,3) {
    auto r = conv(qs[j], qt[j]);
    rep(i,0,min(sz(ans),sz(r))) ans[i] = (ans[i] + r[i] + mod)%mod;
  }

  rep(i,sz(s)-1,sz(t)) cout << (ans[i] == 0);
  cout << endl;
}