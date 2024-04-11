// Author: wlzhouzhuan
// 9:57
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
int d[25][N];
char aa[N];
int n, m, len;

int main() {
  n = read(), m = read();
  scanf("%s", aa + 1);
  for (char a = 'a'; a <= 'c'; a++) {
    for (char b = 'a'; b <= 'c'; b++) {
      for (char c = 'a'; c <= 'c'; c++) {
        if (a == b || b == c || a == c) continue;
        ++len;
        for (int i = 1; i <= n; i++) {
          char maybe;
          switch (i % 3) {
            case 0: maybe = a; break;
            case 1: maybe = b; break;
            case 2: maybe = c; break;
          }
          d[len][i] = d[len][i - 1] + (maybe != aa[i]);
        }
      }
    } 
  }  
  while (m--) {
    int l = read(), r = read(), ans = 1e9;
    for (int i = 1; i <= len; i++) ckmin(ans, d[i][r] - d[i][l - 1]);
    print(ans, '\n');
  }
  return 0;
}