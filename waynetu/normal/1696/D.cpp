#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
      a[i]--;
    }
    vector<int> next_larger(N), prev_larger(N);
    for (int i = 0; i < N; ++i) {
      next_larger[i] = i + 1;
      prev_larger[i] = i - 1;
    }
    for (int i = 0; i < N; ++i) {
      while (prev_larger[i] >= 0 && a[i] > a[prev_larger[i]]) {
        prev_larger[i] = prev_larger[prev_larger[i]];
      }
    }
    for (int i = N - 1; i >= 0; --i) {
      while (next_larger[i] < N && a[i] > a[next_larger[i]]) {
        next_larger[i] = next_larger[next_larger[i]];
      }
    }
    vector<int> next_smaller(N), prev_smaller(N);
    for (int i = 0; i < N; ++i) {
      next_smaller[i] = i + 1;
      prev_smaller[i] = i - 1;
    }
    for (int i = 0; i < N; ++i) {
      while (prev_smaller[i] >= 0 && a[i] < a[prev_smaller[i]]) {
        prev_smaller[i] = prev_smaller[prev_smaller[i]];
      }
    }
    for (int i = N - 1; i >= 0; --i) {
      while (next_smaller[i] < N && a[i] < a[next_smaller[i]]) {
        next_smaller[i] = next_smaller[next_smaller[i]];
      }
    }
    vector<int> dist(N, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    vector<vector<pair<int, int>>> fw1(N + 1);
    vector<vector<pair<int, int>>> fw2(N + 1);

    auto Insert = [&](auto& fw, int p, int x, int y) {
      for (int i = p + 1; i <= N; i += i & -i) {
        fw[i].emplace_back(x, y);
      }
    };

    vector<int> order(N - 1);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(),
         [&](int i, int j) { return prev_larger[i] > prev_larger[j]; });
    for (int u : order) {
      Insert(fw1, u, prev_larger[u], u);
    }
    sort(order.begin(), order.end(),
         [&](int i, int j) { return prev_smaller[i] > prev_smaller[j]; });
    for (int u : order) {
      Insert(fw2, u, prev_smaller[u], u);
    };

    auto QueryMin = [&](auto& fw, int p) {
      pair<int, int> res{N, -1};
      for (int i = p + 1; i > 0; i -= i & -i) {
        while (!fw[i].empty() && dist[fw[i].back().second] != -1) {
          fw[i].pop_back();
        }
        if (!fw[i].empty()) {
          res = min(res, fw[i].back());
        }
      }
      return res;
    };

    // cout << "next_smaller = ";
    // for (int i = 0; i < N; ++i) {
    //   cout << next_smaller[i] << " ";
    // }
    // cout << endl;
    // cout << "next_larger = ";
    // for (int i = 0; i < N; ++i) {
    //   cout << next_larger[i] << " ";
    // }
    // cout << endl;
    // cout << "prev_smaller = ";
    // for (int i = 0; i < N; ++i) {
    //   cout << prev_smaller[i] << " ";
    // }
    // cout << endl;
    // cout << "prev_larger = ";
    // for (int i = 0; i < N; ++i) {
    //   cout << next_larger[i] << " ";
    // }
    // cout << endl;

    while (!que.empty()) {
      int x = que.front();
      que.pop();
      // cout << "x = " << x << " dist = " << dist[x] << endl;
      while (true) {
        auto [p, j] = QueryMin(fw1, next_smaller[x] - 1);
        // cerr << "p = " << p << " j = " << j << endl;
        if (p < x) {
          assert(dist[j] == -1);
          dist[j] = dist[x] + 1;
          que.push(j);
        } else {
          break;
        }
      }
      while (true) {
        auto [p, j] = QueryMin(fw2, next_larger[x] - 1);
        // cerr << "p = " << p << " j = " << j << endl;
        if (p < x) {
          assert(dist[j] == -1);
          dist[j] = dist[x] + 1;
          que.push(j);
        } else {
          break;
        }
      }
    }
    cout << dist[N - 1] << "\n";
  }
}