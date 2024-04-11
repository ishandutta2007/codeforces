/**
 *  author: milos
 *  created: 15.01.2021 01:18:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  const int N = (int) 2e5 + 1;
  vector<int> cnt(N, 0);
  int mn = N, mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
    cnt[x]++;
  }
  int ans = mx != mn, x = 0;
  int sum = 0;
  for (int i = N - 1; i > mn; i--) {
    sum += cnt[i];
    long long y = x + sum;
    if (y > k) {
      ans++;
      x = sum;
    } else {
      x = y;  
    }
  }
  cout << ans << '\n';
  return 0;
}