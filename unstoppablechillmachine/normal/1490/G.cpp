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
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> pref, pos;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      sum += x;
      if (pref.empty() || pref.back() < sum) {
        pref.pb(sum);
        pos.pb(i);
      }
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      if (sum <= 0) {
        if (pref.back() < x) {
          cout << -1 << ' ';
        }
        else {
          int id = lower_bound(all(pref), x) - pref.begin();
          cout << pos[id] - 1 << ' ';
        }
      }
      else {
        if (pref.back() >= x) {
          int id = lower_bound(all(pref), x) - pref.begin();
          cout << pos[id] - 1 << ' ';
        }
        else {
          //cout << "KEK ";
          int laps = (x - pref.back() + sum - 1) / sum;
          x -= laps * sum;
          int id = lower_bound(all(pref), x) - pref.begin();
          cout << laps * n + pos[id] - 1 << ' ';
        }
      }
    }  
    cout << '\n';
  }
}