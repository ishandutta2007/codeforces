/**
 *    author:  tourist
 *    created: 08.10.2021 18:07:34       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s == k) {
      cout << "YES" << '\n';
      continue;
    }
    long long ans = s / (2 * k) * k;
    long long rm = s % (2 * k);
    ans += min(rm + 1, k);
    cout << (n + 1 > ans ? "YES" : "NO") << '\n';
  }
  return 0;
}