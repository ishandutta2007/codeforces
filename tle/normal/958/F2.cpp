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

const int N = 200005;
const int inf = 0x3f3f3f3f;

struct Heap {
  priority_queue <int, vector <int>, greater <int>> p, q;

  inline void I(int x) {
    p.push(x);
  }

  inline void O(int x) {
    q.push(x);
  }

  inline int T() {
    for (; !q.empty() && p.top() == q.top(); p.pop(), q.pop());
    return p.top();
  }
} h;

int n, m, ans, a[N], b[N];
queue <int> q[N];

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), ans = inf, h.I(inf);
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    Read(b[i]);
    if (b[i]) {
      h.I(-inf);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (b[a[i]]) {
      if (q[a[i]].size() == b[a[i]]) {
        h.O(q[a[i]].front()), q[a[i]].pop();
      } else if (q[a[i]].size() == b[a[i]] - 1) {
        h.O(-inf);
      }
      q[a[i]].push(i);
      if (q[a[i]].size() == b[a[i]]) {
        h.I(q[a[i]].front());
      }
    }
    if (h.T() != -inf) {
      if (h.T() == inf) {
        ans = 0;
      } else {
        CheckMin(ans, i - h.T() + 1);
      }
    }
  }
  if (ans == inf) {
    ans = -1;
  } else {
    for (int i = 1; i <= m; ++i) {
      ans -= b[i];
    }
  }
  printf("%d\n", ans);
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}