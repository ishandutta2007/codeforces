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
  if (n < k) {
    cout << "NO" << '\n';
    return 0;
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j){
    return a[i] < a[j];
  });
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    ans[order[i]] = (i % k) + 1;
  }
  const int N = 5005;
  vector<int> cnt(N, 0);
  for (int i = 0; i < n; i++) {
    cnt[a[i]] += 1;
    if (cnt[a[i]] > k) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  return 0;
}