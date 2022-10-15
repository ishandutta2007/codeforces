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
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
#define fir first
#define sec second

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

char str[15][15], ans[15];
int n, m;

bool check() {
  for (rint i = 1; i <= n; i++) {
    int diff = 0;
    for (rint j = 1; j <= m; j++) {
      if (str[i][j] != ans[j]) {
        diff++;
      }
    }
    if (diff > 1) return 0;
  }
  return 1;
}

void work() {
  scanf("%d%d", &n, &m);
  for (rint i = 1; i <= n; i++) {
    scanf("%s", str[i] + 1);
  }
  for (rint i = 1; i <= m; i++) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      memcpy(ans, str[1], sizeof(str[1]));
      ans[i] = ch;
      if (check()) {
        for (rint j = 1; j <= m; j++) {
          printf("%c", ans[j]);
        }
        puts("");
        return ;
      }
    }
  }
  puts("-1");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
  return 0; 
}