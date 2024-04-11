// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 1000005;
const int mod =  998244353;
const int inv6 = 166374059;

ll f[N], g[N], sumf[N], h[N];
int n;

ll mul(ll x, ll y) { return x * y % mod; }
ll C2(ll x) { return x * (x - 1) / 2 % mod; }
ll C3(ll x) { return x * (x - 1) % mod * (x - 2) % mod * inv6 % mod; }

int main() {
  f[0] = 1, g[0] = 1, h[0] = 1, sumf[0] = 1;
  n = read();
  for (int i = 1; i <= n; i++) {
    int coef = i >= 2 ? sumf[i - 2] : 0;
    f[i] = (f[i - 1] + mul(f[i - 1], coef) + C2(f[i - 1] + 1)) % mod;
    if (f[i] < 0) f[i] += mod;
    sumf[i] = (sumf[i - 1] + f[i]) % mod;
//    printf("f[%d] = %d\n", i, f[i]); 
  }
  ll coef = C2(sumf[n - 2] + 1);
//  for (int i = 0; i <= n - 2; i++) {
//    if (i) coef = (coef + sumf[i - 1] * f[i]) % mod;
//    coef = (coef + C2(f[i] + 1)) % mod;
//  }
  g[n] = (f[n] + C3(f[n - 1] + 2) + C2(f[n - 1] + 1) * sumf[n - 2] % mod + f[n - 1] * coef) % mod;
  ll ext = 0;
  for (int i = 1; i <= n; i++) h[i] = f[i - 1];
  for (int i = 1; i < n; i++) {
//    printf("%d %d\n",f[i],h[i]);
    ext = (ext + (f[i] - h[i] + mod) * h[n - i]) % mod;
    ext = (ext - (f[i] - h[i] + mod)) % mod;
    if (ext < 0) ext += mod;
  }
  printf("%d\n", ((2ll * g[n] - 1 + ext) % mod + mod) % mod);
  return 0;
}