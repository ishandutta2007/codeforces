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

    vector<long long> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    vector<long long> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
      if (prefix[i] == -1 || a[i] < prefix[i]) {
        prefix[i + 1] = -1;
      } else {
        prefix[i + 1] = a[i] - prefix[i];
      }
    }

    vector<long long> suffix(n);
    for (int i = n - 1; i > 0; --i) {
      if (suffix[i] == -1 || a[i] < suffix[i]) {
        suffix[i - 1] = -1;
      } else {
        suffix[i - 1] = a[i] - suffix[i];
      }
    }

    bool ok = (prefix[n] == 0);
    for (int i = 1; i < n; ++i) {
      ok |= (prefix[i - 1] >= 0 && suffix[i] >= 0 && a[i] - prefix[i - 1] == a[i - 1] - suffix[i] && a[i] >= prefix[i - 1]);
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}