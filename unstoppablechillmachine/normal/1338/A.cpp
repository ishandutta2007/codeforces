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
    for (auto &it : a) {
      cin >> it;
    }
    int to = a[0], mx = -1;
    for (int i = 1; i < n; i++) {
      to = max(a[i], to);
      int diff = to - a[i];
      for (int j = 0; j <= 30; j++) {
        if ((diff >> j) & 1) {
          mx = max(mx, j);
        }
      }
    }
    cout << mx + 1 << '\n';
  }		
}