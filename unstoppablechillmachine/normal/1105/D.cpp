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

void source() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> z(k);
  for (auto &it : z) {
    cin >> it;
  }  
  vector<vector<char>> a(n, vector<char>(m));
  vector<vector<pii>> kek(k + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] >= '1' && a[i][j] <= '9') {
        kek[a[i][j] - '0'].pb(make_pair(i, j));
      }
    }
  }
  vector<vector<vector<int>>> dist(k + 1, vector<vector<int>>(n, vector<int>(m, INF)));
  vector<pii> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  vector<queue<pii>> q(k + 1);
  vector<vector<pii>> ans(n, vector<pii>(m, make_pair(INF, INF)));
  for (int i = 1; i <= k; i++) {
    for (auto it : kek[i]) {
      q[i].push(it);
      ans[it.F][it.S] = make_pair(0, i);
      dist[i][it.F][it.S] = 0;
    }
  }
  for (int lol = 1;; lol++) {
    bool ok = false;
    for (int i = 1; i <= k; i++) {
      while (!q[i].empty()) {
        pii v = q[i].front();
        ok = true;
        if (dist[i][v.F][v.S] + 1 > lol * z[i - 1]) {
          break;
        }
        q[i].pop();
        for (auto it : delta) {
          pii to = {v.F + it.F, v.S + it.S};
          if (to.F >= 0 && to.S >= 0 && to.F < n && to.S < m && a[to.F][to.S] != '#' && ans[to.F][to.S].S == INF) {
            dist[i][to.F][to.S] = dist[i][v.F][v.S] + 1;
            ans[to.F][to.S] = make_pair(lol, i);
            q[i].push(to);
          }
        }
      }
    }
    if (!ok) {
      break;
    }
  } 
  vector<int> res(k + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j].S < INF) {
        res[ans[i][j].S]++;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    cout << res[i] << ' ';
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