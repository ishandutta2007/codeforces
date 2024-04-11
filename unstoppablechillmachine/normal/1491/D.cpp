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
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      cout << "NO\n";
      continue;
    }
    bool ok = true;
    int sum1 = 0, sum2 = 0;
    for (int bit = 0; bit < 30; bit++) {
      sum1 += (u >> bit) & 1;
      sum2 += (v >> bit) & 1;
      if (sum1 < sum2) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }  
}