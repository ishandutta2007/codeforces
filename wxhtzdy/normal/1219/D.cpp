/**
 *    author:  wxhtzdy
 *    created: 21.09.2022 15:22:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int a;
  cin >> a;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  multiset<int> st;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    st.insert(c[i]);
    while (k < x[i] && !st.empty()) {
      k += a;
      ans += *st.begin();
      st.erase(st.begin());
    }              
    if (k < x[i]) {
      cout << -1 << '\n';
      return 0;
    }      
  }
  cout << ans << '\n';                                      
  return 0;
}