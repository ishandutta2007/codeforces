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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(all(a));
    vector<int> cnt(k);
    for (int i = 0; i < k; i++) {
      cin >> cnt[i];
      cnt[i]--;
    }
    sort(cnt.rbegin(), cnt.rend());
    int ans = 0, ptr = 0;
    for (int i = n - k; i < n; i++) {
      ans += a[i];
    }
    for (auto it : cnt) {
      if (it > 0) {
        ans += a[ptr];
        ptr += it;
      }
    }
    while (!cnt.empty() && cnt.back() == 0) {
      cnt.pop_back();
      ans += a.back();
      a.pop_back();
    }
    cout << ans << '\n';
  }
}