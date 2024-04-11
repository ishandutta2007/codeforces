#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

vector<int> solve(int n, int m, vector<int> a) {
  map<int, int> nxt;
  map<int, vector<int>> have;
  vector<int> dp(m + 1);
  for (int i = m; i >= 1; i--) {
    int vl = a[i] - i;
    if (nxt.find(vl - 1) == nxt.end()) {
      dp[i] = 1;
    }
    else {
      dp[i] = dp[nxt[vl - 1]] + 1;
    }
    nxt[vl] = i;
    have[vl].pb(i);
  }
  for (auto &it : have) {
    reverse(all(it.S));
  }
  vector<int> R(n + 1);
  for (int i = 1; i <= n; i++) {
    if (have[i].empty()) {
      R[i] = min(n, i + m + 1);
    }
    else {
      R[i] = min(n, i + m + 1 - dp[have[i][0]]);
    }
  }
  return R;
} 

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << 0 << '\n';
    exit(0);
  }
  vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  vector<int> R = solve(n, m, a);
  for (int i = 1; i <= m; i++) {
    a[i] = n - a[i] + 1;
  }
  vector<int> L = solve(n, m, a);
  vector<int> true_L(n + 1);
  for (int i = 1; i <= n; i++) {
    true_L[i] = n - L[n - i + 1] + 1;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += R[i] - true_L[i] + 1;
  }
  cout << ans << '\n';
  /*ll ans = 0; 
  for (int i = 1; i <= n; i++) {
    int curR = i, curL = i;
    for (int j = 1; j <= m; j++) {
      if (curR == n) {
        break;
      }
      if (a[j] != curR + 1) {
        curR++;
      }
    }
    if (curR < n) {
      curR++;
    }
    for (int j = 1; j <= m; j++) {
      if (curL == 1) {
        break;
      }
      if (a[j] != curL - 1) {
        curL--;
      }
    }
    if (curL > 1) {
      curL--;
    }
    ans += curR - curL + 1;
  }
  cout << ans << '\n';*/
}