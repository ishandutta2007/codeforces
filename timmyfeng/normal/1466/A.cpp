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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    set<int> areas;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        areas.insert(abs(a[j] - a[i]));
      }
    }

    cout << areas.size() << "\n";
  }
}