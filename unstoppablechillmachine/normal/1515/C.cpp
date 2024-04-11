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
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> tw;
    for (int i = 1; i <= m; i++) {
      tw.insert({0ll, i});
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      pair<int, int> cur = *tw.begin();
      tw.erase(tw.begin());
      cout << cur.second << ' ';
      cur.first += x;
      tw.insert(cur);
    }
    cout << '\n';
  }
}