/**
 *    author:  tourist
 *    created: 25.01.2021 18:11:38       
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
    int mx = *max_element(a.begin(), a.end());
    vector<int> cnt(mx + 1);
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
    }
    vector<int> dp(mx + 1);
    for (int i = 1; i <= mx; i++) {
      dp[i] += cnt[i];
      for (int j = i + i; j <= mx; j += i) {
        dp[j] = max(dp[j], dp[i]);
      }
    }
    cout << n - *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}