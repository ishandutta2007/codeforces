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
  sort(a.begin(), a.end());
  const int MX = (int) 2e5 + 5;
  vector<int> cnt(MX, 0), ans(MX, 0);
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (a[i] > 0) {
      if (cnt[a[i]] < k) {
        cnt[a[i]]++;
        ans[a[i]] += j;
      }
      a[i] /= 2;
      j++;
    }
  }
  int res = 1e9;
  for (int i = 0; i < MX; i++) {
    if (cnt[i] >= k) {
      res = min(res, ans[i]);
    }
  }
  cout << res << '\n';
  return 0;
}