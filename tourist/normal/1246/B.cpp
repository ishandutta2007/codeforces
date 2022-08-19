/**
 *    author:  tourist
 *    created: 26.10.2019 12:06:50       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 100010;
  vector<int> p(MAX);
  iota(p.begin(), p.end(), 0);
  for (int i = 2; i < MAX; i++) {
    if (p[i] == i) {
      for (int j = i + i; j < MAX; j += i) {
        if (p[j] == j) {
          p[j] = i;
        }
      }
    }
  }
  int n, k;
  cin >> n >> k;
  vector<int> cnt(MAX);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int res = 1;
    long long ask = 1;
    while (x > 1) {
      int y = p[x];
      int cc = 0;
      while (x % y == 0) {
        x /= y;
        ++cc;
      }
      cc %= k;
      for (int j = 0; j < cc; j++) {
        res *= y;
      }
      for (int j = 0; j < (k - cc) % k; j++) {
        ask *= y;
        ask = min(ask, MAX - 1LL);
      }
    }
    ans += cnt[ask];
    ++cnt[res];
  }
  cout << ans << '\n';
  return 0;
}