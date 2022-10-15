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

const int N = 200005;
char s[N];
int n, k;

void work() {
  scanf("%d%d", &n, &k);
  k++;
  scanf("%s", s + 1);
  int one = 0;
  for (rint i = 1; i <= n; i++) {
    s[i] -= '0';
    one += s[i];
  }
  if (!one) {
    printf("%d\n", (n - 1) / k + 1);
    return ;
  }
  int fir = 1, lst = n;
  while (!s[fir]) fir++;
  while (!s[lst]) lst--;
  int ans = (fir - 1) / k + (n - lst) / k;
  for (rint i = fir + 1; i <= lst; i++) {
    if (s[i] == 1) {
      int L = i - fir;
      if (L >= 2 * k)
        ans += (i - fir - k) / k;
      fir = i;
    }
  }
  printf("%d\n", ans); 
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
  return 0;
}