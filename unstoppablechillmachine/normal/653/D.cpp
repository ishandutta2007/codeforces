#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

struct edge {
  int to;
  ld cap, f;
  edge() {};
  edge(int to, ld cap, ld f) : to(to), cap(cap), f(f) {};
};

const int N = 1010;
const ld INF = 1e9 + 10;  
vector<int> g[N], g2[N];
edge arr[N], arr2[N];
int cnt;
void add_edge(int from, int to, int cap) {
  arr2[cnt] = edge(to, cap, 0);
  g2[from].pb(cnt++);
  arr2[cnt] = edge(from, 0, 0);
  g2[to].pb(cnt++);  
}

int used[N], timer;

int dfs(int s, int t, ld kek, ld mn = INF) {
  if (s == t) {
    return int(mn / kek);
  }
  used[s] = timer;
  for (auto it : g[s]) {
    if (used[arr[it].to] < timer && arr[it].cap - arr[it].f >= kek) {
      int cnt = dfs(arr[it].to, t, kek, min(mn, arr[it].cap - arr[it].f));
      if (cnt > 0) {
        arr[it].f += kek * (ld)cnt;
        arr[it ^ 1].f -= kek * (ld)cnt;
        return cnt;
      }
    }
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    add_edge(u, v, c);
  }
  ld l = 0, r = 1e6 + 10;
  for (int iter = 0; iter < 150; iter++) {
    for (int i = 1; i <= n; i++) {
      g[i] = g2[i];
    }
    for (int i = 0; i < cnt; i++) {
      arr[i] = arr2[i];
    }
    ld mid = (l + r) / 2;
    int cnt = 0;
    while (cnt < x) {
      timer++;  
      int mx = dfs(1, n, mid);
      if (mx == 0) {
        break;
      }
      cnt += mx;
    }
    if (cnt >= x) {
      l = mid;
    }
    else {
      r = mid;
    }
  }  
  cout << fixed << setprecision(10) << l * (ld)x << '\n';
}