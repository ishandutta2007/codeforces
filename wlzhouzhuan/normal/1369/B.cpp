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

const int N = 100005;
char s[N];
int n;

void solve() {
  scanf("%d%s", &n, s + 1);
  for (rint i = 1; i <= n; i++) s[i] -= '0';
  int fir1 = 1;
  while (fir1 <= n && !s[fir1]) fir1++;
  int lst0 = n;
  while (lst0 >= 1 && s[lst0]) lst0--;
  if (fir1 > lst0) {
    for (rint i = 1; i <= n; i++) printf("%d", s[i]);
    puts("");
    return ;
  }
  for (rint i = 1; i < fir1; i++) printf("%d", s[i]);
  putchar('0');
  for (rint i = lst0 + 1; i <= n; i++) printf("%d", s[i]);
  puts(""); 
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}