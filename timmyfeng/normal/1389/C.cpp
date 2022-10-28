#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> cnt(10);
    for (char c : s) {
      ++cnt[c - '0'];
    }

    int ans = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (i == j)
          continue;
        int pre_i = 0;
        int pre_j = 0;
        for (int k = 0; k < n; ++k) {
          if (s[k] - '0' == i) {
            pre_i = max(pre_i, pre_j + 1);
          } else if (s[k] - '0' == j && pre_i > 0) {
            pre_j = max(pre_j, pre_i + 1);
          }
        }
        ans = max(ans, pre_j);
      }
    }

    cout << n - ans << "\n";
  }
}