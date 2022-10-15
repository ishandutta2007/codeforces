#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
int n, m, p, k, a[150001], tag[600001];
std::vector<std::pair<int, int>> t[600001];
std::vector<std::pair<int, int>> Merge(std::vector<std::pair<int, int>> a,
                                       std::vector<std::pair<int, int>> b) {
  for (auto &&x : b) {
    bool f = false;
    for (auto &&i : a) {
      if (i.first == x.first) {
        i.second += x.second;
        f = true;
        break;
      }
    }
    if (f) {
      continue;
    }
    a.emplace_back(x);
    if (static_cast<int>(a.size()) <= k) {
      continue;
    }
    int min = std::min_element(a.begin(), a.end(),
                               [](const std::pair<int, int> &x,
                                  const std::pair<int, int> &y) -> bool {
                                 return x.second < y.second;
                               })
                  ->second;
    std::vector<std::pair<int, int>> tmp;
    for (auto &&i : a) {
      if (i.second > min) {
        tmp.emplace_back(i.first, i.second - min);
      }
    }
    std::swap(a, tmp);
  }
  return a;
}
void Cover(int l, int r, int v, int x) {
  tag[x] = v;
  std::vector<std::pair<int, int>>().swap(t[x]);
  t[x].emplace_back(v, r - l + 1);
}
void Pushup(int x) { t[x] = Merge(t[x + x], t[x + x + 1]); }
void Pushdown(int l, int r, int x) {
  if (tag[x]) {
    int mid = (l + r) >> 1;
    Cover(l, mid, tag[x], x + x);
    Cover(mid + 1, r, tag[x], x + x + 1);
    tag[x] = 0;
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    t[x].emplace_back(a[l], 1);
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x);
  Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int L, int R, int l, int r, int v, int x) {
  if (L <= l && r <= R) {
    Cover(l, r, v, x);
    return;
  }
  Pushdown(l, r, x);
  int mid = (l + r) >> 1;
  if (L <= mid) {
    Modify(L, R, l, mid, v, x + x);
  }
  if (R > mid) {
    Modify(L, R, mid + 1, r, v, x + x + 1);
  }
  Pushup(x);
}
std::vector<std::pair<int, int>> Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) {
    return t[x];
  }
  Pushdown(l, r, x);
  std::vector<std::pair<int, int>> ans;
  int mid = (l + r) >> 1;
  if (L <= mid) {
    ans = Merge(ans, Query(L, R, l, mid, x + x));
  }
  if (R > mid) {
    ans = Merge(ans, Query(L, R, mid + 1, r, x + x + 1));
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> p;
  k = 100 / p;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  Build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    int op, l, r, x;
    std::cin >> op >> l >> r;
    if (op == 1) {
      std::cin >> x;
      Modify(l, r, 1, n, x, 1);
    } else {
      std::vector<std::pair<int, int>> ans = Query(l, r, 1, n, 1);
      std::cout << ans.size();
      for (auto &&i : ans) {
        std::cout << ' ' << i.first;
      }
      std::cout << '\n';
    }
  }
  return 0;
}