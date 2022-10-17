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
 
const int INF = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> lft(2), rgt(2);
    map<int, int> pos;
    vector<pair<int, char>> kek(n);
    for (auto &it : kek) {
      cin >> it.first;
    }
    for (auto &it : kek) {
      cin >> it.second;
    }
    for (int i = 0; i < n; i++) {
      int x = kek[i].first;
      char dir = kek[i].second;
      pos[x] = i;
      if (dir == 'L') {
        lft[x % 2].insert(x);
      } else {
        rgt[x % 2].insert(x);
      }
    }
    vector<int> result(n, INF);
    for (int i = 0; i < 2; i++) {
      int nxt_r = m;
      while (!rgt[i].empty()) {
        int x = *rgt[i].rbegin();
        rgt[i].erase(x);
        auto it = lft[i].upper_bound(x);
        if (it != lft[i].end()) {
          result[pos[x]] = result[pos[*it]] = (*it - x) / 2;
          lft[i].erase(it);
          continue;
        }
        if (nxt_r < m) {
          result[pos[x]] = result[pos[nxt_r]] = (m - nxt_r) + (nxt_r - x) / 2;
          nxt_r = m;
        }
        else {
          nxt_r = x;
        }
      }
      int prv_l = 0;
      while (!lft[i].empty()) {
        int x = *lft[i].begin();
        lft[i].erase(x);
        auto it = rgt[i].lower_bound(x);
        if (it != rgt[i].begin()) {
          it--;
          result[pos[x]] = result[pos[*it]] = (x - *it) / 2;
          rgt[i].erase(it);
          continue;
        }
        if (prv_l > 0) {
          result[pos[x]] = result[pos[prv_l]] = prv_l + (x - prv_l) / 2;
          prv_l = 0;
        }
        else {
          prv_l = x;
        }
      }
      if (nxt_r != m && prv_l != 0) {
        result[pos[nxt_r]] = result[pos[prv_l]] = (m + prv_l + (m - nxt_r)) / 2;
      }
    }
    for (auto it : result) {
      cout << (it < INF ? it : -1) << ' ';
    }
    cout << '\n';
  }
}