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

    vector<int> a(2 * n);
    for (auto &i : a) {
      cin >> i;
    }
    sort(a.rbegin(), a.rend());

    bool ok = false;
    for (int i = 1; i < 2 * n; ++i) {
      int x = a[0] + a[i];

      multiset<int> numbers(a.begin(), a.end());
      vector<array<int, 2>> ans;
      while (!numbers.empty()) {
        int u = *(--numbers.end());
        numbers.erase(--numbers.end());
        if (numbers.find(x - u) == numbers.end()) {
          break;
        }
        numbers.erase(numbers.find(x - u));
        ans.push_back({u, x - u});
        x = u;
      }

      if (numbers.empty()) {
        ok = true;
        cout << "YES\n";
        cout << a[0] + a[i] << "\n";
        for (auto [u, v] : ans) {
          cout << u << " " << v << "\n";
        }
        break;
      }
    }

    if (!ok) {
      cout << "NO\n";
    }
  }
}