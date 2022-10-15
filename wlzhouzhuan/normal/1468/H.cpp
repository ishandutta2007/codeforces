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

const int N = 200005;
int a[N], pre[N], suf[N], tag[N];
int n, k, m;

void solve() {
  n = read(), k = read(), m = read();
  for (int i = 1; i <= m; i++) a[i] = read();
  if ((n - m) % (k - 1)) return puts("NO"), void();
  for (int i = 0; i <= n + 1; i++) pre[i] = suf[i] = 1, tag[i] = 0;
  pre[0] = suf[n + 1] = 0;
  for (int i = 1; i <= m; i++) pre[a[i]]--, suf[a[i]]--, tag[a[i]] = 1;
  for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
  for (int i = n; i >= 1; i--) suf[i] += suf[i + 1];
  for (int i = 1; i <= n; i++) {
    if (tag[i] && pre[i - 1] >= k / 2 && suf[i + 1] >= k / 2) {
      puts("YES");
      return ;
    }
  }
  puts("NO");
}

int main() {
  for (int T = read(); T; T--) {
    solve();
  }
  return 0;
}