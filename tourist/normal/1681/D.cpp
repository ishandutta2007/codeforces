/**
 *    author:  tourist
 *    created: 23.05.2022 18:39:11       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> p10(n);
  p10[0] = 1;
  for (int i = 1; i < n; i++) {
    p10[i] = p10[i - 1] * 10;
  }
  long long goal = p10[n - 1];
  const int inf = (int) 1e9;
  int ans = inf;
  function<void(int, long long)> Dfs = [&](int cnt, long long num) {
    if (cnt >= ans) {
      return;
    }
    if (num >= goal) {
      ans = cnt;
      return;
    }
    int need = 0;
    long long tmp = num;
    while (tmp < goal) {
      tmp *= 9;
      need += 1;
    }
    if (cnt + need >= ans) {
      return;
    }
    array<bool, 10> has;
    for (int d = 0; d < 10; d++) {
      has[d] = false;
    }
    tmp = num;
    while (tmp > 0) {
      has[tmp % 10] = true;
      tmp /= 10;
    }
    for (int d = 9; d >= 2; d--) {
      if (has[d]) {
        Dfs(cnt + 1, num * d);
      }
    }
  };
  Dfs(0, x);
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}