#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<pair<int, int> > > s(m + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    s[x].pb({a[i], i});
  }
  vector<bool> cc(n + 1);
  for (int i = 1; i <= m; i++) {
    sort(s[i].rbegin(), s[i].rend());
    cc[s[i][0].S] = true;
  }
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    if (!cc[x]) {
      ans++;
    }
  }
  cout << ans;
}
signed main() {
#ifdef extraterrestrial_
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}