#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

signed main() {
  ios_base::sync_with_stdio(0);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
  }  
  for (int i = 0; i < n; i++) {
    int l = max(i - x, 0), r = min(n - 1, i + y);
    bool ok = true;
    for (int j = l; j <= r; j++) {
      if (j != i && a[j] <= a[i]) {
        ok = false;
      }
    }
    if (ok) {
      cout << i + 1 << '\n';
      exit(0);
    }
  }
}