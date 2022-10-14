/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 17:37:59
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
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    vector<int> a, b;
    for (int i = 1; i + 1 < n; i++) {
      if (i % 2 == 1) {
        a.push_back(i);
      } else {
        b.push_back(i);
      }
    }
    auto Cost = [&](int i) {
      return max(0, max(h[i - 1], h[i + 1]) - h[i] + 1);
    };
    auto Calc = [&](vector<int> ids) {
      long long s = 0;
      for (int i : ids) {
        s += Cost(i);
      }
      return s;
    };
    if (n % 2 == 1) {
      cout << Calc(a) << '\n';
    } else {
      const long long inf = 1e17;
      vector<vector<long long>> dp(n, vector<long long>(2, inf));
      dp[0][0] = 0;
      for (int i = 1; i + 1 < n; i++) {
        {                        
          long long ft = (i == 1 ? 0LL : dp[i - 2][0]);
          dp[i][0] = ft + Cost(i);
        }
        if (i >= 4 && i % 2 == 0) {
          dp[i][1] = min(dp[i][1], dp[i - 3][0] + Cost(i));          
        }
        if (i >= 3) {
          dp[i][1] = min(dp[i][1], dp[i - 2][1] + Cost(i));
        }
      }
      cout << min({dp[n - 2][0], dp[n - 3][0], dp[n - 2][1], dp[n - 3][1]}) << '\n';
    }
  }                                                                    
  return 0;
}