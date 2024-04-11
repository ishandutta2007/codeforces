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
    set<int> values;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      values.insert(a[i]);
    }

    bool ok = false;
    while (!values.empty()) {
      int x = *values.begin();
      values.erase(values.begin());
      ok |= (count(a.begin(), a.end(), x) > 1);
      for (int i = a.size() - 1; i > 0; --i) {
        if (a[i] == a[i - 1] && a[i] == x) {
          a.erase(a.begin() + i);
          values.insert(++a[i - 1]);
        }
      }
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}