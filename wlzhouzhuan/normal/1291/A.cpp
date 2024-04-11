// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 300001;
char s[N]; 
int n;

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &n, s + 1);
    int ans = 0;
    for (rint i = 1; i <= n; i++) {
      s[i] -= '0';
      ans += s[i];
    }
    if (ans % 2 == 0) {
      int id = -1;
      for (rint i = n; i >= 1; i--) {
        if (s[i] & 1) {
          id = i; break;
        }
      }
      if (id == -1) {
        puts("-1"); continue;
      }
      int pre = 1;
      for (rint i = 1; i <= id; i++) {
        if (pre && s[i] == 0) continue;
        pre = 0;
        printf("%d", s[i]);
      }
      puts("");
      if (pre) puts("0"); 
    } else {
      int id = -1;
      for (rint i = n; i >= 1; i--) {
        if (s[i] & 1) {
          id = i; break;
        }
      }
      if (id == -1) {
        puts("-1"); continue;
      }
      int id2 = -1;
      for (rint i = 1; i < id; i++) {
        if (s[i] & 1) {
          id2 = i; break;
        }
      }
      if (id2 == -1) {
        puts("-1"); continue;
      }
      int pre = 1;
      for (rint i = 1; i <= id; i++) {
        if (i != id2) {
          if (pre && s[i] == 0) continue;
          pre = 0;
          printf("%d", s[i]);
        }
      }
      puts("");
      if (pre) puts("0");
    }
  }
  return 0;
}