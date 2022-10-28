#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int K = 4;

int a[K][N], cost[K][N];
vector<int> yuck[K][N];
int n[K], m[K];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto &i : n) {
    cin >> i;
  }

  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      cin >> a[i][j];
    }
  }

  multiset<int> prv;
  for (int j = 0; j < n[0]; ++j) {
    cost[0][j] = a[0][j];
    prv.insert(cost[0][j]);
  }

  for (int i = 1; i < K; ++i) {
    cin >> m[i];
    for (int j = 0; j < m[i]; ++j) {
      int u, v;
      cin >> u >> v;
      yuck[i][--v].push_back(--u);
    }

    for (int j = 0; j < n[i]; ++j) {
      for (auto k : yuck[i][j]) {
        if (cost[i - 1][k] < INT_MAX) {
          prv.erase(prv.find(cost[i - 1][k]));
        }
      }

      if (prv.empty()) {
        cost[i][j] = INT_MAX;
      } else {
        cost[i][j] = a[i][j] + *prv.begin();
      }

      for (auto k : yuck[i][j]) {
        if (cost[i - 1][k] < INT_MAX) {
          prv.insert(cost[i - 1][k]);
        }
      }
    }

    prv.clear();
    for (int j = 0; j < n[i]; ++j) {
      if (cost[i][j] < INT_MAX) {
        prv.insert(cost[i][j]);
      }
    }
  }

  cout << (prv.empty() ? -1 : *prv.begin()) << "\n";
}