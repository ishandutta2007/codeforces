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
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    if (n == 1) {
      cout << a[0] << '\n';
      continue;
    }
    int sum = a[0] + a.back();
    for (int i = 0; i + 1 < n; i++) {
      sum += abs(a[i] - a[i + 1]);
    }
    for (int i = 0; i < n; i++) {
      int can = 1e9 + 10;
      if (i > 0) {
        can = min(can, a[i] - a[i - 1]);
      }
      if (i + 1 < n) {
        can = min(can, a[i] - a[i + 1]);
      }
      sum -= max(0ll, can);
    }
    cout << sum << '\n';
  }
}