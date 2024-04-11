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
    vector<int> d(n);
    for (auto &x : d) {
      cin >> x;
    }
    sort(all(d));
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    int ans = d.back(), sum = 0;
    for (int i = 1; i < n; i++) {
      ans -= d[i] * i - sum;
      sum += d[i];
    }
    cout << ans << '\n';
  }
}