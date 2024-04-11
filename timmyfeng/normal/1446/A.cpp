#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    long long w;
    cin >> n >> w;

    vector<int> ans;
    vector<int> item(n);
    for (int i = 0; i < n; ++i) {
      cin >> item[i];
      if (item[i] >= (w + 1) / 2 && item[i] <= w && ans.empty()) {
        ans.push_back(i);
      }
    }

    if (ans.empty()) {
      long long sum = 0;
      for (int i = 0; i < n && sum < (w + 1) / 2; ++i) {
        if (item[i] < (w + 1) / 2) {
          sum += item[i];
          ans.push_back(i);
        }
      }

      if (sum < (w + 1) / 2) {
        cout << -1 << "\n";
        continue;
      }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}