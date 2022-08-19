/**
 *    author:  tourist
 *    created: 03.06.2022 18:40:26       
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
  int n, m;
  cin >> n >> m;
  auto Ask = [&](string s) {
    cout << "? " << s << endl;
    long long x;
    cin >> x;
    return x;
  };
  vector<long long> l(m);
  for (int i = 0; i < m; i++) {
    string s(m, '0');
    s[i] = '1';
    l[i] = Ask(s);
  }
  vector<int> order(m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return l[i] < l[j];
  });
  string s(m, '0');
  long long ans = 0;
  for (int i : order) {
    s[i] = '1';
    long long got = Ask(s);
    if (got == ans + l[i]) {
      ans = got;
    } else {
      s[i] = '0';
    }
  }
  cout << "! " << ans << endl;
  return 0;
}