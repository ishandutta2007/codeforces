#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 100005;

int n, rot, f[N], ans[N], dep[N], par[N], son[N];
vector <int> all, adj[N];

inline void DFS(int x) {
  for (auto y : adj[x]) {
    if (y != par[x]) {
      par[y] = x, dep[y] = dep[x] + 1, DFS(y);
    }
  }
}

inline void DP(int x) {
  f[x] = 1;
  for (auto y : adj[x]) {
    if (y != par[x]) {
      par[y] = x, DP(y);
      if (CheckMax(f[x], f[y] + 1)) {
        son[x] = y;
      }
    }
  }
  for (auto y : adj[x]) {
    if (y != par[x] && y != son[x]) {
      all.pb(f[y]);
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n);
  for (int i = 1, x, y; i < n; ++i) {
    Read(x), Read(y);
    adj[x].pb(y), adj[y].pb(x);
  }
  dep[1] = 1, DFS(1);
  for (int i = 1; i <= n; ++i) {
    if (dep[i] > dep[rot]) {
      rot = i;
    }
  }
  par[rot] = 0, DP(rot), all.pb(f[rot]);
  sort(all.begin(), all.end(), greater <int> ());
  for (int i = 0; i < all.size(); ++i) {
    ans[i + 2] = ans[i + 1] + all[i];
  }
  for (int i = all.size() + 2; i <= n; ++i) {
    ans[i] = n;
  }
  ans[1] = 1;
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i], i == n ? '\n' : ' ');
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}