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

const int N = 100002;
char a[N];
long long cnt[26][26], ans = 0ll; 
int suf[N][26];
int n;

int main() {
  scanf("%s", a + 1); n = strlen(a + 1);
  for (rint i = 1; i <= n; i++) a[i] -= 'a';
  for (rint i = n; i >= 1; i--) {
    for (rint j = 0; j < 26; j++) {
      suf[i][j] = suf[i + 1][j] + (a[i] == j);
    }
  }
  for (rint i = n; i >= 1; i--) {
    for (rint j = 0; j < 26; j++) {
      cnt[a[i]][j] += suf[i + 1][j]; 
    }
  }
  for (rint i = 0; i < 26; i++) {
    for (rint j = 0; j < 26; j++) {
      ans = max(ans, cnt[i][j]);
    }
    ans = max(ans, 1ll * suf[1][i]);
  }
  printf("%lld\n", ans);
  return 0;
}