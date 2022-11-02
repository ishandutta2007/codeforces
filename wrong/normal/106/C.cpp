#include<cstdio>
#include<algorithm>

using namespace std;

int dp[1024];

int main()
{
  int n, m, k[11], w[11], c[11];

  scanf("%d%d", &n, &m);
  scanf("%d%d", &w[0], &c[0]);
  k[0] = n;

  for(int i=1; i<=m; ++i) {
    int a, b;
    scanf("%d%d%d%d", &a, &b, &w[i], &c[i]);
    k[i] = a/b;
  }

  for(int i=0; i<=m; ++i)
    for(int j=0; j<k[i]; ++j)
      for(int x=n; x>=w[i]; --x)
	dp[x] = max(dp[x], dp[x-w[i]]+c[i]);
  printf("%d\n", *max_element(dp, dp+n+1));
  return 0;
}