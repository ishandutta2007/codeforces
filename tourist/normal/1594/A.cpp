/**
 *    author:  tourist
 *    created: 08.10.2021 18:33:27       
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
    cout << -(n - 1) << " " << n << '\n';
  }
  return 0;
}