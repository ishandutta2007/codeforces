// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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

const int N = 1001;
vector<pii> ans;
bitset<N> f[N], g[N];
int n;
bool used[N];

int main() {
  n = read();
  int all = 1;
  for (int i = 0; i < n; i++) {
    int l = read();
    all &= l == n;
    while (l--) {
      int x = read() - 1;
      f[i].set(x);
    }
  }
  if (all) {
    for (int i = 2; i <= n; i++) {
      printf("1 %d\n", i);
    }
    return 0;
  }
  
  bitset<N> leaf, not_leaf;
  leaf.set(), not_leaf.reset();
  
  int edge = 0;
  for (int i = 0; i < n; i++) g[i].set(i);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bitset<N> tmp = f[i] & f[j];
      if (tmp.count() == 2) {
        int u = tmp._Find_first();
        tmp.reset(u);
        int v = tmp._Find_first();
        if (g[u][v]) continue;
        edge++;
        ans.pb({u, v});
        leaf.reset(u), leaf.reset(v);
        not_leaf.set(u), not_leaf.set(v);
        g[u].set(v), g[v].set(u);
      }
    }
  }
//  cerr << edge << '\n';
//  
//  cerr << not_leaf << '\n'; 
//  for (int i = 0; i < n; i++) {
//    cerr << g[i] << '\n';
//  }
  
//  for (int i = 0; i < n; i++) {
//    printf("node[%d]", i);
//    cerr << f[i] << '\n';
//  }
  if (edge == 1) {
    int x = ans[0].fir, y = ans[0].sec;
    for (int i = 0; i < n; i++) if (f[i].count() != n) {
      for (int j = 0; j < n; j++) {
        if (j != x && j != y) {
          if(f[i][j]) ans.pb({j, x});
          else ans.pb({j, y});
        }
      }
      break;
    }
  } else {
    for (int i = 0; i < n; i++) if (leaf[i] && !used[i]) {
      bitset<N> tmp;
      tmp.set();
      for (int j = 0; j < n; j++) {
        if (f[j][i]) tmp &= f[j];
      }
      bitset<N> lf = leaf & tmp, tmq = tmp ^ lf;
      int v = -1;
      for (int j = 0; j < n; j++) {
        if (g[j] == tmq) {
          v = j;
          break;
        }
      }
      assert(v != -1);
      for (int u = 0; u < n; u++) {
        if (lf[u]) {
          ans.pb({u, v});
          used[u] = 1;
        }
      }
    }
  }
  for (auto v: ans) printf("%d %d\n", v.fir + 1, v.sec + 1);
  return 0;
}

/*
5
3 1 2 3
4 1 2 3 4
5 1 2 3 4 5
4 2 3 4 5
3 3 4 5 
*/