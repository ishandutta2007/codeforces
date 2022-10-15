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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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
const int N = 100005;
int f[N], n, m;
int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
      int x = read(), y = read();
      if (x != y) {
        ans++;
        if (find(x) == find(y)) ans++;
        f[find(x)] = find(y);
      }
    }
    print(ans, '\n');
  }
  return 0;
}