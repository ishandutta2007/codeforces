#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
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

const ll mod = 998'244'353; // (119 << 23) + 1

ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}


const ll root = 62;

typedef vector<ll> vl;
void ntt(vl &a) {
  int n = sz(a), L = 31 - __builtin_clz(n);
  static vl rt(2, 1);
  for (static int k = 2, s = 2; k < n; k *= 2, s++) {
    rt.resize(n);
    ll z[] = {1, modpow(root, mod >> s)};
    rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  vi rev(n);
  rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
      ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
      a[i + j + k] = ai - z + (z > ai ? mod : 0);
      ai += (ai + z >= mod ? z - mod : z);
    }
}
vl conv(const vl &a, const vl &b) {
  if (a.empty() || b.empty()) return {};
  int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
  int inv = modpow(n, mod - 2);
  vl L(a), R(b), out(n);
  L.resize(n), R.resize(n);
  ntt(L), ntt(R);
  rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
  ntt(out);
  return {out.begin(), out.begin() + s};
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  string s;
  cin>>s;
  ll evenQ = 0, oddQ = 0;
  ll evenB = 0, oddB = 0;
  rep(i,0,n) {
    if(s[i] == 'b') ++(i%2 ? oddB : evenB);
    if(s[i] == '?') ++(i%2 ? oddQ : evenQ);
  }

  int N = n+10;
  vector<ll> inv(N,1), fac(N, 1), ifac(N, 1), pw2(N,1);
  pw2[1] = 2;
  rep(i,2,N) {
    inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i-1] * i % mod;
    ifac[i] = ifac[i-1] * inv[i] % mod;
    pw2[i] = (pw2[i-1] * 2) % mod;
  }

  auto binom = [&](ll n, ll k) {
    if(k < 0 || k > n) return 0LL;
    return fac[n] * ifac[k] % mod * ifac[n-k] % mod;
  };

  ll ans = 0, tot = 0;
  //rep(x,0,evenQ+1) { // say we pick x of the evenQ to be B
  //  ll even = evenB + x;
  //  ll pick_even = binom(evenQ, x);
  //  rep(y,0,oddQ+1) {
  //    ll odd = oddB + y;
  //    ll pick_odd = binom(oddQ, y);
  //    if((even + odd) % 2 == 0) { // so that matching exists
  //      ll cases = pick_even * pick_odd % mod;
  //      tot = (tot + cases) % mod;
  //      ans = (ans + cases * abs(odd-even)) % mod;
  //    }
  //  }
  //}

  vl coeffEven(N);
  vl coeffOdd(N);
  rep(x,0,evenQ+1) coeffEven[x] = binom(evenQ, x);
  rep(y,0,oddQ+1) coeffOdd[n-y] = binom(oddQ, y);

  vl coeff = conv(coeffEven, coeffOdd);
  rep(t,0,sz(coeff)) {
    ll x_minus_y = t-n; // t = x+n-y
    ll odd_minus_even = oddB - evenB - x_minus_y;
    if(odd_minus_even % 2 == 0) { // matching exists
      ll cases = coeff[t];
      tot = (tot + cases) % mod;
      ans = (ans + cases * abs(odd_minus_even)) % mod;
    }
  }

  ans = ans * modpow(tot,mod-2) % mod;
  ans = ans * modpow(2,mod-2) % mod;
  cout << ans << endl;
}