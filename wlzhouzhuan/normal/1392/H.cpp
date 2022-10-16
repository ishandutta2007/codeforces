// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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
#define SZ(x) (int(x.size()))
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

const int N = 4000005;
const int mod = 998244353;

int inv[N];
int n, m;

int main() {
  inv[1] = 1;
  for (int i = 2; i < N; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  n = read(), m = read();
  int fn = 1;
  for (int i = 1; i <= n; i++) fn = (fn + 1ll * m * inv[i]) % mod;
  int E = 0, coef = 1;
  for (int i = 1; i <= n + 1; i++) {
    int j = i - 2;
    if (j >= 0) coef = 1ll * coef * (n - j) % mod * inv[n + m - j] % mod;
    E = (E + 1ll * i * m % mod * inv[n + m + 1 - i] % mod * coef) % mod;
  } 
  printf("%d\n", 1ll * E * fn % mod);
  return 0;
}