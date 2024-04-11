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
/*
0: 
1: 
2:  1
3:  0 
*/
int typ[10];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char opt[5]; int x;
    scanf("%s%d", opt, &x);
    if (opt[0] == '^') {
      for (int j = 0; j < 10; j++) {
        if (x >> j & 1) {
          if (typ[j] == 0) typ[j] = 1;
          else if (typ[j] == 1) typ[j] = 0;
          else if (typ[j] == 2) typ[j] = 3;
          else typ[j] = 2; 
        }
      }
    } else if (opt[0] == '&') {
      for (int j = 0; j < 10; j++) {
        if (!(x >> j & 1)) {
          typ[j] = 3;
        }
      }
    } else if (opt[0] == '|') {
      for (int j = 0; j < 10; j++) {
        if (x >> j & 1) {
          typ[j] = 2;
        }
      }
    }
  }
  int x = 1023, y = 0, z = 0;
  for (int j = 0; j < 10;  j++) {
    if (typ[j] == 1) z ^= 1 << j;
    if (typ[j] == 2) y |= 1 << j;
    if (typ[j] == 3) x ^= 1 << j;
  }
  printf("3\n& %d\n| %d\n^ %d\n", x, y, z);
}