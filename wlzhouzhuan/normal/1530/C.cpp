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
int a[N], b[N], n;

int calc1(int *a, int need) {
  int chose = need - (need / 4);
  int fre = need - n;
  if (fre >= chose) return chose * 100;
  else {
    int num = fre * 100;
    chose -= fre;
    for (int i = n; i >= n - chose + 1; i--) num += a[i];
    return num;
  }
}
int calc2(int *a, int need) {
  int chose = need - (need / 4);
  chose = min(chose, n);
  int num = 0;
  for (int i = n; i >= n - chose + 1; i--) num += a[i];
  return num;
}

void solve() {
  n = read();
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n) b[i] = read();
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
//  printf("debug %d %d\n", calc(a, 2), calc(b, 2));
  int l = n, r = 1e6;
  while (l < r) {
    int mid = l + r >> 1;
    if (calc1(a, mid) >= calc2(b, mid)) r = mid;
    else l = mid + 1;
  }
  print(l - n, '\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}