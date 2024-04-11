/**
 *    author:  wxhtzdy
 *    created: 23.05.2022 16:37:46
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
    long long s = accumulate(b.begin(), b.end(), 0LL);
    cout << a[s % n] << '\n';
  }                                                                    
  return 0;
}