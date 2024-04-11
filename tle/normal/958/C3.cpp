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

const int N = 500005;
const int inf = 0x3f3f3f3f;

int n, m, p, sum, a[N], b[N], f[N], g[N];

inline void Modify(int x, int y) {
  for (++x; x <= p; x += x & -x) {
    CheckMin(b[x], y);
  }
}

inline int Query(int x) {
  int r = inf;
  for (++x; x; x -= x & -x) {
    CheckMin(r, b[x]);
  }
  return r;
}

inline void DP() {
  for (int i = 0; i < p; ++i) {
    b[i + 1] = inf;
  }
  int min_val = inf;
  for (int i = 0; i <= n; ++i) {
    g[i] = min(min_val + 1, Query(a[i]));
    Modify(a[i], f[i]);
    CheckMin(min_val, f[i]);
  }
  for (int i = 0; i <= n; ++i) {
    f[i] = g[i];
  }
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(p);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]), a[i] = (a[i] + a[i - 1]) % p;
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = inf;
  }
  while (m--) {
    DP();
  }
  printf("%d\n", f[n] * p + a[n]);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}