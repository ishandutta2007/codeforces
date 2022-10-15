// Author: wlzhouzhuan
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

const int N = 300005;
char a[N], b[N];
int n;

int pre[N];
void solve(char *a) {
  for (int i = 1; i <= n; i++) {
    if (a[i] == '1') pre[i] = pre[i - 1] + 1;
    else pre[i] = pre[i - 1] - 1; 
  }
  int turn = 0;
  for (int i = n; i >= 1; i--) {
    a[i] = (a[i] - '0') ^ turn + '0';
    if (pre[i] == 0 && a[i] == '1') {
      turn ^= 1;
      a[i] = '0';
    }
  }
} 
void work() {
  scanf("%d%s%s", &n, a + 1, b + 1);
  solve(a), solve(b);
  for (int i = 1; i <= n; i++) if (a[i] != b[i]) return puts("NO"), void();
  puts("YES");
}

int main() {
  int T = read();
  while (T--) work();
  return 0;
}