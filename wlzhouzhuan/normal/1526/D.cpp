// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
char a[N];
int n;

struct Fenwick {
  int c[N];
  void clear(int n) {
    memset(c, 0, 4 * (n + 1));
  }
  void add(int x, int dlt) {
    while (x > 0) {
      c[x] += dlt;
      x ^= x & -x;
    }
  }
  int qry(int x) {
    int ret = 0;
    while (x <= n) {
      ret += c[x];
      x += x & -x;
    }
    return ret;
  }
} bit;

int rec(char s) {
  if (s == 'A') return 1;
  if (s == 'N') return 2;
  if (s == 'T') return 3;
  if (s == 'O') return 4;
}

char anss[N];

void solve() {
  scanf("%s", a + 1), n = strlen(a + 1);
  vector<int> zz[5];
  for (int i = 1; i <= n; i++) zz[rec(a[i])].pb(i);
  int p[5];
  p[1] = 1, p[2] = 2, p[3] = 3, p[4] = 4;
  ll maxx = -1;
  do {
    ll ans = 0;
    bit.clear(n);
    for (int i = 1; i <= 4; i++) {
      for (auto j: zz[p[i]]) {
        ans += bit.qry(j);
        bit.add(j, 1);
      }
    }
    if (ans > maxx) {
      maxx = ans;
      int len = 0;
      for (int i = 1; i <= 4; i++) {
        for (auto j: zz[p[i]]) {
          anss[++len] = p[i];
        }
      }
    }
  } while (next_permutation(p + 1, p + 5));
//  fprintf(stderr, "ans = %d\n", maxx);
  for (int i = 1; i <= n; i++) {
    switch (anss[i]) {
      case 1: putchar('A'); break;
      case 2: putchar('N'); break;
      case 3: putchar('T'); break;
      case 4: putchar('O'); break;
    }
  }
  putchar('\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}