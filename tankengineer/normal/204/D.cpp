#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1000005;
const long long MOD = 1000000007;

int n, k, cnt[2][N];
char s[N];
long long ans, sum, f[N], g[N], ff[N], gg[N], p;

int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  for (int i = 1; i <= n; ++i) {
    cnt[0][i] = cnt[0][i - 1] + (s[i] == 'B');
    cnt[1][i] = cnt[1][i - 1] + (s[i] == 'W');
  }
  f[0] = 1; sum = 1; p = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = s[i] != 'B' ? sum : 0;
    if (s[i] != 'W') {
      sum = (sum + f[i] - f[i - k >= p ? i - k : n + 1] + MOD) % MOD;
    } else {
      sum = f[i] % MOD;
      p = i;
    }  
  }
  for (int i = k; i <= n; ++i) ff[i] = (cnt[1][i] - cnt[1][i - k]) ? 0 : f[i - k];
  g[n + 1] = 1; sum = 1; p = n + 1;
  for (int i = n; i >= k; --i) {
    g[i] = s[i] != 'W' ? sum : 0;
    if (s[i] != 'B') {
      sum = (sum + g[i] - g[i + k <= p ? i + k : 0] + MOD) % MOD;
    } else {
      sum = g[i] % MOD;
      p = i;
    }    
  }  
  for (int i = 1; i <= n - k + 1; ++i) gg[i] = (cnt[0][i + k - 1] - cnt[0][i - 1]) ? 0 : g[i + k];
  ans = 0; sum = 0;
  for (int i = k; i < n - k + 1; ++i) ans = (ans + (sum = (s[i] == 'X' ? sum * 2 % MOD : sum) + ff[i]) % MOD * gg[i + 1]) % MOD;
  printf("%I64d\n", ans);
  return 0;
}