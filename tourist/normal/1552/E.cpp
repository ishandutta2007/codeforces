/**
 *    author:  tourist
 *    created: 25.07.2021 18:10:27       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> c(n * k);
  vector<vector<int>> at(n);
  for (int i = 0; i < n * k; i++) {
    cin >> c[i];
    --c[i];
    at[c[i]].push_back(i);
  }
  vector<int> L(n, -1);
  vector<int> R(n, -1);
  vector<int> take(k - 1, 0);
  for (int i = 0; i < n; i++) {
    take[i % (k - 1)] += 1;
  }
  vector<bool> used(n, false);
  for (int it = 0; it < k - 1; it++) {
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        all.emplace_back(at[i][it + 1], i);
      }
    }
    sort(all.begin(), all.end());
    for (int id = 0; id < take[it]; id++) {
      int i = all[id].second;
      L[i] = at[i][it];
      R[i] = at[i][it + 1];
      used[i] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << L[i] + 1 << " " << R[i] + 1 << '\n';
  }
  return 0;
}