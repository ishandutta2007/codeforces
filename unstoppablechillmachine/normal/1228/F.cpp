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

const int N = (1 << 17) + 10;
vector<int> g[N], g2[N];
int h[N];

bool check(int v, int par = 0) {
  if (SZ(g[v]) == 1) {
    h[v] = 0;
    if (g[v][0] == par) {
      return true;
    }
    return false;
  }
  int a = -1, b = -1;
  for (auto u : g[v]) {
    if (u != par) {
      if (a == -1) {
        a = u;
        if (!check(u, v)) {
          return false;
        }
      }
      else if (b == -1) {
        b = u;
        if (!check(u, v)) {
          return false;
        }
      }
      else {
        return false;
      }
    }
  }
  if (a == -1 || b == -1) {
    return false;
  }
  if (h[a] != h[b]) {
    return false;
  }
  h[v] = h[a] + 1;
  return true;
}

int ok = 0, n;
int dp[N];
void get(int v, int par = 0) {
  if (ok) {
    return;
  }
  if (SZ(g[v]) == 1) {
    dp[v] = 0;
    return;
  }
  dp[v] = n;
  int cnt = 0;
  vector<pair<int, int>> kek;
  for (auto u : g[v]) {
    if (u != par) {
      get(u, v);
      if (ok) {
        return;
      }
      cnt++;
      dp[v] = min(dp[v], dp[u] + 1);
      kek.pb({dp[u], u});
    }
  }
  if (cnt == 3) {
    ok = v;
    sort(all(kek));
    g[v] = {par, kek.back().S, (1 << n) - 1};
    g[(1 << n) - 1] = {v, kek[0].S, kek[1].S};
    vector<int> na, nb;
    for (auto it : g[kek[0].S]) {
      if (it != v) {
        na.pb(it);
      }
    }
    na.pb((1 << n) - 1);
    g[kek[0].S] = na;
    for (auto it : g[kek[1].S]) {
      if (it != v) {
        nb.pb(it);
      }
    }
    nb.pb((1 << n) - 1);
    g[kek[1].S] = nb;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < (1 << n) - 2; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }  
  if (n == 2) {
    cout << 2 << '\n' << 1 << ' ' << 2 << '\n';
    exit(0);
  }
  vector<int> lf;
  for (int i = 1; i <= (1 << n) - 2; i++) {
    if (SZ(g[i]) == 1) {
      lf.pb(i);
    }
  }
  if (SZ(lf) < (1 << (n - 1)) - 1) {
    cout << 0 << '\n';
    exit(0);
  }
  if (SZ(lf) == (1 << (n - 1)) - 1) {
    //cout << "KEK\n";
    int pr = -1;
    for (int i = 1; i <= (1 << n) - 2; i++) {
      int cnt = 0;
      for (auto u : g[i]) {
        if (SZ(g[u]) == 1) {
          cnt++;
        }
      }
      if (cnt == 1) {
        pr = i;
        break;
      }
    }
    //cout << pr << '\n';
    if (pr == -1) {
      cout << 0 << '\n';
      exit(0);
    }
    int root = -1;
    g[pr].pb((1 << n) - 1);
    g[(1 << n) - 1].pb(pr);
    for (int i = 1; i <= (1 << n) - 2; i++) {
      if (SZ(g[i]) == 2) {
        root = i;
        break;
      }
    }
    if (root == -1) {
      cout << 0 << '\n';
      exit(0);
    }
    if (check(root)) {
      cout << 1 << '\n' << pr << '\n';
    }
    else {
      cout << 0 << '\n';
    }
    exit(0);
  }
  
  vector<int> roots;
  for (int i = 1; i <= (1 << n) - 2; i++) {
    if (SZ(g[i]) == 2) {
      roots.pb(i);
    }
  }
  if (SZ(roots) > 1) {
    cout << 0 << '\n';
    exit(0);
  }
  if (SZ(roots) == 1) {
    get(roots[0]);
    if (ok && check(roots[0])) {
      cout << 1 << '\n' << ok << '\n';
    }
    else {
      cout << 0 << '\n';
    }
    exit(0);
  }
  vector<int> dist(1 << n, n);
  queue<int> q;
  for (auto it : lf) {
    dist[it] = 0;
    q.push(it);
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : g[v]) {
      if (dist[u] == n) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  vector<int> lol;
  for (int i = 1; i <= (1 << n) - 2; i++) {
    if (dist[i] == n - 2) {
      lol.pb(i);
    }
    if (dist[i] > n - 2) {
      cout << 0 << '\n';
      exit(0);
    }
  }
  if (SZ(lol) != 2) {
    cout << 0 << '\n';
    exit(0);
  }
  bool f = false;
  for (auto it : g[lol[0]]) {
    if (it == lol[1]) {
      f = true;
    }
  }
  if (!f) {
    cout << 0 << '\n';
    exit(0);
  }
  vector<int> can;
  for (int iter = 0; iter < 2; iter++) {
    for (int i = 1;i <= (1 << n) - 1; i++) {
      g2[i] = g[i];
    }
    int rt = lol[0];
    int a = -1, b = -1;
    for (auto it : g[rt]) {
      if (it != lol[1]) {
        if (a == -1) {
          a = it;
        }
        else if (b == -1) {
          b = it;
        }
        else {
          cout << 0 << '\n';
          exit(0);
        }
      }
    }
    if (a == -1 || b == -1) {
      cout << 0 << '\n';
      exit(0);
    }
    vector<int> na, nb;
    for (auto it : g[a]) {
      if (it != rt) {
        na.pb(it);
      }
    }
    na.pb((1 << n) - 1);
    for (auto it : g[b]) {
      if (it !=  rt) {
        nb.pb(it);
      }
    }
    nb.pb((1 << n) - 1);
    g[a] = na;
    g[b] = nb;
    g[rt] = {lol[1], (1 << n) - 1};
    g[(1 << n) - 1] = {a, b, rt};
    if (check(rt)) {
      can.pb(rt);
    }
    for (int i = 1; i <= (1 << n) - 1; i++) {
      g[i] = g2[i];
    }  
    swap(lol[0], lol[1]);
  }
  

  cout << SZ(can) << '\n';
  for (auto it : can) {
    cout << it << ' ';
  }
  cout << '\n';
}