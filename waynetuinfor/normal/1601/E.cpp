#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q, K;
  cin >> N >> Q >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<vector<int>> sp(1, A);
  for (int i = 1; (1 << i) <= N; ++i) {
    sp.emplace_back(N);
    for (int j = 0; j + (1 << i) <= N; ++j) {
      sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
    }
  }

  auto QuerySP = [&](int l, int r) {
    int p = 31 - __builtin_clz(r - l + 1);
    return min(sp[p][l], sp[p][r - (1 << p) + 1]);
  };

  vector<int> best(N);
  for (int i = K - 1; i < N; ++i) {
    best[i] = QuerySP(i - K + 1, i);
  }

  vector<int> l(Q), r(Q);
  vector<vector<int>> query(K);
  for (int i = 0; i < Q; ++i) {
    cin >> l[i] >> r[i];
    l[i]--;
    query[l[i] % K].push_back(i);
  }
  vector<vector<int>> block(K);
  for (int i = 0; i < N; ++i) {
    block[i % K].push_back(i);
  }
  vector<int64_t> tree(N * 4);
  vector<int64_t> tag(N * 4);

  auto Update = [&](int ql, int qr, int v) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (l >= qr || ql >= r) return;
      if (l >= ql && r <= qr) {
        tree[o] += 1LL * v * (r - l);
        tag[o] += v;
        return;
      }
      int m = (l + r) >> 1;
      tree[o * 2 + 1] += (m - l) * tag[o];
      tag[o * 2 + 1] += tag[o];
      tree[o * 2 + 2] += (r - m) * tag[o];
      tag[o * 2 + 2] += tag[o];
      tag[o] = 0;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
      tree[o] = tree[o * 2 + 1] + tree[o * 2 + 2];
    };

    return dfs(dfs, 0, N);
  };

  auto Query = [&](int ql, int qr) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> int64_t {
      if (l >= qr || ql >= r) {
        return 0;
      }
      if (l >= ql && r <= qr) {
        return tree[o];
      }
      int m = (l + r) >> 1;
      tree[o * 2 + 1] += (m - l) * tag[o];
      tag[o * 2 + 1] += tag[o];
      tree[o * 2 + 2] += (r - m) * tag[o];
      tag[o * 2 + 2] += tag[o];
      tag[o] = 0;
      return dfs(dfs, l, m, o * 2 + 1) + dfs(dfs, m, r, o * 2 + 2);
    };

    return dfs(dfs, 0, N);
  };

  vector<int64_t> ans(Q);

  for (int k = 0; k < K; ++k) {
    if (query[k].empty()) continue;
    sort(query[k].begin(), query[k].end(), [&](int i, int j) {
      return l[i] > l[j];
    });
    vector<tuple<int, int, int>> stk;
    int R = block[k].size();
    // cout << "remainder = " << k << endl;
    for (int i = 0, j = block[k].size() - 1; i < query[k].size(); ++i) {
      while (j >= 0 && block[k][j] - K >= l[query[k][i]]) {
        while (!stk.empty() && get<0>(stk.back()) >= best[block[k][j]]) {
          Update(get<1>(stk.back()), get<2>(stk.back()), -get<0>(stk.back()));
          stk.pop_back();
        }
        int t = -1;
        if (stk.empty()) {
          t = R;
        } else {
          t = get<1>(stk.back());
        }
        Update(j, t, best[block[k][j]]);
        stk.emplace_back(best[block[k][j]], j, t);
        j--;
      }
      // cout << "ID = " << query[k][i] << endl;
      // for (auto [v, l, r] : stk) {
      //   cout << "(" << v << " " << l << " " << r << ")" << endl;
      // }
      int v = A[l[query[k][i]]];
      int lb = lower_bound(block[k].begin(), block[k].end(), l[query[k][i]]) - block[k].begin();
      int rb = lower_bound(block[k].begin(), block[k].end(), r[query[k][i]]) - block[k].begin();
      // cout << "lb = " << lb << " rb = " << rb << endl;
      int q = stk.size();
      for (int d = 20; d >= 0; --d) {
        if (q - (1 << d) >= 0 && get<0>(stk[q - (1 << d)]) >= v) {
          q -= (1 << d);
        }
      }
      if (q < stk.size()) {
        ans[query[k][i]] += 1LL * v * (min(rb, get<2>(stk[q])) - lb - 1);
        if (get<2>(stk[q]) < rb) {
          ans[query[k][i]] += Query(get<2>(stk[q]), rb);
        }
      } else {
        ans[query[k][i]] += Query(lb, rb);
      }
      ans[query[k][i]] += v;
    }
    for (auto [v, l, r] : stk) {
      Update(l, r, -v);
    }
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}