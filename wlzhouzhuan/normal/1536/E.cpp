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
#define poly vector<int>
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

const int N = 2005;
const int mod = 1e9 + 7;

char a[N][N];
int n, m;

int qpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return res;
}

void solve() {
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '#') ++cnt;
    }
  }
  printf("%d\n", (qpow(2, cnt) - (cnt == n * m) + mod) % mod);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}