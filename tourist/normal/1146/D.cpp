/**
 *    author:  tourist
 *    created: 20.04.2019 21:11:00       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, a, b;
  cin >> m >> a >> b;
  vector<int> first(a + b, -1);
  int x = 0;
  int y = 0;
  while (true) {
    first[x] = y;
    if (x >= b) {
      x -= b;
    } else {
      x += a;
    }
    if (x == 0) {
      break;
    }
    y = max(y, x);
  }
  long long ans = 0;
  for (int i = 0; i < a + b; i++) {
    if (first[i] != -1) {
      ans += max(0, m - first[i] + 1);
    }
  }
  if (m >= a + b) {
    int left = m - (a + b);
    int g = __gcd(a, b);
    int u = left / g * g;
    long long first = left - 0 + 1;
    long long last = left - u + 1;
    long long cnt = (first - last) / g + 1;
    ans += (first + last) * cnt / 2;
  }
  cout << ans << '\n';
  return 0;
}