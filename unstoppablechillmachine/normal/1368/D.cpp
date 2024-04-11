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
  int n;
  cin >> n;
  vector<int> cnt(20);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < 20; j++) {
      cnt[j] += (x >> j) & 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < 20; j++) {
      if (cnt[j] > 0) {
        cnt[j]--;
        cur |= 1 << j;
      }
    }
    ans += cur * cur;
  }  
  cout << ans << '\n';
}