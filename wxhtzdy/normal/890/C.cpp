#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans += max(0, cnt[i] - 1);
  }
  cout << ans << '\n';
  return 0;
}