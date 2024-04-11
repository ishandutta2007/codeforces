/**
 *    author:  milos
 *    created: 31.07.2020 12:01:59      
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 100050;

vector<vector<int>> g(N);

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int d = y - x;
    if (d % (a + b) != 0) cout << -1 << '\n';
    else cout << d / (a + b) << '\n';
  }
  return 0;   
}