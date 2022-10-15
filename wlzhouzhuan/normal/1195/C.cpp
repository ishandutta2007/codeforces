%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }


#define int long long
const int N = 1e5 + 5;

int a[N], b[N];
int dp[N][2], n;

signed main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
  }
  
  dp[0][0] = dp[0][1] = 0;
  dp[1][0] = a[1], dp[1][1] = b[1];
  for (int i = 2; i <= n; i++) {
    dp[i][0] = a[i] + max(dp[i - 1][1], max(dp[i-2][0], dp[i-2][1]));
    dp[i][1] = b[i] + max(dp[i - 1][0], max(dp[i-2][0], dp[i-2][1]));
  }
  printf("%lld\n", max(dp[n][0], dp[n][1]));
  return 0;
}