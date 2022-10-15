#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second

namespace IO {
  const int SIZE = 1 << 20;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  int getc() {
    return getchar();
    //return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
  }
  int read() {
    int x = 0, f = 0;
    char ch = getc();
    while (!isdigit(ch)) f |= ch == '-', ch = getc();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getc();
    return f ? -x : x;
  }
  template<typename T> void print(T x) {
    if (x < 0) *O++ = '-', x = -x;
    if (x > 9) print(x / 10);
    *O++ = char(x % 10 + '0');
  }
  template<typename T> void print(T x, char opt) {
    print(x), *O++ = opt;
  } 
  void Flush() {
    fwrite(obuf, O - obuf, 1, stdout);
  }
}
using namespace IO;

const int N = 200005;
queue<int> q[3];
vector<int> adj[N];
int a[N], deg[N], n;

int flip(int x) {
  return 3 - x;
}
int solve(int c) { //  c
  for (int i = 1; i <= n; i++) deg[i] = 0;
  for (int i = 1; i <= n; i++) {
    for (auto v: adj[i]) {
      deg[v]++;
    }
  }
  for (int i = 1; i <= n; i++) if (deg[i] == 1) q[a[i]].push(i);
  int dot = n, ans = 0;
  while (dot > 0) {
    c = flip(c), ans++;
    while (q[0].size() + q[c].size()) {
      int u;
      if (q[0].size()) u = q[0].front(), q[0].pop();
      else u = q[c].front(), q[c].pop();
      dot--;
      for (auto v: adj[u]) {
        if (--deg[v] == 1) q[a[v]].push(v);
      }
    }
  } 
  return ans;
}

void solve() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), adj[i].clear();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].push_back(v), adj[v].push_back(u); 
  }
  if (n == 1) {
    puts("1"); return ;
  }
  printf("%d\n", min(solve(1), solve(2)));
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}