// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { a > b && a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { a < b && a = b; }
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
char a[1000005];
int cnt[1000005], n, k;
int qwq[5000005];
int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    scanf("%d%d", &n, &k);
    scanf("%s", a + 1);
    rep(i, 1, n) a[i] = '1' - a[i], cnt[i] = cnt[i - 1] + a[i];
    rep(i, k, n) {
      int rnk = 0;
      int l = i - k + 1, r = max(i - min(k - 1, 19), 1) - 1;
      if (l <= r && cnt[r] - cnt[l - 1] > 0) continue;
      rep(j, max(i - min(k - 1, 19), 1), i) {
        rnk = 2 * rnk + a[j];
      }
      qwq[rnk] = 1;
    }
    int ups = (k <= 20 ? (1 << k) - 1 : 2000000), ok = 0;
    rep(i, 0, ups) {
      if (!qwq[i]) {
        ok = 1;
        puts("YES");
        rep(j, 1, k - 20) putchar('0');
        per(j, 19, 0) {
          if (j < k)
            printf("%d", i >> j & 1);
        } 
        puts("");
        break;
      }
    }
    if (!ok) puts("NO");
    rep(i, k, n) {
      int rnk = 0;
      int l = i - k + 1, r = max(i - min(k - 1, 19), 1) - 1;
      if (l <= r && cnt[r] - cnt[l - 1] > 0) continue;
      rep(j, max(i - min(k - 1, 19), 1), i) {
        rnk = 2 * rnk + a[j];
      }
      qwq[rnk] = 0;
    }
  }
  return 0;
}