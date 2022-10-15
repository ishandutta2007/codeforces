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

const int N = 105;
char a[N][N];
int n, m, row, col;

char get(int x, int y) {
  x %= 5, y %= 5;
  return 'a' + 5 * x + y;
}

void solve() {
  n = read(), m = read(), row = read();
  col = n * m / 2 - row;
  if (n & 1) {
    row -= m / 2;
    if (row < 0 || row & 1) return puts("NO"), void();
    else {
      assert(row % 2 == 0 && col % 2 == 0);
      for (int i = 1; i <= m; i += 2) a[1][i] = a[1][i + 1] = get(1, i);
      for (int i = 2; i <= n; i += 2) {
        for (int j = 1; j <= m; j += 2) {
          if (col) {
            a[i][j] = a[i + 1][j] = get(i, j);
            a[i][j + 1] = a[i + 1][j + 1] = get(i, j + 1);
            col -= 2;
          } else {
            assert(row);
            a[i][j] = a[i][j + 1] = get(i, j);
            a[i + 1][j] = a[i + 1][j + 1] = get(i + 1, j);
            row -= 2;
          }
        }  
      }
    }
  } else if (m & 1) {
    col -= n / 2;
    if (col < 0 || col & 1) return puts("NO"), void();
    else {
      assert(row % 2 == 0 && col % 2 == 0);
      for (int i = 1; i <= n; i += 2) a[i][1] = a[i + 1][1] = get(1, i);
      for (int i = 1; i <= n; i += 2) {
        for (int j = 2; j <= m; j += 2) {
          if (col) {
            a[i][j] = a[i + 1][j] = get(i, j);
            a[i][j + 1] = a[i + 1][j + 1] = get(i, j + 1);
            col -= 2;
          } else {
            assert(row);
            a[i][j] = a[i][j + 1] = get(i, j);
            a[i + 1][j] = a[i + 1][j + 1] = get(i + 1, j);
            row -= 2;
          }
        }  
      } 
    }
  } else {
    if (col & 1) return puts("NO"), void();
    else {
      assert(row % 2 == 0 && col % 2 == 0);
      for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= m; j += 2) {
          if (col) {
            a[i][j] = a[i + 1][j] = get(i, j);
            a[i][j + 1] = a[i + 1][j + 1] = get(i, j + 1);
            col -= 2; 
          } else {
            assert(row);
            a[i][j] = a[i][j + 1] = get(i, j);
            a[i + 1][j] = a[i + 1][j + 1] = get(i + 1, j);
            row -= 2;
          }
        }  
      }
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%c", a[i][j]);
    }
    puts("");
  }
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}