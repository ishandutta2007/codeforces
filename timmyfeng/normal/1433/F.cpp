#include <bits/stdc++.h>
using namespace std;

const int N = 70 + 1;

int row_sum[N][N][N];
int sum[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  vector<int> ans(t, INT_MIN / 2);
  ans[0] = 0;

  for (int i = 0; i < n; ++i) {
    vector<vector<int>> sum(m / 2 + 1, vector<int>(t, INT_MIN / 2));
    sum[0][0] = 0;

    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;

      vector<vector<int>> sum_new = sum;
      for (int k = 0; k < m / 2; ++k) {
        for (int l = 0; l < t; ++l) {
          sum_new[k + 1][(l + a) % t] = max(sum_new[k + 1][(l + a) % t], sum[k][l] + a);
        }
      }
      sum = sum_new;
    }

    vector<int> ans_new = ans;
    for (int j = 0; j <= m / 2; ++j) {
      for (int k = 0; k < t; ++k) {
        for (int l = 0; l < t; ++l) {
          ans_new[(k + l) % t] = max(ans_new[(k + l) % t], ans[k] + sum[j][l]);
        }
      }
    }
    ans = ans_new;
  }

  cout << ans[0] << "\n";
}