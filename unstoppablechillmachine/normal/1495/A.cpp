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
    int n;
    cin >> n;
    vector<int> guys, items;
    for (int i = 0; i < 2 * n; i++) {
      int x, y;
      cin >> x >> y;
      if (x == 0) {
        guys.pb(y);
      }
      else {
        items.pb(x);
      }
    }
    auto cmp = [](int a, int b) {
      return abs(a) < abs(b);
    };
    sort(all(guys), cmp);
    sort(all(items), cmp);
    auto dist = [](int x, int y, int x2, int y2) {
      return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
    };
    ld answer = 0;
    for (int i = 0; i < n; i++) {
      answer += dist(0, guys[i], items[i], 0);
    }
    cout << fixed << setprecision(10) << answer << '\n';
  }
}