// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
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

const int N = 500005;
int f[N], g[N], type[N], vis[N];
int n;

void WA() { puts("-1"), exit(0); }

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int a = read(), b = read();
    f[a] = b, f[b] = a;
    g[a] = 0, g[b] = 1;
    type[a] = type[b] = i;
  }
  int l = 1, r = 2 * n, ans = 0;
  while (l <= r) {
    int cnt[2] = {0};
    while (l <= r && vis[type[l]]) l++;
    if (l > r) break;
    int u = l, state = 0;
    cnt[g[l]]++, vis[type[l]] = 1;
    l++;
    while (l <= r) {
      if (!state) {
        int lst = 0;
        while (l <= r) {
          if (type[u] == type[r]) break;
          if (vis[type[r]]) { r--; continue; }
          if (f[r] > f[u] || (lst && f[r] < f[lst])) WA(); 
          vis[type[r]] = 1;
          cnt[g[r]]++;
          lst = r, r--;
        }
        if (!lst) break;
        u = lst; 
      } else {
        int lst = 0;
        while (l <= r) {
          if (type[u] == type[l]) break;
          if (vis[type[l]]) { l++; continue; }
          if (f[l] < f[u] || (lst && f[l] > f[lst])) WA();
          vis[type[l]] = 1;
          cnt[g[l]]++;
          lst = l, l++;
        }
        if (!lst) break;
        u = lst;
      }
      state ^= 1;
    }
    ans += min(cnt[0], cnt[1]);
  }
  printf("%d\n", ans);
  return 0;
}