/**
 *    author: m371
 *    created: 17.10.2021 09:56:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  if (k >= 1e8) {
    cout << -1 << '\n';
    return 0;
  }
  long long mn = k * (k + 1) / 2;
  if (n < mn) {
    cout << -1 << '\n';
    return 0;
  }
  long long mx = 1;
  for (int i = 2; i <= 1e5; i++) {
    long long curr = mn * i;
    if (curr > n) {
      break;
    }                
    if ((n - curr) % i == 0) {
      mx = max(mx, (long long) i);
    }        
    if (n % i == 0) {
      long long j = n / i;
      curr = mn * j;
      if (curr <= n && (n - curr) % j == 0) {
        mx = max(mx, j);
      }
    }
  }
  vector<long long> ans;
  for (int i = 0; i < k; i++) {
    ans.push_back((i + 1) * 1LL * mx);
  }
  ans.back() += n - accumulate(ans.begin(), ans.end(), 0LL);
  for (int i = 0; i < k; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}