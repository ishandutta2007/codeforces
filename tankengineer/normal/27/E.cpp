//27E
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int n;
long long ans, INF, f[11][1005];
bool vis[11][1005];

void dp(const int k, const int n) {
  if (vis[k][n]) return;
  vis[k][n] = true;
  if (n == 1) {
    f[k][n] = 1;
    return;
  }
  if (k == 0) {
    f[k][n] = INF;
    return;
  }
  f[k][n] = INF;
  long long muti = prime[k - 1];
  for (int i = 1; i < n; i++) {
    if (n % (i + 1) == 0) {
      dp(k - 1, n / (i + 1));
      if (log((long double)f[k - 1][n / (i + 1)]) + log((long double)muti) < log((long double)INF)) {
        f[k][n] = min(f[k][n], f[k - 1][n / (i + 1)] * muti);
      } 
    }
    if (log((long double)muti) + log((long double)prime[k - 1]) > log((long double)INF)) return;
    muti *= prime[k - 1];
  }
}

int main() {
  scanf("%d", &n);
  ans = 1 << 30;
  ans *= ans;
  INF = ans << 2;
  for (int i = 1; i <= 10; i++) dp(i, n);
  for (int i = 1; i <= 10; i++) if (vis[i][n]) ans = min(ans, f[i][n]);
  printf("%I64d\n", ans);
  return 0;
}