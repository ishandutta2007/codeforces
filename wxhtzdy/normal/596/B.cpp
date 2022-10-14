#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long add = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    a[i] += add;
    ans += abs(a[i] - b[i]);
    add += b[i] - a[i];
  }
  cout << ans << '\n';
  return 0;
}