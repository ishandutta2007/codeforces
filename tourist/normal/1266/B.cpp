/**
 *    author:  tourist
 *    created: 17.12.2019 18:11:28       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    cout << (14 <= n && 1 <= n % 14 && n % 14 <= 6 ? "YES" : "NO") << '\n';
  }
  return 0;
}