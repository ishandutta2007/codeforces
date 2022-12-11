#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

const int N = (int)1e5 + 10;
int a[N], b[N];
long long delta[N];

const long long INF = 1e18;

struct SegmentTree {
  long long min_value[4 * N];
  long long max_value[4 * N];
  
  SegmentTree() {
    for (int i = 0; i < 4 * N; i++) {
      min_value[i] = max_value[i] = 0;
    }
  }

  void set(int pos, long long value) {
    set(1, 0, N, pos, value);
  }
  void set(int v, int l, int r, int pos, long long value) {
    if (l == r) {
      min_value[v] = max_value[v] = value;
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
      set(2 * v, l, mid, pos, value);
    } else {
      set(2 * v + 1, mid + 1, r, pos, value);
    }
    min_value[v] = min(min_value[2 * v], min_value[2 * v + 1]);
    max_value[v] = max(max_value[2 * v], max_value[2 * v + 1]);
  }
  long long get_min(int l, int r) {
    return get_min_max(1, 0, N, l, r).first;
  }
  long long get_max(int l, int r) {
    return get_min_max(1, 0, N, l, r).second;
  }
  pair<long long, long long> get_min_max(int v, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return make_pair(min_value[v], max_value[v]);
    }
    if (r < a || b < l) {
      return make_pair(INF, -INF);
    }
    int mid = (l + r) / 2;
    auto t1 = get_min_max(2 * v, l, mid, a, b);
    auto t2 = get_min_max(2 * v + 1, mid + 1, r, a, b);
    return make_pair(min(t1.first, t2.first), max(t1.second, t2.second));
  }
} tree;

long long get_sum(int l, int r) {
  return delta[r] - (l == 0 ? 0 : delta[l - 1]);
}

long long get_min(int l, int r) {
  return tree.get_min(l, r) - (l == 0 ? 0 : delta[l - 1]);
}

long long get_max(int l, int r) {
  return tree.get_max(l, r) - (l == 0 ? 0 : delta[l - 1]);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif

  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    delta[i] = b[i] - a[i];
  }
  for (int i = 1; i < n; i++) {
    delta[i] += delta[i - 1];
  }
  for (int i = 0; i < n; i++) {
    tree.set(i, delta[i]);
  }
  for (int i = 0; i < n; i++) {
    eprintf("%lld ", delta[i]);
  }
  eprintf("\n");
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    auto sum = get_sum(l, r);
    auto min_value = get_min(l, r);
    auto max_value = get_max(l, r);
    eprintf("%d %d\n", l, r);
    eprintf("%lld %lld %lld\n", sum, min_value, max_value);
    if (sum != 0 || min_value < 0) {
      puts("-1");
    } else {
      printf("%lld\n", max_value);
    }
  }
  return 0;
}