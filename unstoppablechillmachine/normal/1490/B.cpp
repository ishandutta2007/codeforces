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
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x % 3]++;
    }
    int ans = 0;
    for (int iter = 0; iter < 3; iter++) {
      for (int i = 0; i < 3; i++) {
        if (cnt[(i + 1) % 3] < n / 3) {
          int ad = min(n / 3 - cnt[(i + 1) % 3],  cnt[i]);
          ans += ad;
          cnt[(i + 1) % 3] += ad;
          cnt[i] -= ad;
        }
      }  
    }
    cout << ans << '\n';
  }
}