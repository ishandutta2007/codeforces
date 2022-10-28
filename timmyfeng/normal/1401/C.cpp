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
    for (auto& i : a) {
      cin >> i;
    }

    int mn = *min_element(a.begin(), a.end());
    vector<int> b;
    for (auto i : a) {
      if (i % mn == 0) {
        b.push_back(i);
      }
    }
    sort(b.begin(), b.end());

    int ptr = 0;
    for (auto& i : a) {
      if (i % mn == 0) {
        i = b[ptr];
        ++ptr;
      }
    }

    bool ok = true;
    for (int i = 1; i < n; ++i) {
      ok &= (a[i] >= a[i - 1]);
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
}