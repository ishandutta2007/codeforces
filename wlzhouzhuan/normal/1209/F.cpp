#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define mset(s, t) memset(s, t, sizeof(s))

namespace IO {
  const int SIZE = 1 << 20;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  int getc() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
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

const int N = 1300005;
const int mod = 1000000007;

vector<int> adj[N][10];
int d[15], len;
int ans[N], n, m, tot;

int main() {
  memset(ans, -1, sizeof(ans));
  n = read(), m = read(), tot = n;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = i;
    len = 0;
    while (w > 0) d[++len] = w % 10, w /= 10;
    int tmp = u;
    for (int j = len; j > 1; j--) {
      adj[u][d[j]].push_back(++tot);
      u = tot;
    }
    adj[u][d[1]].push_back(v);
    for (int j = len; j > 1; j--) {
      adj[v][d[j]].push_back(++tot);
      v = tot; 
    }
    adj[v][d[1]].push_back(tmp);
  }
  queue<vector<int>> q;
  q.push({1}), ans[1] = 0;
  while (!q.empty()) {
    vector<int> u = q.front(); q.pop();
    for (int dig = 0; dig < 10; dig++) {
      vector<int> zip;
      for (auto it: u) {
        for (auto v: adj[it][dig]) {
          if (ans[v] == -1) {
            ans[v] = (10ll * ans[it] + dig) % mod;
            zip.push_back(v);
          }
        }
      }
      if (!zip.empty()) q.push(zip);
    }
  }
  for (int i = 2; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}

//