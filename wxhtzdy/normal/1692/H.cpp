/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 16:47:04
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
    vector<int> a(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]].push_back(i);
    }
    tuple<int, int, int, int> ans;
    get<0>(ans) = 1;
    get<1>(ans) = a[0];
    get<2>(ans) = 1;
    get<3>(ans) = 1;     
    for (auto &p : pos) {
      vector<int> b = p.second;
      int mn = 0;
      int pos = 0;
      for (int j = 0; j < (int) b.size(); j++) {
        int bal = j + (j - b[j]);
        if (bal <= mn) {
          mn = bal - 1;
          pos = b[j];
        }
        if (bal - mn > get<0>(ans)) {
          get<0>(ans) = bal - mn;
          get<1>(ans) = p.first;
          get<2>(ans) = pos + 1;
          get<3>(ans) = b[j] + 1;  
        }
      }
    }
    cout << get<1>(ans) << " " << get<2>(ans) << " " << get<3>(ans) << '\n';
  }                                                                    
  return 0;
}