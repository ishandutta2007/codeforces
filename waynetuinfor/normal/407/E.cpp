#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, k, d;
  cin >> N >> k >> d;
  vector<int64_t> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  if (d == 0) {
    pair<int, int> ans = {0, -1};
    for (int i = 0, j = 0; i < N; i = j) {
      while (j < N && a[i] == a[j]) j++;
      pair<int, int> res = {i, j - 1};
      if (res.second - res.first > ans.second - ans.first ||
          res.second - res.first == ans.second - ans.first &&
              res.first < ans.first) {
        ans = res;
      }
    }
    cout << ans.first + 1 << " " << ans.second + 1 << "\n";
    return 0;
  }

  int t = *min_element(a.begin(), a.end());
  if (t < 0) {
    int64_t add = (-t + d - 1) / d * d;
    for (int i = 0; i < N; ++i) {
      a[i] += add;
    }
  }

  auto Solve = [&](vector<int64_t> vec) {
    int M = vec.size();
    vector<int64_t> tree(M * 4);
    vector<int64_t> tag(M * 4);
    // max - min <= k + j - i
    // k + right - left - max + min >= 0

    auto Build = [&]() {
      auto dfs = [&](auto dfs, int l, int r, int o = 0) {
        if (r - l == 1) {
          tree[o] = -l + k;
          return;
        }
        int m = (l + r) >> 1;
        dfs(dfs, l, m, o * 2 + 1);
        dfs(dfs, m, r, o * 2 + 2);
        tree[o] = max(tree[o * 2 + 1], tree[o * 2 + 2]);
      };
      return dfs(dfs, 0, M);
    };

    Build();

    auto Push = [&](int o) {
      for (int k = 1; k <= 2; ++k) {
        tree[o * 2 + k] += tag[o];
        tag[o * 2 + k] += tag[o];
      }
      tag[o] = 0;
    };

    auto Update = [&](int ql, int qr, int64_t v) {
      auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
        if (l >= qr || ql >= r) {
          return;
        }
        if (l >= ql && r <= qr) {
          tree[o] += v;
          tag[o] += v;
          return;
        }
        Push(o);
        int m = (l + r) >> 1;
        dfs(dfs, l, m, o * 2 + 1);
        dfs(dfs, m, r, o * 2 + 2);
        tree[o] = max(tree[o * 2 + 1], tree[o * 2 + 2]);
      };
      return dfs(dfs, 0, M);
    };

    auto QueryFirst = [&](int ql, int qr) {
      auto dfs = [&](auto dfs, int l, int r, int o = 0) -> int {
        if (l >= ql && r <= qr) {
          if (tree[o] < 0) {
            return -1;
          }
          if (r - l == 1) {
            return l;
          }
          Push(o);
          int m = (l + r) >> 1;
          if (tree[o * 2 + 1] >= 0) {
            return dfs(dfs, l, m, o * 2 + 1);
          } else {
            return dfs(dfs, m, r, o * 2 + 2);
          }
        }
        Push(o);
        int m = (l + r) >> 1;
        if (qr <= m) {
          return dfs(dfs, l, m, o * 2 + 1);
        } else if (ql >= m) {
          return dfs(dfs, m, r, o * 2 + 2);
        } else {
          int t = dfs(dfs, l, m, o * 2 + 1);
          if (t != -1) {
            return t;
          }
          return dfs(dfs, m, r, o * 2 + 2);
        }
      };
      return dfs(dfs, 0, M);
    };

    vector<int> max_stack = {-1}, min_stack = {-1};
    map<int64_t, int> prv;
    int left = 0;
    pair<int, int> res = {0, -1};

    for (int i = 0; i < vec.size(); ++i) {
      while (max_stack.size() > 1 && vec[i] >= vec[max_stack.back()]) {
        Update(max_stack[max_stack.size() - 2] + 1, max_stack.back() + 1,
               vec[max_stack.back()]);
        max_stack.pop_back();
      }
      max_stack.push_back(i);
      Update(max_stack[max_stack.size() - 2] + 1, max_stack.back() + 1,
             -vec[max_stack.back()]);
      while (min_stack.size() > 1 && vec[i] <= vec[min_stack.back()]) {
        Update(min_stack[min_stack.size() - 2] + 1, min_stack.back() + 1,
               -vec[min_stack.back()]);
        min_stack.pop_back();
      }
      min_stack.push_back(i);
      Update(min_stack[min_stack.size() - 2] + 1, min_stack.back() + 1,
             vec[min_stack.back()]);
      if (prv.find(vec[i]) != prv.end()) {
        left = max(left, prv[vec[i]] + 1);
      }
      prv[vec[i]] = i;
      Update(0, i + 1, i);
      int t = QueryFirst(left, i + 1);
      Update(0, i + 1, -i);
      if (t != -1) {
        pair<int, int> cur = {t, i};
        if (cur.second - cur.first > res.second - res.first ||
            cur.second - cur.first == res.second - res.first &&
                cur.first < res.first) {
          res = cur;
        }
      }
    }
    return res;
  };

  pair<int, int> ans = {0, -1};
  for (int i = 0, j = 0; i < N; i = j) {
    vector<int64_t> vec;
    while (j < N && a[i] % d == a[j] % d) {
      vec.push_back(a[j++] / d);
    }
    auto res = Solve(vec);
    res.first += i;
    res.second += i;
    if (res.second - res.first > ans.second - ans.first ||
        res.second - res.first == ans.second - ans.first &&
            res.first < ans.first) {
      ans = res;
    }
  }
  cout << ans.first + 1 << " " << ans.second + 1 << "\n";
  return 0;
}