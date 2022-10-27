/**
 *    author:  wxhtzdy
 *    created: 15.10.2022 16:40:39
**/
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    set<int> st;
    for (int i = 1; i <= n; i++) {
      st.insert(i);
    }
    vector<int> ans(n + 1, 1);
    for (int i = n; i > 1; i--) {
      if (a[i] > a[i - 1]) {
        continue;
      }
      int d = a[i - 1] - a[i];
      auto it = st.lower_bound(d);
      if (it != st.end()) {
        ans[*it] = i;
        st.erase(it);
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }                                                                    
  return 0;
}