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
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) {
      a[i] -= x;
    }
    const int inf = 1e9;    
    vector<vector<int>> dp(2, vector<int>(4, -inf));
    dp[1][0] = 0;
    for (int i = 0; i < n; i++) {
      int p = i % 2;
      int q = (i + 1) % 2;
      for (int f = 0; f < 4; f++) {
        dp[p][f] = -inf;
      } 
      for (int f = 0; f < 4; f++) {
        int x = (f >> 0 & 1);
        int y = (f >> 1 & 1);
        for (int s = 0; s < 2; s++) {
          if (i >= 1 && s > 0 && y > 0 && a[i] + a[i - 1] < 0) {
            continue;  
          }
          if (i >= 2 && s > 0 && y > 0 && x > 0 && a[i] + a[i - 1] + a[i - 2] < 0) {
            continue;
          }
          dp[p][s * 2 + y] = max(dp[p][s * 2 + y], dp[q][f] + s);
        }    
      }
    }
    int p = (n + 1) % 2;
    cout << *max_element(dp[p].begin(), dp[p].end()) << '\n';                                                                   
  }
  return 0;
}