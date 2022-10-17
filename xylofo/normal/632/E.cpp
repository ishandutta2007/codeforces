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


int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  vl v(1005);
  rep(i,0,n) {
    int x;
    cin>>x;
    v[x] = 1;
  }

  auto mul = [&](vl &a, const vl& b) {
    a = conv(a,b);
    while(sz(a) > 5 && a.back() == 0) a.pop_back();
    trav(x, a) x = (x ? 1 : 0);
  };

  vl ans(1,1);
  while(k) {
    if(k&1) mul(ans, v);
    mul(v,v);
    k /= 2;
  }
  rep(i,1,sz(ans)) if(ans[i]) cout << i << " ";
  cout << endl;
}