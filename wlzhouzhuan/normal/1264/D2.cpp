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
const int mod = 998244353;

char a[N];
int l1, l2, r1, r2;
int n;

int fac[N], ifac[N];
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  for (int i = n; i >= 1; i--) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int main() {
  init(N - 5);
  scanf("%s", a + 1), n = strlen(a + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == ')') r2++;
    if (a[i] == '?') r1++;
  }
  int ans = 0; 
  for (int i = 1; i < n; i++) {
    if (a[i] == '(') l2++;
    if (a[i] == '?') l1++, r1--;
    if (a[i] == ')') r2--;
    int d = r1 + r2 - l2;
    ans = (ans + 1ll * l2 * C(l1 + r1, d) + 1ll * l1 * C(l1 + r1 - 1, d - 1)) % mod;
  }
  printf("%d\n", ans);
  return 0;
}