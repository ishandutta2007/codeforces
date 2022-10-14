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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] * a[i] * (n - 1);
      ans += b[i] * b[i] * (n - 1);
    }
    const int MAX = n * 100 + 5;
    const long long inf = (long long) 1e15;
    vector<vector<long long>> dp(n, vector<long long>(MAX, inf));
    dp[0][a[0]] = 0;
    dp[0][b[0]] = 0;
    int s = a[0] + b[0];
    for (int i = 1; i < n; i++) {
      s += a[i] + b[i];
      for (int sa = 0; sa < MAX; sa++) {
        for (int foo = 0; foo < 2; foo++) {
          int sb = s - sa;
          if (sa >= a[i] && sb >= b[i]) { 
            dp[i][sa] = min(dp[i][sa], dp[i - 1][sa - a[i]] + (sa - a[i]) * 1LL * a[i] * 2 + (sb - b[i]) * 1LL * b[i] * 2);  
          }
          swap(a[i], b[i]);
        }
      }
    }
    cout << ans + *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
  }                                                                    
  return 0;
}