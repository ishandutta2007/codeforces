/**
 *    author:  tourist
 *    created: 12.09.2021 17:35:25       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s;
    cin >> n >> s;
    int cnt = n / 2 + 1;
    cout << s / cnt << '\n';
  }
  return 0;
}