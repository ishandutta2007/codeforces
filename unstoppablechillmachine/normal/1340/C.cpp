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

const int N = 10010;
const int M = 1010;
bool used[N][M];
int a[N];
vector<int> have[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int at, bt;
  cin >> at >> bt;
  used[1][0] = true;
  int ans = 1e18;
  have[0].pb(1);
  for (int i = 0;; i++) {
    if (have[i].empty()) {
      break;
    }
    queue<pair<int, int>> q;
    for (auto it : have[i]) {
      q.push({it, 0});
    }
    while (!q.empty()) {
      pair<int, int> cur = q.front();
      if (cur.F == n) {
        ans = min(ans, i * (at + bt) + cur.S);
      }
      if (at - cur.S >= m - a[cur.F]) {
        ans = min(ans, i * (at + bt) + cur.S + m - a[cur.F]);
      }
      q.pop();
      if (cur.F < n) {
        int vl = cur.S + a[cur.F + 1] - a[cur.F];
        if (vl == at) {
          if (!used[cur.F + 1][0]) {
            used[cur.F + 1][0] = true;
            have[i + 1].pb(cur.F + 1);
          }
        }
        else if (vl < at) {
          if (!used[cur.F + 1][vl]) {
            used[cur.F + 1][vl] = true;
            q.push({cur.F + 1, vl});
          }
        }
      }
      if (cur.F > 1) {
        int vl = cur.S + a[cur.F] - a[cur.F - 1];
        if (vl == at) {
          if (!used[cur.F - 1][0]) {
            used[cur.F - 1][0] = true;
            have[i + 1].pb(cur.F - 1);
          }
        }
        else if (vl < at) {
          if (!used[cur.F - 1][vl]) {
            used[cur.F - 1][vl] = true;
            q.push({cur.F - 1, vl});
          }
        }
      }
    }
  }
  cout << (ans == 1e18 ? -1 : ans) << '\n';
}