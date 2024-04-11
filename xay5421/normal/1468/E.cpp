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

int main() {
  int T = read();
  while (T--) {
    int a[4];
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        int cnt[4] = {0};
        cnt[i] = cnt[j] = 1;
        int k = 0, t = 0;
        while (cnt[k]) k++;
        cnt[k] = 1;
        while (cnt[t]) t++;
        cnt[t] = 1;
        ans = max(ans, min(a[i], a[j]) * min(a[k], a[t]));
      }
    }
    printf("%d\n", ans);
  }
}