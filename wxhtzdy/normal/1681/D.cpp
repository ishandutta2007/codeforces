/**
 *    author:  wxhtzdy
 *    created: 24.05.2022 07:17:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  long long x;
  cin >> x;
  const int inf = 1e9;
  int ans = inf;
  long long pw = 1;
  for (int i = 1; i < n; i++) {
    pw *= 10;
  }
  function<void(int, long long)> Dfs = [&](int d, long long p) {
    if (p >= pw) {
      ans = min(ans, d);
      return;
    }
    if (d >= ans) {
      return;
    }
    vector<bool> dig(10, false);
    long long tmp = p;
    int len = 0;
    while (tmp > 0) {
      dig[tmp % 10] = true;
      tmp /= 10;
      len += 1;
    }       
    if (n - len + d >= ans) {
      return;
    }
    for (int i = 2; i < 10; i++) {
      if (dig[i]) {
        Dfs(d + 1, p * i);
      }
    }
  };
  Dfs(0, x);
  cout << (ans == inf ? -1 : ans) << '\n';                                                                   
  return 0;
}