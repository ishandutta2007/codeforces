#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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


const ll LIM = 200000;
vl inv(LIM,1);
vl fact(LIM,1);
vl invfact(LIM,1);

ll choose(ll n, ll r) {
  if(r < 0 || n < r) return 0;
  return fact[n] * invfact[r] % mod * invfact[n-r] % mod;
}

vl c(ll l, ll r){ // stirling numbers
  if(l+1 == r) return {l, 1};
  if(r <= l) return {1};
  ll m = (l+r)/2;
  vl a = c(l,m);
  vl b = c(m,r);
  return conv(a, b);
}

int main() {
  rep(i,2,LIM) {
    inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    fact[i] = i*fact[i-1] % mod;
    invfact[i] = inv[i]*invfact[i-1] % mod;
  }

  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  ll N, A, B;
  cin>>N>>A>>B;

  vl q = c(0,N-1);
  ll s = A+B-2;
  ll ans = 0;
  if(s < sz(q)) ans = q[s];
  ans = (ans * choose(s, A-1)) % mod;
  cout << ans << endl;
}