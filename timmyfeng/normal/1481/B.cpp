#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, k;
  cin >> n >> k;
  --k;

  vector<int> h(n);
  for (auto &i : h) {
    cin >> i;
  }

  vector<array<int, 2>> slope;
  for (int i = 0; i < n; ++i) {
    while (!slope.empty() && slope.back()[0] < h[i]) {
      auto [a, b] = slope.back();
      slope.pop_back();

      int c = h[i];
      if (!slope.empty()) {
        c = min(c, slope.back()[0]);
      }

      if (k < b * (c - a)) {
        cout << i - (k % b) << "\n";
        return;
      }

      k -= b * (c - a);
      if (!slope.empty() && slope.back()[0] == a) {
        slope.back()[1] += b;
      } else {
        slope.push_back({c, b});
      }
    }

    if (!slope.empty() && slope.back()[0] == h[i]) {
      ++slope.back()[1];
    } else {
      slope.push_back({h[i], 1});
    }
  }

  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}