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
const ll mod = 998244353;
const int N = 5005;
ll a[N], dp[N][N]; 
ll n, m;

void qujian_dp() {
  for (int i = 1; i <= n + 3; i++)
    dp[i][i] = dp[i][i - 1] = 1ll;
    
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      ll left_ans = 0ll, right_ans = 0ll;
      int mxid = i;
      for (int k = i; k <= j; k++)
        if (a[mxid] > a[k]) mxid = k;
      
      //printf("maxid %d\n", mxid); 
      for (int k = i; k <= mxid; k++) {
        left_ans += 1ll * dp[i][k - 1] * dp[k][mxid - 1] % mod;
        left_ans %= mod;
      }
      for (int k = mxid; k <= j; k++) {
        right_ans += 1ll * dp[mxid + 1][k] * dp[k + 1][j] % mod;
        right_ans %= mod; 
      }
      
      dp[i][j] = 1ll * left_ans * right_ans % mod;
      //printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
      //printf("*** %lld %lld\n", left_ans, right_ans);
    }
  }
}

signed main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  qujian_dp();
  printf("%lld\n", dp[1][n]);
  return 0;
}