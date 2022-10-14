#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        ans.push_back(a[i]);
      } else {
        while (!ans.empty() && ans.back() != a[i] - 1) {
          ans.pop_back();
        }
        ans[ans.size() - 1] = a[i];
      }
      for (int j = 0; j < ans.size(); j++) {
        cout << ans[j];
        if (j < ans.size() - 1) {
          cout << '.';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}