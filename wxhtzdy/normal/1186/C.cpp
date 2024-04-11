/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 14:55:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string a;
  cin >> a;
  string b;
  cin >> b;
  int n = (int) a.size();
  int m = (int) b.size();
  int sb = 0;
  for (int i = 0; i < m; i++) {
    sb += (b[i] - '0');
  }                  
  vector<int> f(n + 1);
  for (int i = 0; i < n; i++) {
    f[i + 1] = f[i] + (a[i] - '0');
  }  
  int ans = 0;
  for (int i = m; i <= n; i++) {
    if ((f[i] - f[i - m]) % 2 == sb % 2) {
      ans += 1;
    }
  }
  cout << ans << '\n';                                      
  return 0;
}