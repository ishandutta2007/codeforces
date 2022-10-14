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
    map<int, vector<int>> ids;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == -1) {
        a[i] = i + 1;
      } else {
        a[i]--;
      }
      ids[a[i]].push_back(i);
    }
    vector<int> ans(n, -1);
    int m = n;
    function<void(int)> Dfs = [&](int i) {
      if (i != n) {
        ans[i] = m--;
      }
      for (int j : ids[i]) {
        Dfs(j);
      }
    };
    Dfs(n);
    vector<int> stk;
    vector<int> nans(n);
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && ans[stk.back()] <= ans[i]) {
        stk.pop_back();
      }
      nans[i] = (stk.empty() ? n : stk.back());
      stk.push_back(i);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != -1 && a[i] != nans[i]) {
        ok = false;
      }
    }
    if (!ok || *min_element(ans.begin(), ans.end()) == -1) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}