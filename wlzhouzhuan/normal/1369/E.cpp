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
#define fir first
#define sec second

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

vector <pii> to[N]; 
int s[N], w[N], n, m;
int x[N], y[N];
int vis[N], used[N];

int main() {
  n = read(), m = read();
  for (rint i = 1; i <= n; i++) w[i] = read();
  for (rint i = 1; i <= m; i++) {
    x[i] = read(), y[i] = read();
    s[x[i]]++, s[y[i]]++;
    to[x[i]].pb(make_pair(y[i], i));
    to[y[i]].pb(make_pair(x[i], i));
  }
  
  queue <int> q;
  vector <int> ans;
  for (rint i = 1; i <= n; i++) {
    if (s[i] <= w[i]) {
      used[i] = 1;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v: to[u]) {
      if (!vis[v.sec]) {
        vis[v.sec] = 1;
        ans.pb(v.sec);
      }
      s[v.fir]--;
      if (!used[v.fir] && s[v.fir] <= w[v.fir]) {
        used[v.fir] = 1;
        q.push(v.fir);
      }
    }
  }
  if (ans.size() < m) {
    puts("DEAD"); exit(0);
  }
  puts("ALIVE");
  reverse(ans.begin(), ans.end());
  for (auto v: ans) printf("%d ", v);
  puts("");
  return 0;
}