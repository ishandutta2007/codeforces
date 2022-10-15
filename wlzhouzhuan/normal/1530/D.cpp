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
#define poly vector<int>
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


const int N = 200005;
int a[N], b[N], vis[N], who[N];
int n, s;

void solve() {
  n = read();
  rep(i, 1, n) a[i] = b[i] = vis[i] = who[i] = 0;
  s = 0;
  rep(i, 1, n) {
    b[i] = read();
    if (!vis[b[i]]) vis[b[i]] = 1, a[i] = b[i], who[b[i]] = i, s++;
  }
  int p = 1;
  rep(i, 1, n) {
    if (!a[i]) {
      while (vis[p]) ++p;
      vis[p] = 1;
      a[i] = p;
      who[p] = i;
    }
  }
  rep(i, 1, n) if (a[i] == i) {
    int t = who[b[i]];
    swap(a[i], a[t]);
    swap(who[b[i]], who[i]);
  }
  print(s, '\n');
  rep(i, 1, n) print(a[i], " \n"[i == n]);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}