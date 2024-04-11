/**
 *    author:  milos
 *    created: 13.02.2021 23:48:03       
**/
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
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (int) (s[i] - '0');
    }
    auto Solve = [&](vector<int> a, int ss) {
      int sz = (int) a.size(), ans = ss, t = 0;
      vector<int> dp(sz);
      for (int i = 0; i < sz; i++) {
        t += a[i], dp[i] = a[i] ^ 1;
        if (i > 0) {
          dp[i] += min(dp[i - 1], t - a[i]);
        }
        int tmp = dp[i];
        tmp += ss;
        tmp -= t;
        ans = min(ans, tmp);
      }
      return ans;
    };
    int ans = (int) 1e9;
    for (int i = 0; i < k; i++) {
      vector<int> b;
      int ss = 0;
      for (int j = i; j < n; j += k) {
        b.push_back((int) (s[j] - '0'));
        ss += b.back();
      }                
      int curr = Solve(b, ss);
      curr += sum - ss;
      ans = min(ans, curr);
    }
    cout << ans << '\n';
  }
  return 0;
}