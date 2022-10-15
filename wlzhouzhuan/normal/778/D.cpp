// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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

const int N = 55;
vector<pii> ans, ans1;
char a[N][N], b[N][N];
int n, m;

/*
LR
LR
*/ 
void Rotate1(char a[N][N], int i, int j) { // 
  ans.pb(make_pair(i, j));
  a[i][j] = 'U', a[i + 1][j] = 'D';
  a[i][j + 1] = 'U', a[i + 1][j + 1] = 'D';
}
/*
UU
DD
*/
void Rotate2(char a[N][N], int i, int j) { //  
  ans.pb(make_pair(i, j));
  a[i][j] = 'L', a[i][j + 1] = 'R';
  a[i + 1][j] = 'L', a[i + 1][j + 1] = 'R';
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] == 'L') {
        int px = i, py = j;
        while (a[px][py] == 'L') {
          if (a[px + 1][py] == 'L') break;
          if (a[px + 1][py] == 'U' && a[px + 1][py + 1] == 'U') {
            Rotate2(a, px + 1, py);
            break;
          }
          px++, py++;
        }
        while (px >= i) {
          Rotate1(a, px, py);
          if (px != i) Rotate2(a, px, py - 1);
          px--, py--;
        }
      }
    }
  }
  ans1 = ans, ans.clear();
  for (int i = 1; i <= n; i++) scanf("%s", b[i] + 1);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (b[i][j] == 'L') {
        int px = i, py = j;
        while (b[px][py] == 'L') {
          if (b[px + 1][py] == 'L') break;
          if (b[px + 1][py] == 'U' && b[px + 1][py + 1] == 'U') {
            Rotate2(b, px + 1, py);
            break;
          }
          px++, py++;
        }
        while (px >= i) {
          Rotate1(b, px, py);
          if (px != i) Rotate2(b, px, py - 1);
          px--, py--;
        }
      }
    }
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", ans1.size() + ans.size());
  for (auto v: ans1) print(v.fir, ' '), print(v.sec, '\n');
  for (auto v: ans) print(v.fir, ' '), print(v.sec, '\n');
  return 0;
}