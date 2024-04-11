#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(n);
  for (int i = 0; i < 21; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << i)) {
        cnt++;
      }
    }
    for (int j = 0; j < cnt; j++) {
      b[j] += (1 << i);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += b[i] * b[i];
  }
  cout << ans << '\n';
  return 0;
}