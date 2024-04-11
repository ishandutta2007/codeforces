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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int k = 1; k <= n + 1; k++) {
      multiset<int> st(a.begin(), a.end());
      bool fail = false;
      for (int i = 1; i <= k; i++) {
        auto it = st.lower_bound(k - i + 2);
        if (it == st.begin()) {
          fail = true;
          break;
        }
        st.erase(prev(it));
        if (!st.empty()) {
          st.erase(st.begin());
        }
      }
      if (fail) {
        cout << k - 1 << '\n';
        break;
      }
    }
  }
  return 0;
}