/**
 *    author:  milos
 *    created: 25.03.2021 15:36:28       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    long long x;
    cin >> x;
    long long i = (x - 1) / n, j = (x - 1) % n;
    cout << j * m + i + 1 << '\n';
  }
  return 0;
}