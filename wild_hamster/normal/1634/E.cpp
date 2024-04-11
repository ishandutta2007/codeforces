#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;

ll n, t, k, x, y, m;
vector<ll> g[255555];
ll pnt[255555], pntg[455555];
string ans[255555];
map<ll, ll> suck;
map<ll, ll> compr;
vector<pii> gg[455555];
string s;

int main() {
  cin >> m;
  for (int ii = 0; ii < m; ii++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      g[ii].push_back(x);
      ans[ii].push_back('O');
      suck[x]++;
    }
  }
  k = 1;
  for (auto it : suck) {
    if (it.second % 2 != 0) {
      cout << "NO" << endl;
      return 0;
    }
    compr[it.first] = k++;
  }
  cout << "YES" << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      g[i][j] = compr[g[i][j]];
      gg[g[i][j]].push_back(mp(i, j));
    }
  }

  for (int i = 0; i < m; i++) {
    if (pnt[i] == g[i].size()) {
      continue;
    }
    while (pnt[i] < g[i].size() && ans[i][pnt[i]] != 'O') {
      pnt[i]++;
    }
    while (pnt[i] < g[i].size()) {
      ll l = g[i][pnt[i]];
      ans[i][pnt[i]] = 'L';
      while (pnt[i] < g[i].size() && ans[i][pnt[i]] != 'O') {
        pnt[i]++;
      }
      ans[i][pnt[i]] = 'R';
      ll r = g[i][pnt[i]];
      while (pnt[i] < g[i].size() && ans[i][pnt[i]] != 'O') {
        pnt[i]++;
      }
      while (l != r) {
        while (ans[gg[r][pntg[r]].X][gg[r][pntg[r]].Y] != 'O') {
          pntg[r]++;
        }

        ll x = gg[r][pntg[r]].X;
        ll y = gg[r][pntg[r]].Y;
        ans[x][y] = 'L';
        while (pnt[x] < g[x].size() && ans[x][pnt[x]] != 'O') {
          pnt[x]++;
        }
        ans[x][pnt[x]] = 'R';
        r = g[x][pnt[x]];
        while (pnt[x] < g[x].size() && ans[x][pnt[x]] != 'O') {
          pnt[x]++;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}