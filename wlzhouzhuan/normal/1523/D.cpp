// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

int ansc[61];
char a[200001][61];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int pr[15], sum[1 << 15], n, m, p, ans;

int popcnt(int x) {
  int ret = 0;
  while (x) ret++, x &= x - 1;
  return ret;
}

int main() {
  n = read(), m = read(), p = read();
  rep(i, 0, n - 1) {
    scanf("%s", a[i]);
    rep(j, 0, m - 1) {
      a[i][j] -= '0';
    }
  }
  rep(times, 1, 10) {
    int u = rng() % n;
    p = 0;
    rep(j, 0, m - 1) if (a[u][j]) pr[p++] = j;
    int all = 1 << p;
    rep(st, 0, all - 1) sum[st] = 0;
    rep(i, 0, n - 1) {
      int zip = 0;
      rep(j, 0, p - 1) {
        if (a[i][pr[j]]) {
          zip |= 1 << j;
        }
      }
      sum[zip]++;
    }
    rep(i, 0, p - 1) {
      rep(st, 0, all - 1) {
        if (!((st >> i) & 1)) {
          sum[st] += sum[st ^ 1 << i];
        }
      }
    }
    rep(st, 0, all - 1) {
      if (sum[st] >= (n + 1) / 2 && popcnt(st) > ans) {
        ans = popcnt(st);
        rep(j, 0, m - 1) ansc[j] = 0;
        rep(j, 0, p - 1) if (st >> j & 1) ansc[pr[j]] = 1;
      } 
    }
  }
  rep(j, 0, m - 1) printf("%d", ansc[j]);
  puts("");
  return 0;
}