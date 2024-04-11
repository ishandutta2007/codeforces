#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, l, r) for (int i = l; i <= r; i++) 
#define per(i, l, r) for (int i = l; i >= r; i--)

inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char ch) {
  print(x), putchar(ch);
}

template<typename T1, typename T2> void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

const int N = 100005;
char a[N], b[N];
int n, m;

int nxt[N][26][2];

void solve() {
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1), m = strlen(b + 1);
  memset(nxt[n + 1], 0, sizeof(nxt[n + 1]));
  for (int i = n; i >= 1; i--) {
    memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i + 1]));
    nxt[i][a[i] - 'a'][i & 1] = i;
  }
  // odd
  int pos = 0, ok = 1, cur = 1;
  for (int i = 1; i <= m; i++) {
    pos = nxt[pos + 1][b[i] - 'a'][cur];
    cur ^= 1;
    if (pos == 0) { ok = 0; break; }
  }
  if (ok && (n - pos) % 2 == 0) { puts("YES"); return ; }
  // even
  pos = 0, ok = 1, cur = 0;
  for (int i = 1; i <= m; i++) {
    pos = nxt[pos + 1][b[i] - 'a'][cur];
    cur ^= 1;
    if (pos == 0) { ok = 0; break; }
  }
  if (ok && (n - pos) % 2 == 0) { puts("YES"); return ; }
  puts("NO");
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}