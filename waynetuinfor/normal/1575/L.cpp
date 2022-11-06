#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> ds(N);
  for (int i = 0; i < N; ++i) {
    ds[i] = i - A[i];
  }
  sort(ds.begin(), ds.end());
  ds.resize(unique(ds.begin(), ds.end()) - ds.begin());

  vector<int> order(N);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return A[i] < A[j];
  });

  vector<int> fw(ds.size() + 1, -1);

  auto Update = [&](int p, int v) {
    for (int i = p + 1; i < fw.size(); i += i & -i) {
      fw[i] = max(fw[i], v);
    }
  };

  auto Query = [&](int p) {
    int res = -1;
    for (int i = p + 1; i > 0; i -= i & -i) {
      res = max(res, fw[i]);
    }
    return res;
  };

  vector<int> dp(N, -1);
  for (int i = 0, j = 0; i < N; ++i) {
    while (j < N && A[order[j]] < A[order[i]]) {
      int p = lower_bound(ds.begin(), ds.end(), order[j] - A[order[j]]) - ds.begin();
      Update(p, dp[order[j]]);
      j++;
    }
    int p = lower_bound(ds.begin(), ds.end(), order[i] - A[order[i]]) - ds.begin();
    int x = Query(p);
    if (x != -1) {
      dp[order[i]] = x + 1;
    }
    if (order[i] >= A[order[i]] - 1) {
      dp[order[i]] = max(dp[order[i]], 1);
    }
  }
  cout << max(*max_element(dp.begin(), dp.end()), 0) << "\n";
}