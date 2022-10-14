#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    k = min(n, k);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
    }
    int mex = 0;
    int ops = 0;
    for (int i = 0; ; i++) {
      if (cnt[i] == 0) {
        if (ops == k) {
          mex = i;
          break;
        }
        ops += 1;
      }
    }
    multiset<int> st;
    for (auto& c : cnt) {
      if (c.first > mex) {
        st.insert(c.second);
      }
    }
    int ans = 0;
    for (auto& p : st) {
      if (k >= p) {
        k -= p;
      } else {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}