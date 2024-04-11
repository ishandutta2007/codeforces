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

const int N = 20005;
const int inf = 0x3f3f3f3f;

int n, m, p, f[N], g[N], s[N], v[N];

inline void DP() {
  for (int i = 0; i < p; ++i) {
    v[i] = -inf;
  }
  for (int i = 0; i <= n; ++i) {
    g[i] = -inf;
    for (int j = 0; j < p; ++j) {
      if (v[j] != -inf) {
        CheckMax(g[i], v[j] + (s[i] - j + p) % p);
      }
    }
    CheckMax(v[s[i]], f[i]);
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
    Read(s[i]), s[i] = (s[i] + s[i - 1]) % p;
  }
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = -inf;
  }
  while (m--) {
    DP();
  }
  printf("%d\n", f[n]);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}