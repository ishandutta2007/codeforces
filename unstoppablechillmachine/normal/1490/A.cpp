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
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      int A = min(a[i], a[i + 1]), B = max(a[i], a[i + 1]);
      while (A * 2 < B) {
        A *= 2;
        ans++;
      }
    }
    cout << ans << '\n';
  }
}