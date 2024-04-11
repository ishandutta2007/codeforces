// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
 
inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
 
const int N = 200005;
vector <int> adj[N];
int vis[N], deg[N], n, k;
int Nums[N], ans;
int tmp[N];
 
void topo() {
  ans = 0;
  queue <int> q;
  for (int i = 1; i <= n; i++) tmp[i] = deg[i];
  for (int u = 1; u <= n; u++) {
    if (tmp[u] == 1) {
      vis[u] = 1;
      deg[u]--;
      for (auto v: adj[u]) {
        deg[v]--;
        Nums[v]++;
      }
    }
  } 
  /*
  for (int i = 1; i <= n; i++) {
    printf("node %d: %d %d\n", i, deg[i], Nums[i]);
  }
  */
  for (int i = 1; i <= n; i++) {
    if (Nums[i] && Nums[i] % k == 0 && deg[i] <= 1) {
      vis[i] = 1;
      q.push(i);
    }
  }
  while (!q.empty()) {
    /*
    printf("-----\n");
    for (int i = 1; i <= n; i++) {
      printf("node %d: %d %d vis = %d\n", i, deg[i], Nums[i], vis[i]);
    }
    */
    int u = q.front(); q.pop();
    //printf("%d\n", u);
    ans += Nums[u] / k;
    for (auto v: adj[u]) {
      Nums[v]++;
      if (!vis[v] && --deg[v] <= 1) {
        if (Nums[v] % k == 0) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && Nums[i]) {
      ans += Nums[i] / k;
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false), cin.tie(0); 
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      Nums[i] = 0;
      deg[i] = 0;
      vis[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v); deg[v]++;
      adj[v].pb(u); deg[u]++;
    }
    if (n == 2) {
      if (k == 1) cout << "1\n";
      else cout << "0\n";
      continue;
    }
    topo();
    cout << ans << '\n';
  }
  return 0;
}