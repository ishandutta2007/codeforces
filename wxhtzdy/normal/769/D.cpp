/**
 *    author: m371
 *    created: 18.10.2021 15:45:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }    
  const int MAX = 1e4 + 5;
  vector<int> cnt(MAX);
  for (int i = 0; i < n; i++) {
    cnt[a[i]] += 1;
  }
  long long ans = 0;                   
  for (int i = 0; i < MAX; i++) {
    for (int j = i; j < MAX; j++) {
      if (__builtin_popcount(i ^ j) == k) {
        if (i == j) {
          ans += (cnt[i] * 1LL * (cnt[i] - 1)) / 2;
        } else {
          ans += cnt[i] * 1LL * cnt[j];
        }
      }
    }
  }
  cout << ans << '\n';  
  return 0;
}