#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;

const int MOD = 998244353;
const int me = 15;
const int ms = 1 << me;
//const int MOD = 754974721;

ll fexp(ll x, ll e, ll mod = MOD) {
  ll ans = 1;
  x %= mod;
  for(; e > 0; e /= 2) {
    if(e & 1) {
      ans = ans * x % mod;
    }
    x = x * x % mod;
  }
  return ans;
}

//is n primitive root of p ?
bool test(ll x, ll p) {
  ll m = p - 1;
  for(int i = 2; i * i <= m; ++i) if(!(m % i)) {
    if(fexp(x, i, p) == 1) return false;
    if(fexp(x, m / i, p) == 1) return false;
  }
  return true;
}

//find the largest primitive root for p
int search(int p) {
  for(int i = p - 1; i >= 2; --i) if(test(i, p)) return i;
  return -1;
}

std::map<int, int> roots;

int get_root(int p) {
  if(roots[p]) {
    return roots[p];
  } else {
    roots[p]=search(p);
    return roots[p];
  }
}

#define add(x, y) x+y>=MOD?x+y-MOD:x+y

const int gen = search(MOD);
int bits[2*ms], root[2*ms];

void initFFT() {
  root[1] = 1;
  for(int len = 2; len < 2*ms; len += len) {
    int z = fexp(gen, (MOD - 1) / len / 2);
    for(int i = len / 2; i < len; i++) {
      root[2 * i] = root[i];
      root[2 * i + 1] = (long long) root[i] * z % MOD;
    }
  }
}

void pre(int n) {
  int LOG = 0;
  while(1 << (LOG + 1) < n) {
    LOG++;
  }
  for(int i = 1; i < n; i++) {
    bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
  }
}

std::vector<int> fft(std::vector<int> a, int mod, bool inv = false) {
  int n = (int) a.size();
  pre(n);
  if(inv) {
    std::reverse(a.begin() + 1, a.end());
  }
  for(int i = 0; i < n; i++) {
    int to = bits[i];
    if(i < to) 
      std::swap(a[i], a[to]);
  }
  for(int len = 1; len < n; len *= 2) {
    for(int i = 0; i < n; i += len * 2) {
      for(int j = 0; j < len; j++) {
        int u = a[i + j], v = (ll) a[i + j + len] * root[len + j] % mod;
        a[i + j] = add(u, v);
        a[i + j + len] = add(u, mod - v);
      }
    }
  }
  if(inv) {
    int rev = fexp(n, mod-2, mod);
    for(int i = 0; i < n; i++)
      a[i] = (ll) a[i] * rev % mod;
  }
  return a;
}

void prepare(std::vector<std::vector<int> > &x, bool inv = false)
{
  for(int i=0;i<3;i++)
  {
    x[i].resize(2*ms, 0);
    x[i] = fft(x[i], MOD, inv);
  }
}

std::vector<std::vector<int> > combine(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b)
{
  std::vector<std::vector<int> > ans(3, std::vector<int>(ms, 0));

  std::vector<int> cur(2*ms, 0);

  for(int i=0;i<cur.size();i++)
    cur[i] = (ll) a[2][i] * b[2][i] % MOD;
  cur = fft(cur, MOD, true);

  for(int i=0;i<ms;i++)
    ans[2][i] = add(ans[2][i], cur[i]);

  for(int i=0;i<cur.size();i++)
    cur[i] = (ll) a[2][i] * b[1][i] % MOD;
  cur = fft(cur, MOD, true);

  for(int i=0;i<ms;i++)
    ans[1][i] = add(ans[1][i], cur[i]);

  for(int i=0;i<cur.size();i++)
    cur[i] = (ll) a[1][i] * b[1][i] % MOD;
  cur = fft(cur, MOD, true);

  for(int i=0;i<ms;i++)
    ans[0][i] = add(ans[0][i], cur[i]);
  for(int i=1;i<ms;i++)
    ans[2][i] = add(ans[2][i], cur[i-1]);

  for(int i=0;i<cur.size();i++)
    cur[i] = (ll) a[1][i] * b[0][i] % MOD;
  cur = fft(cur, MOD, true);

  for(int i=1;i<ms;i++)
    ans[1][i] = add(ans[1][i], cur[i-1]);

  for(int i=0;i<cur.size();i++)
    cur[i] = (ll) a[0][i] * b[0][i] % MOD;
  cur = fft(cur, MOD, true);

  for(int i=1;i<ms;i++)
    ans[0][i] = add(ans[0][i], cur[i-1]);

  return ans;
}

std::vector<int> polynomial_fexp(std::vector<int> basee, ll e)
{
  std::vector<std::vector<int> > ans(3, std::vector<int>(ms, 0));
  std::vector<std::vector<int> > base(3, std::vector<int>(ms, 0));
  base[1][0]=1;
  base[2]=basee;
  ans[2][0]=1;
  while(e)
  {
    prepare(base);
    if(e&1)
    {
      prepare(ans);
      ans = combine(ans, base);
    }
    base = combine(base, base);
    e >>= 1;
  }
  return ans[2];
}

int main() {
  ll n, k;
  initFFT();
  std::cin >> n >> k;
  std::vector<int> base(ms, 0);
  base[0] = base[1] = 1;
  std::vector<int> ans = polynomial_fexp(base, n);
  for(int i=1;i<=k;i++)
  {
    if(i!=1)
      printf(" ");
    printf("%i", ans[i]);
  }
  std::cout << '\n';
}