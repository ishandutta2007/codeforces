#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;

    vector<int> ans;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1]) {
        ans.push_back(i);
      }
    }

    if ((a[0] ^ (int(ans.size()) & 1)) != b[n - 1]) {
      ans.push_back(n);
    }

    for (int i = n - 1; i > 0; --i) {
      if (b[i] != b[i - 1]) {
        ans.push_back(i);
      }
    }

    cout << ans.size();
    for (int i : ans) {
      cout << " " << i;
    }
    cout << "\n";
  }
}