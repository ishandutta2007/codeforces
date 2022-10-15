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

int a[222222], n, sum, k;

void solve() {
  sum = read(), k = read();
  int mx = 0, id = 0;
  rep(i, 1, k) {
    a[i] = read();
    if (a[i] > mx) mx = a[i], id = i;
  }
  int l = 0, r = 3000;
  while (l < r) {
    int mid = l + r >> 1;
    if (1ll * mid * mid - 1ll * (mid / 2) * (mid / 2) >= sum && 1ll * mid * ((mid + 1) / 2) >= mx) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  n = l;
  print(n, '\n');
  vector<vector<int>> ans(n + 1, vector<int>(n + 1)); 
  vector<pii> A, B, C;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j & 1) {
        if (i & 1) B.pb({i, j});
        else A.pb({i, j});
      } else {
        if (i & 1) C.pb({i, j});
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    int x = i;
    if (i == 1) x = id;
    else if (i == id) x = 1;
    while (a[x]--) {
      if (A.size()) ans[A.back().fir][A.back().sec] = x, A.pop_back();
      else if (B.size()) ans[B.back().fir][B.back().sec] = x, B.pop_back();
      else ans[C.back().fir][C.back().sec] = x, C.pop_back();
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      print(ans[i][j], ' ');
    }
    putchar('\n'); 
  }
}

int main() {
  for (int T = read(); T; T--) solve();
  return 0;
}