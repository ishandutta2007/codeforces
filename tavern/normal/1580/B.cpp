#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int INF;
int fac[maxn];
int binom[maxn][maxn];
int f[maxn][maxn][maxn];

inline int F(int n, int m, int k){
  if(~f[n][m][k])
    return f[n][m][k];
  int &ret = f[n][m][k];
  if(k > 0 && (n < m || n - m + 1 < k))
    return ret = 0;
  if(n == 0){
    return ret = (k == 0);
  }
  if(m == 1){
    ret = (k == 1) * (n > 0) * fac[n];
    return ret;
  }
  long long res = 0;
  for(int i = 0; i <= n - 1; ++i){
    for(int k_ = 0; k_ <= k; ++k_){
      int tmp = 1ll * binom[n - 1][i] * F(i, m - 1, k_) % INF * F(n - 1 - i, m - 1, k - k_) % INF;
      res += tmp;
    }
  }
  return (ret = res % INF);
}

int n, m, k;

int main(){
  //freopen("B.in", "r", stdin);
  
  scanf("%d%d%d%d", &n, &m, &k, &INF);
  memset(f, -1, sizeof(f));
  for(int i = 0; i < maxn; ++i){
    binom[i][0] = 1;
    for(int j = 1; j <= i; ++j)
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % INF;
  }

  fac[0] = 1; for(int i = 1; i < maxn; ++i) fac[i] = 1ll * fac[i - 1] * i % INF;
  printf("%d\n", F(n, m, k));
  return 0;
}