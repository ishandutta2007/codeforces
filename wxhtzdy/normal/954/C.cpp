/**
 *    author:  milos
 *    created: 02.04.2021 00:10:11       
**/
#include <bits/stdc++.h>
 
using namespace std;

struct Point {
  int x, y;
  void init(int n, int w) {
    n--;
    y = n % w;
    x = n / w; 
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int y = 1e9;
  for (int i = 1; i < n; i++) {
    if (abs(a[i] - a[i - 1]) > 1) {
      y = abs(a[i] - a[i - 1]); 
    }
  }
  bool ok = true;
  for (int i = 1; i < n; i++) {
    ok &= (abs(a[i] - a[i - 1]) == 1 || abs(a[i] - a[i - 1]) == y);  
  }
  for (int i = 1; i < n; i++) {
    Point x1, y1;
    x1.init(a[i], y);
    y1.init(a[i - 1], y);
    if (abs(x1.x - y1.x) + abs(x1.y - y1.y) != 1) {
      ok = false;
    }
  }
  if (!ok) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  cout << (int) 1e9 << " " << y << '\n'; 
  return 0;
}