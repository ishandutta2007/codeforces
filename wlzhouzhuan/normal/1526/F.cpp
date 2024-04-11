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
int a[N], n;

int ask(int x, int y, int z) {
  printf("? %d %d %d\n", x, y, z), fflush(stdout);
  int t; scanf("%d", &t); return t; 
}

void solve() {
  scanf("%d", &n);
  int A, B;
  for (int i = 1; i <= 13; i++) {
    for (int j = i + 1; j <= 13; j++) {
      for (int k = j + 1; k <= 13; k++) {
        if (ask(i, j, k) <= (n - 4) / 6) {
          A = i, B = j;
          goto end;
        }
      }
    }
  } 
  end: ;
  vector<vector<int>> rnk(n);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (i != A && i != B) {
      int t = ask(A, B, i);
      rnk[t].pb(i);
      if (t > mx) mx = t;
    }
  } 
  int mx1 = rnk[mx][0], mx2;
  if (rnk[mx - 1].size() >= 2) {
    if (ask(mx1, A, rnk[mx - 1][0]) > ask(mx1, A, rnk[mx - 1][1])) {
      swap(rnk[mx - 1][0], rnk[mx - 1][1]);
    }
  }
  mx2 = rnk[mx - 1][0];
  a[mx1] = 1, a[mx2] = 2;
  for (int i = 1; i <= n; i++) {
    if (i != mx1 && i != mx2) {
      a[i] = ask(mx1, mx2, i) + 2;
    }
  }
  if (a[1] > a[2]) {
    for (int i = 1; i <= n; i++) a[i] = n + 1 - a[i];    
  }
  printf("!"); for (int i = 1; i <= n; i++) printf(" %d", a[i]); puts(""), fflush(stdout); 
  int status; scanf("%d", &status); assert(status != -1);
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    solve();
  }
  return 0;
}