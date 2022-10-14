/**
 *    author:  milos
 *    created: 28.01.2021 17:04:13       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dist = max(abs(x1 - x2), abs(y1 - y2));
  cout << dist << '\n';
  return 0;
}