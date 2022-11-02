#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define st first
#define nd second
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
  int n; cin >> n;
  vector<vector<int>> seg(30);
  vector<vector<pair<int, int>>> hole(30);
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    if (c == 'C') {
      int r, t1, t2;
      cin >> r >> t1 >> t2;
      hole[r].push_back({t2, t1});
    } else {
      int r1, r2, t; 
      cin >> r1 >> r2 >> t;
      for (int j = r1; j < r2; j++)
        seg[j].push_back(t);
    }
  }

  for (int i = 1; i < 30; i++)
    sort(all(seg[i]));
  for (int i = 0; i <= 22; i++) {
    if (hole[i].empty()) {
      for (int j = 0; j < 360; j++)
        hole[i].push_back({j, j + 1});
      continue;
    }
    sort(all(hole[i]));
    vector<pair<int, int>> tmp;
    for (int j = 0; j < 360; j++) {
      int o = 1;
      for (auto [l, r]: hole[i]) {
        if (r < l)
          r += 360;
        if (!((l <= j && j + 1 <= r) || (l - 360 <= j && j + 1 <= r - 360)))
          o = 0;
      }
      if (o == 1)
        tmp.push_back({j, j + 1});
    }
    hole[i] = tmp;
  }

  vector<int> vis(22 * 360);
  deque<int> pq;
  for (int i = 0; i < 360; i++) {
    vis[i] = 1;
    pq.push_back(i);
  }
  int ans = 0;

  auto go = [&](int r, int a) {
    if (r > 20) {
      ans = 1;
      return;
    }
    if (!vis[r * 360 + a]) {
      vis[r * 360 + a] = 1;
      pq.push_back(r * 360 + a);
    }
  };

  while (sz(pq) && ans == 0) {
    // break;
    int i = pq.front(); pq.pop_front();
    int a = i % 360;
    int r = i / 360;
    // if (r >= 20 && a >= 180 && a < 190)
    //   cout << r << " " << a << endl;
    {
      int j = lower_bound(all(seg[r]), (a + 1) % 360) - seg[r].begin();
      if (j == sz(seg[r]) || seg[r][j] != (a + 1) % 360)
        go(r, (a + 1) % 360);
    }
    {
      int j = lower_bound(all(seg[r]), a) - seg[r].begin();
      if (j == sz(seg[r]) || seg[r][j] != a)
        go(r, (a - 1 + 360) % 360);
    }
    for (int rr: {r - 1, r + 1}) {
      if (rr < 0)
        continue;
      int j = lower_bound(all(hole[min(rr, r) + 1]), make_pair(a, a + 1)) - hole[min(rr, r) + 1].begin();
      // if (rr > 20 && a >= 180 && a < 190)
      //   cout << sz(hole[min(rr, r) + 1]) << " " << j << " " << rr << endl;
      if (j < sz(hole[min(rr, r) + 1]) && hole[min(rr, r) + 1][j] == make_pair(a, a + 1)) {
        // if (rr > 20 && a >= 180 && a < 190)
        //   cout << j << " -- " << rr << endl;
        go(rr, a);
      }
    }
  }

  if (ans == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) solve();
}