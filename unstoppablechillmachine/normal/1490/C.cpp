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
  set<int> kek;
  for (int i = 1; i * i * i <= 1e12; i++) {
    kek.insert(i * i * i);
  }
  while (T--) {
    int n;
    cin >> n;
    bool ok = false;
    for (int i = 1; i * i * i < n; i++) {
      if (kek.count(n - i * i * i)) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}