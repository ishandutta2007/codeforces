#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> ans;
  for (int i = 1; i <= k + 1; ++i) {
    int cur = i + k + 1;
    vector<int> path = {i};
    while (cur + k <= n) {
      path.push_back(cur + k);
      cur = cur + 2 * k + 1;
    }

    if (cur > n) {
      if (ans.empty() || path.size() < ans.size()) {
        ans = path;
      }
    }
  }

  cout << ans.size() << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}