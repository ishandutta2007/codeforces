#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for (auto& i : x) {
      cin >> i;
    }
    sort(x.begin(), x.end());

    for (int i = 0; i < n; ++i) {
      int y;
      cin >> y;
    }

    int ans = 0;
    int ptr1 = 0;
    int ptr2 = 0;
    vector<array<int, 2>> points;
    for (int i = 0; i < n; ++i) {
      while (ptr1 < n && x[ptr1] - x[i] <= k) {
        ++ptr1;
      }
      while (ptr2 < n && x[ptr2] - x[i] <= 2 * k) {
        ++ptr2;
      }
      ans = max(ans, ptr2 - i);
      points.push_back({i, ptr1 - i});
      points.push_back({ptr1, i - ptr1});
    }

    sort(points.begin(), points.end());
    
    int mx = 0;
    for (auto [x, val] : points) {
      if (val > 0) {
        ans = max(ans, val + mx);
      } else {
        mx = max(mx, -val);
      }
    }

    cout << ans << "\n";
  }
}