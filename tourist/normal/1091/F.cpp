/**
 *    author:  tourist
 *    created: 30.12.2018 18:08:06       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> L(n);
  for (int i = 0; i < n; i++) {
    cin >> L[i];
    L[i] *= 2;
  }
  string s;
  cin >> s;
  long long ans = 0;
  int everW = 0;
  long long G = 0, W = 0;
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      G += L[i];
      ans += L[i] * 5;
    }
    if (s[i] == 'W') {
      everW = 1;
      W += L[i];
      ans += L[i] * 3;
    }
    if (s[i] == 'L') {
      long long x = L[i];
      ans += x * 1;
      long long takeW = min(x, W);
      x -= takeW;
      W -= takeW;
      long long takeG = min(x, G);
      x -= takeG;
      G -= takeG;
      if (x > 0) {
        ans += x * (everW ? 3 : 5);
      }
    }
    if (W == 0 && G == 0) {
      start = i + 1;
    }
  }
  long long extra = (W + G) / 2;
  if (extra > 0) {
    long long haveG = 0;
    for (int i = start; i < n; i++) {
      if (s[i] == 'G') {
        haveG += L[i];
      }
    }
    haveG = min(haveG, extra);
    long long low = 0, high = haveG;
    while (low < high) {
      long long mid = (low + high + 1) >> 1;
      vector<long long> turn(n, 0);
      long long need = mid;
      for (int i = n - 1; i >= start; i--) {
        if (s[i] == 'G') {
          turn[i] = min(need, L[i]);
          need -= turn[i];
        }
      }
      long long E = 0;
      int ok = 1;
      for (int i = start; i < n; i++) {
        if (s[i] == 'G') {
          E += L[i] - turn[i];
          E -= turn[i];
        }
        if (s[i] == 'W') {
          E += L[i];
        }
        if (s[i] == 'L') {
          E -= L[i];
        }
        if (E < 0) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    ans -= low * 4 + (extra - low) * 2;
  }
  cout << ans / 2 << '\n';
  return 0;
}