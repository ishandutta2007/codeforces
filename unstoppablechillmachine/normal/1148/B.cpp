//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<int> a(n), b(m);
  for (auto &it : a) {
    cin >> it;
  }
  for (auto &it : b) {
    cin >> it;
  }
  int ans = 0;
  for (int i = 0; i <= min(n, k); i++) {
    if (i >= n) {
      cout << -1;
      exit(0);
    }
    int can = k - i;
    int ind = lower_bound(all(b), a[i] + ta) - b.begin();
    if (m - ind <= can) {
      cout << -1;
      exit(0);
    }
    ans = max(ans, b[ind + can] + tb);
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}