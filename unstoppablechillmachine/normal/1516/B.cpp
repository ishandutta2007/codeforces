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
    int vl = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      vl ^= a[i];
    }
    bool ok = false;
    int current = 0;
    for (int i = 0; i + 1 < n; i++) {
      current ^= a[i];
      if (current == (vl ^ current)) {
        ok = true;
      }
    }
    int lft = 0;
    for (int l = 1; l + 1 < n; l++) {
      lft ^= a[l - 1];
      int mid = 0;
      for (int r = l; r + 1 < n; r++) {
        mid ^= a[r];
        if (lft == mid && (lft == (mid ^ lft ^ vl))) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}