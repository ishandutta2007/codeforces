/**
 *    author:  milos
 *    created: 30.03.2021 20:56:31       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;                                  
  vector<int> a(n), b(26);
  for (int i = 0; i < n; i++) {
    int fk = 1;
    for (int j = 0; j < 26; j++) {
      if ((int) s[i] - 'a' < j) {
        fk = max(fk, b[j] + 1);
      }
    }
    a[i] = fk;
    int ch = (int) s[i] - 'a';
    b[ch] = max(b[ch], fk);
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans = max(ans, b[i]);
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  return 0;
}