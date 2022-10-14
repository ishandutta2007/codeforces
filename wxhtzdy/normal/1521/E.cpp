#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m, k;
    cin >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
      cin >> a[i];
    }
    auto Can = [&](int n) {
      int tot = 0;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          tot += n;
        } else {
          tot += (n + 1) / 2;
        }
      }
      if (m > tot) {
        return false;
      }
      for (int i = 0; i < k; i++) {
        if (a[i] > n * ((n + 1) / 2)) {
          return false;
        }
      }
      return true;
    };
    int low = 1, high = sqrt(m) * 4, n = 0;
    while (low <= high) {
      int mid = low + high >> 1;
      if (Can(mid)) {
        n = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << n << "\n";
    vector<int> order(k);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] > a[j];
    });
    vector<vector<pair<int, int>>> v(4);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int id = (i % 2) * 2 + j % 2;
        v[id].emplace_back(i, j);
      }
    }
    vector<vector<int>> ans(n, vector<int>(n));
    vector<int> ptr(3);
    for (int x = 0; x < k; x++) {
      int i = order[x];
      for (int foo = 0; foo < a[i]; foo++) {
        for (int id : {2, 0, 1}) {
          if (ptr[id] == v[id].size()) continue;
          auto cell = v[id][ptr[id]];
          ans[cell.first][cell.second] = i + 1;
          ptr[id]++;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ans[i][j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}