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

    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    int max_a = max_element(a.begin(), a.end()) - a.begin();
    int min_a = min_element(a.begin(), a.end()) - a.begin();

    if (a[max_a] == a[min_a]) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";

    cout << max_a + 1 << " " << min_a + 1 << "\n";
    for (int i = 0; i < n; ++i) {
      if (i != max_a && i != min_a) {
        if (a[i] == a[max_a]) {
          cout << i + 1 << " " << min_a + 1 << "\n";
        } else {
          cout << i + 1 << " " << max_a + 1 << "\n";
        }
      }
    }
  }
}