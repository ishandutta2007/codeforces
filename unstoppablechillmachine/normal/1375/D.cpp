#include <bits/stdc++.h>
  typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll    
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> used(n + 1), ans;
    int timer = 0;
    for (int i = 0; i < n; i++) {
      int cm = 0;
      timer++;
      for (int j = 1; j <= n; j++) {
        used[a[j]] = timer;
      }
      while (used[cm] == timer) {
        cm++;
      }
      if (cm == n) {
        int pos = 1;
        while (pos <= n && a[pos] == pos - 1) {
          pos++;
        }
        if (pos > n) {
          break;
        }
        int id = 1;
        while (a[id] != pos - 1) {
          id++;
        }
        ans.pb(id);
        a[id] = n;
        ans.pb(pos);
        a[pos] = pos - 1;
      }
      else {
        ans.pb(cm + 1);
        a[cm + 1] = cm;
      }
    }
    cout << SZ(ans) << '\n';
    for (auto it : ans) {
      cout << it << ' ';
    }
    cout << '\n';
  }
}