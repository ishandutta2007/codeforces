#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<int, vector<int>> freq;
    for (int i = 1; i <= n; ++i) {
      int a;
      cin >> a;
      freq[a].push_back(i);
    }

    int ans = -1;
    for (auto &[a, b] : freq) {
      if (b.size() == 1) {
        ans = b[0];
        break;
      }
    }

    cout << ans << "\n";
  }
}