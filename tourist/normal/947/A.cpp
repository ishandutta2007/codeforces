/**
 *    author:  tourist
 *    created: 10.03.2018 19:12:30       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  vector<int> p(x + 1);
  for (int i = 1; i <= x; i++) {
    p[i] = i;
  }
  for (int i = 2; i <= x; i++) {
    if (p[i] == i) {
      for (int j = i + i; j <= x; j += i) {
        p[j] = min(p[j], i);
      }
    }
  }
  const int inf = (int) 1e9;
  vector<int> best(x + 1, inf);
  for (int i = 1; i <= x; i++) {
    int tmp = i;
    while (tmp > 1) {
      int d = p[tmp];
      if (i != d) {
        best[i] = min(best[i], i - d + 1);
      }
      tmp /= p[tmp];
    }
  }
  int res = inf;
  {
    int tmp = x;
    while (tmp > 1) {
      int d = p[tmp];
      for (int j = x - d + 1; j <= x; j++) {
        res = min(res, best[j]);
      }
      tmp /= p[tmp];
    }
  }
  cout << res << '\n';
  return 0;
}