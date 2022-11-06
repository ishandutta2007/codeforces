#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

struct UnionFind {
  vector<int> set;
  vector<bool> single;

  UnionFind(int n) {
    set.assign(n, -1);
    single.assign(n, false);
  }

  void unite(int a, int b) {
    int rtA = root(a);
    int rtB = root(b);
    if (rtA == rtB) {
      return;
    }
    set[rtA] += set[rtB];
    set[rtB] = rtA;
    single[rtA] = single[rtA] || single[rtB];
  }

  bool find(int a, int b) {
    return root(a) == root(b);
  }

  int root(int a) {
    if (set[a] < 0) {
      return a;
    } else {
      set[a] = root(set[a]);
      return set[a];
    }
  }

  int size(int a) {
    return -set[root(a)];
  }

  bool is_single(int a) {
    return single[root(a)];
  }

  void set_single(int a) {
    single[root(a)] = true;
  }
};

int64_t MOD = 1000000007;
int INF = 1 << 28;
int n, m;
int k[500001];
int x1[500001];
int x2[500001];
vector<vector<int>> d2n_2;
vector<vector<int>> d2n_1;

void solve() {
  scanf("%d %d", &n, &m);
  d2n_2.resize(m + 1);
  d2n_1.resize(m + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &k[i], &x1[i]);
    if (k[i] == 2) {
      scanf("%d", &x2[i]);
      d2n_2[x1[i]].push_back(i);
      d2n_2[x2[i]].push_back(i);
    } else {
      d2n_1[x1[i]].push_back(i);
    }
  }
  vector<bool> visited_d(m + 1);
  vector<bool> visited_v(n + 1);
  int64_t ans = 1;
  vector<int> ans_v;
  UnionFind uf(m + 1);
  for (int i = 1; i <= m; ++i) {
    if (visited_d[i]) continue;
    if (d2n_2[i].empty()) {
      if (!d2n_1[i].empty()) {
        ans = ans * 2 % MOD;
        ans_v.push_back(d2n_1[i][0]);
      }
      continue;
    }
    vector<int> dims = {i};
    vector<int> vecs_1;
    vector<int> vecs_2;
    visited_d[i] = true;
    for (int qi = 0; qi < dims.size(); ++qi) {
      int d = dims[qi];
      for (int vi : d2n_2[d]) {
        if (visited_v[vi]) continue;
        vecs_2.push_back(vi);
        visited_v[vi] = true;
        int nd = x1[vi] == d ? x2[vi] : x1[vi];
        if (visited_d[nd]) continue;
        visited_d[nd] = true;
        dims.push_back(nd);
      }
    }
    for (int di : dims) {
      if (!d2n_1[di].empty()) {
        vecs_1.push_back(d2n_1[di][0]);
        vecs_2.push_back(d2n_1[di][0]);
      }
    }
    for (int j = 0; j < dims.size() - 1; ++j) {
      ans = ans * 2 % MOD;
    }
    if (!vecs_1.empty()) {
      ans = ans * 2 % MOD;
    }
    sort(vecs_2.begin(), vecs_2.end());
    for (int vi : vecs_2) {
      if (k[vi] == 1) {
        if (!uf.is_single(x1[vi])) {
          uf.set_single(x1[vi]);
          ans_v.push_back(vi);
        }
      } else {
        if (!uf.find(x1[vi], x2[vi]) && (!uf.is_single(x1[vi]) || !uf.is_single(x2[vi]))) {
          uf.unite(x1[vi], x2[vi]);
          ans_v.push_back(vi);
        }
      }
    }
  }
  sort(ans_v.begin(), ans_v.end());
  cout << ans << " " << ans_v.size() << endl;
  // printf("%d %lu\n", ans, ans_v.size());
  for (int i = 0; i < ans_v.size(); ++i) {
    printf("%d", ans_v[i] + 1);
    printf(i == ans_v.size() - 1 ? "\n" : " ");
  }
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    solve();
  }
}