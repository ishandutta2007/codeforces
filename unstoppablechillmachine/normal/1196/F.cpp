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

const int INF = 1e9 + 10;
const int N = 2e5 + 10;
vector<pair<int, ll>> g[N];
set<pair<ll, int>> st[N];
map<int, ll> dist[N];
bool cmp(pair<int, ll> a, pair<int, ll> b) {
  return a.S < b.S;
}
int cnt[N];
signed main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> ed;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].pb({v, c});
    g[v].pb({u, c});
    ed.pb(c);
  }
  sort(all(ed));
  ll lim = 1e18;
  if (k <= m) {
    lim = ed[k - 1];
  }
  for (int i = 1; i <= n; i++) {
    sort(all(g[i]), cmp);
  }
  set<pair<ll, int>> cur;
  int kk = k;
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
    for (auto u : g[i]) {
      if (cnt[i] < kk && u.S <= lim) {
        dist[i][u.F] = u.S;
        st[i].insert({u.S, u.F});
        if (u.F > i) {
          cnt[i]++;
        }
      } 
    }
    if (!st[i].empty()) {
      cur.insert({st[i].begin()->F, i});
    }
  } 
  ll lst = 0;
  while (k > 0) {
    int ind = cur.begin()->S;
    cur.erase(cur.begin());
    lst = st[ind].begin()->F;
    int v = st[ind].begin()->S;
    st[ind].erase(st[ind].begin());
    if (v > ind) {
      k--;
    }
    for (pair<int, ll> u : g[v]) {
      if (dist[ind].find(u.F) == dist[ind].end()) {
        if (cnt[ind] < kk && dist[ind][v] + u.S <= lim) {
          dist[ind][u.F] = dist[ind][v] + u.S;
          st[ind].insert({dist[ind][u.F], u.F});
          if (u.F > ind) {
            cnt[ind]++;
          }
        }
      }
      else if (dist[ind][v] + u.S < dist[ind][u.F]) {
        st[ind].erase({dist[ind][u.F], u.F});
        dist[ind][u.F] = dist[ind][v] + u.S;
        st[ind].insert({dist[ind][u.F], u.F}); 
      }
    }
    if (!st[ind].empty()) {
      cur.insert({st[ind].begin()->F, ind});
    }
  }
  cout << lst << '\n';
}