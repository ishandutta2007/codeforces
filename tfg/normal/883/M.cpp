#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx = abs(x1 - x2), dy = abs(y1 - y2);
  int ans = 2 * (dx + dy + 2);
  if (dx == 0) {
    ans += 2;
  }
  if (dy == 0) {
    ans += 2;
  }
  cout << ans << endl;
 }