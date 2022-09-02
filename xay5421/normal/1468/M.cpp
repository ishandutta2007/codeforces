// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx")
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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
namespace IO {
  const int SIZE = 1 << 20;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  char getc() {
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
    if (O == obuf + SIZE) fwrite(obuf, O - obuf, 1, stdout), O = obuf; 
  }
  template<typename T> void print(T x, char opt) {
    print(x), *O++ = opt;
  } 
  void Flush() {
    fwrite(obuf, O - obuf, 1, stdout);
  }
}
using namespace IO;
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 300005;
const int B = 35;
vector<int> adj[N];
bool vis[N];
int n;
int tmp[N], aux;
unordered_map<ll, int> mp;
void solve() {
  for (int i = n; i >= 1; i--) {
    if (adj[i].size() > B) {
      for (auto v: adj[i]) vis[v] = 1;
      for (int j = 1; j <= n; j++) {
        if (i != j && (j > i || adj[j].size() <= B)) {
          int cnt = 0;
          for (auto v: adj[j]) if (vis[v]) {
            cnt++;
            if (cnt >= 2) {
              printf("%d %d\n", i, j);
              for (auto v: adj[i]) vis[v] = 0;
              return ;
            }
          }
        }
      }
      for (auto v: adj[i]) vis[v] = 0;
    }
  }
  mp.clear();
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() <= B) {
      int len = adj[i].size();
      for (int j = 0; j < len; j++) {
        for (int k = j + 1; k < len; k++) {
          ll x = min(200000ll * adj[i][j] + adj[i][k], 200000ll * adj[i][k] + adj[i][j]);
          if (mp[x]) {
            printf("%d %d\n", mp[x], i);
            return ;
          }
          mp[x] = i;
        }
      }
    }
  }
  puts("-1");
}
int main() {
  int T = read();
  for (; T; T--) {
    n = read();
    aux = 0;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) {
      int m = read();
      adj[i].resize(m);
      for (int j = 0; j < m; j++) {
        adj[i][j] = read();
        tmp[++aux] = adj[i][j];
      }
    }
    
    sort(tmp + 1, tmp + aux + 1);
    aux = unique(tmp + 1, tmp + aux + 1) - tmp - 1;
    for (int i = 1; i <= n; i++) {
      for (auto &v: adj[i]) {
        v = lower_bound(tmp + 1, tmp + aux + 1, v) - tmp;
//        printf("%d ", v);
      }
//      puts("");
    }
    solve();
  }
}