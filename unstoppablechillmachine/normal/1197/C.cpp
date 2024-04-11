#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b;
  for (auto &it : a) {
    cin >> it;
  }
  for (int i = 1; i < n; i++) {
    b.pb(a[i] - a[i - 1]);
  }
  sort(all(b));
  int lim = n - k, ans = 0;
  for (int i = 0; i < lim; i++) {
    ans += b[i];
  }
  cout << ans << '\n';
}