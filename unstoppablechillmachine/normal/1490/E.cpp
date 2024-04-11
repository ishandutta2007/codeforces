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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].F;
      a[i].S = i;
    }
    sort(all(a));
    int pref = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i].F > pref) {
        mx = i;
      }
      pref += a[i].F;
    }
    vector<int> kek;
    for (int i = mx; i < n; i++) {
      kek.pb(a[i].S);
    }
    sort(all(kek));
    cout << SZ(kek) << '\n';
    for (auto it : kek) {
      cout << it + 1 << ' ';
    }
    cout << '\n';
  }
}