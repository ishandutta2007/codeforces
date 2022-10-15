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
#define SZ(a) ((int)(a.size()))
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

vector<pii> ans;
vector<int> cycs[N];
int tot;
int vis[N], p[N], n;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) p[i] = read();
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int j = i;
      tot++;
      while (!vis[j]) {
        cycs[tot].pb(j);
        vis[j] = 1;
        j = p[j];
      }
      if (SZ(cycs[tot]) == 1) {
        cycs[tot].clear();
        tot--;
      }
    }
  }
  while (tot > 1) {
    vector<int> a = cycs[tot--];
    vector<int> b = cycs[tot--];
    ans.pb({a.back(), b.back()});
    for (int i = 0; i < SZ(a) - 1; i++) ans.pb({a[i], b.back()});
    for (int i = 0; i < SZ(b) - 1; i++) ans.pb({b[i], a.back()});
    ans.pb({a.back(), b.back()});
  }
  if (tot) {
    vector<int> a = cycs[tot];
    int len = SZ(a);
    if (len == 2) {
      int x = a[0], y = a[1], z;
      for (int i = 1; i <= n; i++) if (i != x && i != y) z = i;
      ans.pb({x, z});
      ans.pb({y, z});
      ans.pb({x, z});
    } else {
      ans.pb({a[len - 2], a[len - 1]});
      ans.pb({a[len - 3], a[len - 1]});
      for (int i = 0; i <= len - 3; i++) ans.pb({a[i], a[len - 2]});
      ans.pb({a[len - 2], a[len - 1]});
    }
  }
  printf("%d\n", SZ(ans));
  for (auto v: ans) printf("%d %d\n", v.fir, v.sec);
  return 0;
}