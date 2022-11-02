//19B
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, t[2005];
long long c[2005], dp[2005], ans;
bool vis[2005];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %I64d", &t[i], &c[i]);
    t[i]++;
  }
  memset(vis, 0, sizeof(vis));
  memset(dp, 0, sizeof(dp));
  dp[0] = 0; vis[0] = true;
  ans = 1 << 30; ans = ans * ans;
  for (int i = 1; i <= n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (vis[j]) {
        if (j + t[i] >= n) {
          ans = min(ans, dp[j] + c[i]);
        } else if (!vis[j + t[i]] || dp[j + t[i]] > dp[j] + c[i]) {
          vis[j + t[i]] = true;
          dp[j + t[i]] = dp[j] + c[i];
        }
      }
    }
  }      
  
  printf("%I64d\n", ans);
  return 0;
}