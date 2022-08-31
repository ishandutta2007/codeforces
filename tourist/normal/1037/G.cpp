/**
 *    author:  tourist
 *    created: 02.09.2018 19:09:40       
**/
#include <bits/stdc++.h>

using namespace std;

const int ALPHA = 26;
const int MAX_G = 32;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string foo;
  cin >> foo;
  int n = (int) foo.size();
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    s[i] = (int) (foo[i] - 'a');
  }
  vector<vector<int>> nxt(n + 1, vector<int>(ALPHA));
  for (int c = 0; c < ALPHA; c++) {
    nxt[n][c] = n;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int c = 0; c < ALPHA; c++) {
      nxt[i][c] = nxt[i + 1][c];
    }
    nxt[i][s[i]] = i;
  }
  vector<vector<int>> prv(n + 1, vector<int>(ALPHA));
  for (int c = 0; c < ALPHA; c++) {
    prv[0][c] = -1;
  }
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < ALPHA; c++) {
      prv[i + 1][c] = prv[i][c];
    }
    prv[i + 1][s[i]] = i;
  }
  int m;
  cin >> m;
  vector<int> from(m), to(m);
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i];
    from[i]--; to[i]--;
  }
  vector<vector<int>> add(n);
  for (int i = 0; i < m; i++) {
    add[from[i]].push_back(to[i]);
    for (int c = 0; c < ALPHA; c++) {
      int j = prv[to[i] + 1][c];
      if (j < to[i] && j >= from[i]) {
        add[j + 1].push_back(to[i]);
      }
    }
  }
  vector<vector<int>> rs(n);
  vector<vector<int>> dp(n);
  auto get_dp = [&](int i, int j) {
    if (i > j) {
      return 0;
    }
    auto it = lower_bound(rs[i].begin(), rs[i].end(), j);
    assert(!(it == rs[i].end() || *it != j));
    int pos = (int) (it - rs[i].begin());
    return dp[i][pos];
  };
  vector<vector<int>> get_dp_to(n + 1, vector<int>(ALPHA));
  vector<vector<int>> get_dp_from(n + 1, vector<int>(ALPHA));
  vector<int> xorval(n + 1, 0);
  vector<int> touched(MAX_G, 0);
  int iter = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1) {
      int j = nxt[i + 1][s[i]];
      xorval[i] = xorval[j] ^ get_dp(i + 1, j - 1);
    }
    for (int c = 0; c < ALPHA; c++) {
      if (nxt[i][c] != n && nxt[i][c] != i) {
        rs[i].push_back(nxt[i][c] - 1);
      }
    }
    rs[i].push_back(n - 1);
    for (int j : add[i]) {
      rs[i].push_back(j);
    }
    sort(rs[i].begin(), rs[i].end());
    rs[i].resize(unique(rs[i].begin(), rs[i].end()) - rs[i].begin());
    dp[i].resize(rs[i].size());
    for (int jt = 0; jt < (int) rs[i].size(); jt++) {
      int j = rs[i][jt];
      iter++;
      for (int c = 0; c < ALPHA; c++) {
        if (nxt[i][c] > j) {
          continue;
        }
        int A = nxt[i][c];
        int B = prv[j + 1][c];
        int cur = 0;
        if (A > i) {
          cur ^= get_dp_to[i][c];
        }
        if (B < j) {
          cur ^= get_dp_from[j][c];
        }
        cur ^= xorval[A] ^ xorval[B];
        touched[cur] = iter;
      }
      int &res = dp[i][jt];
      res = 0;
      while (touched[res] == iter) {
        res++;
      }
      if (j < n - 1) {
        if (nxt[i][s[j + 1]] == j + 1) {
          get_dp_to[i][s[j + 1]] = res;
        }
      }
      if (i > 0) {
        if (prv[j + 1][s[i - 1]] == i - 1) {
          get_dp_from[j][s[i - 1]] = res;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int x = get_dp(from[i], to[i]);
    cout << (x > 0 ? "Alice" : "Bob") << '\n';
  }
  return 0;
}