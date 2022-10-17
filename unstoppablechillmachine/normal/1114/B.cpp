#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

const int BINF = 1e18 + 10;

void source() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].F;
    arr[i].S = i;
  }
  sort(arr.rbegin(), arr.rend());
  int ans = 0;
  vector<int> res;
  for (int i = 0; i < k * m; i++) {
    ans += arr[i].F;
    res.pb(arr[i].S);
  }
  cout << ans << '\n';
  sort(all(res));
  for (int i = 1; i < k; i++) {
    cout << res[i * m - 1] + 1 << ' ';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}