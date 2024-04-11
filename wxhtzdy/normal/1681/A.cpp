/**
 *    author:  wxhtzdy
 *    created: 23.05.2022 16:35:32
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    int x = *max_element(a.begin(), a.end());
    int y = *max_element(b.begin(), b.end());
    cout << (x < y ? "Bob" : "Alice") << '\n';
    cout << (x <= y ? "Bob" : "Alice") << '\n';
  }                                                                    
  return 0;
}