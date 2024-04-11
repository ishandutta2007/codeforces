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

vector<pair<int, int>> ans;
int k;

void get1(int a, int b) {
  if (b <= k) {
    ans.pb({a, 2 * k});
    ans.pb({b, 2 * k});
    ans.pb({a, 2 * k});
  }
  else {
    ans.pb({1, a});
    ans.pb({1, b});
    ans.pb({1, a});
  }
}

void get2(int a, int b) {
  //cout << a << ' ' << b << '\n';
  if (abs(a - b) >= k) {
    ans.pb({a, b});
    return;
  }
  ans.pb({1, b});
  ans.pb({a, 2 * k});
  ans.pb({1, 2 * k});
  ans.pb({1, b});
  ans.pb({a, 2 * k});
}

void source() {
  int n;
  cin >> n;
  k = n / 2;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      vector<int> path;
      int cur = i;
      while (a[cur] != i) {
        path.pb(cur);
        cur = a[cur];
      }
      path.pb(cur);
      for (auto it : path) {
        used[it] = true;
      }
      for (int j = SZ(path) - 1; j >= 1; j--) {
        if ((path[j] - 1) / k == (path[j - 1] - 1) / k) {
          get1(min(path[j], path[j - 1]), max(path[j], path[j - 1]));
        }
        else {
          get2(min(path[j], path[j - 1]), max(path[j], path[j - 1]));
        }
      }
    }
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << '\n';
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