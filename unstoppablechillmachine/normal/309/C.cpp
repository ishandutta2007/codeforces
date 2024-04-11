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
  int n, m;
  cin >> n >> m;
  vector<int> have(n), kek;
  for (auto &it : have) {
    cin >> it;
  }  
  vector<int> cnt(31);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (x <= 30) {
      cnt[x]++;
    }
  }
  int ans = 0;
  sort(all(have));
  for (int i = 0; i <= 30; i++) {
    for (auto &it : have) {
      if (it % (1ll << (i + 1)) != 0) {
        if (cnt[i]) {
          //cout << it << ' ' << i << endl;
          ans++;
          cnt[i]--;
        }
        it -= 1ll << i;
      } 
    }
    bool fnd = true;
    while (fnd) {
      fnd = false;
      for (auto &it : have) {
        while (cnt[i] && it >= (1ll << i)) {
          cnt[i]--;
          ans++;
          it -= 1ll << i;
          fnd = true;
        }
      }
    }
    for (auto &it : have) {
      it -= it % (1ll << (i + 1)); 
    }
  }
  cout << ans << '\n';
}