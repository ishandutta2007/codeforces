// Author: wlzhouzhuan
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
vector<int> bck[N], adj[N];
int in[N], typ[N];
int n, m;

int ind[N], zz = 0;
void topo_sort() {
  queue<int> q;
  vector<int> IN(n + 1, 0);
  for (int u = 1; u <= n; u++) {
    for (auto v: adj[u]) {
      IN[v]++;
    }
  }
  zz = 0;
  for (int u = 1; u <= n; u++) {
    if (!IN[u]) {
      q.push(u);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ind[++zz] = u;
    for (auto v: adj[u]) {
      if (--IN[v] == 0) {
        q.push(v);
      }
    }
  }
}
void solve() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    adj[i].clear(), bck[i].clear();
    in[i] = 0, typ[i] = 0;
  } 
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    bck[v].pb(u);
    in[v]++;
    adj[u].pb(v);
  }
  topo_sort();
  
  vector<int> A, B, C;
  for (int _ = 1; _ <= n; _++) {
    int i = ind[_];
    if (!in[i]) { // A 
      A.pb(i);
      typ[i] = 1;
      continue;
    }
    int inA = 0, inB = 0, inC = 0;
    for (auto v: bck[i]) {
      if (typ[v] == 1) inA++;
      else if (typ[v] == 2) inB++;
      else inC++;
    }
    if (inA && !inB) { // B 
      B.pb(i);
      typ[i] = 2;
    } else if (inB) { // C 
      C.pb(i);
      typ[i] = 3; 
    } else { // A
      A.pb(i);
      typ[i] = 1;
    }
  }
  printf("%d\n", C.size());
  for (auto v: C) {
    printf("%d " , v);
  }
  puts("");
}

int main() {
  
  int T = read(); while (T--) solve();
//  solve();
  return 0;
}