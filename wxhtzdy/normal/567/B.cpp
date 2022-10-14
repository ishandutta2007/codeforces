/**
 *    author:  milos
 *    created: 21.02.2021 14:50:17       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<char> foo(n);
  vector<int> x(n);
  const int MX = (int) 1e6 + 5;
  vector<int> cnt(MX, 0);
  int bal = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> foo[i] >> x[i];
    if (foo[i] == '+') {
      cnt[x[i]]++;
      bal++;
      ans = max(ans, bal);
    }
    if (foo[i] == '-') {
      if (cnt[x[i]] == 0) {
        ans++;
      } else {
        cnt[x[i]]--;
        bal--;
      }
    }
  }                 
  cout << ans << '\n'; 
  return 0;
}