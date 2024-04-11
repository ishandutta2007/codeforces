#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll    

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    int dx = abs(x - x2), dy = abs(y - y2);
    if (dx > dy) {
      swap(dx, dy);
    }
    if (dx == 0) {
      cout << dy << '\n';
    }
    else {
      cout << dx + dy + 2 << '\n';
    }
  }
}