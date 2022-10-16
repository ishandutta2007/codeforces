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
int a[N];
int n, k;

int can[N];
bool check(int x) {
  for (rint i = 1; i <= n; i++) can[i] = a[i] <= x;
  int cnt1 = 0, cnt2 = 0;
  for (rint i = 1; i <= n; i++) {
    if (can[i]) {
      cnt1++;
      i++;
      if (i <= n) cnt1++;
    }
  }
  if (cnt1 >= k) return 1;
  cnt2 = 1;
  for (rint i = 2; i <= n; i++) {
    if (can[i]) {
      cnt2++;
      i++;
      if (i <= n) cnt2++;
    }
  }
  return cnt2 >= k;
}

int main() {
  n = read(), k = read();
  for (rint i = 1; i <= n; i++) a[i] = read();
  int l = 1, r = *max_element(a + 1, a + n + 1);
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}