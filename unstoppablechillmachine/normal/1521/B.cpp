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
 
const int INF = 1e9 + 7;

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
    int mx = 0;
    for (auto &x : a) {
      cin >> x;
    }
    cout << n / 2 << '\n';
    for (int i = 1; i < n; i += 2) {
      cout << i << ' ' << i + 1 << ' ' << min(a[i], a[i - 1]) << ' ' << INF << '\n';
    }
  }
}