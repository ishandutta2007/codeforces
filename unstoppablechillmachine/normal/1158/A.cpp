//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &it : a) {
    cin >> it;
  }
  for (auto &it : b) {
    cin >> it;
  }
  sort(all(a));
  sort(all(b));
  if (a.back() > b[0]) {
    cout << -1;
    exit(0);
  }
  if (n == 1) {
    if (b[0] == a[0]) {
      int ans = 0;
      for (auto it : b) {
        ans += it;
      }
      cout << ans;
    }
    else {
      cout << -1;
    }
    exit(0);
  }
  if (m == 1) {
    if (a.back() == b[0]) {
      int ans = 0;
      for (auto it : a) {
        ans += it;
      }
      cout << ans;
    }
    else {
      cout << -1;
    }
    exit(0);
  }
  if (a.back() == b[0]) {
    int ans = 0;
    for (int i = 0; i + 1 < SZ(a); i++) {
      ans += a[i] * m;
    }
    for (auto it : b) {
      ans += it;
    }
    cout << ans;
  }
  else {
    int ans = 0;
    for (int i = 1; i < m; i++) {
      ans += b[i];
    }
    ans += a.back();
    ans += b[0];
    ans += a[n - 2] * (m - 1);
    for (int i = 0; i + 2 < SZ(a); i++) {
      ans += a[i] * m;
    }
    cout << ans;
  }
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