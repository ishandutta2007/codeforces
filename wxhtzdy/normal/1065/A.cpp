/**
 *  author: milos
 *  created: 15.01.2021 00:54:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long s, a, b, c;
    cin >> s >> a >> b >> c;
    long long take = s / c;
    take += take / a * b;
    cout << take << '\n';
  }
  return 0;
}