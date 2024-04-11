#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 1005
using namespace std;
const int mo = 998244353;
int n, k, a[maxn];
int sum[maxn][maxn];
int ans = 0;
int work(int t)
{
	sum[0][0] = 1;
	int last = 0, cnt = (t == 0 ? k : min(k, (a[n] - a[1]) / t + 1));
	if(cnt < k) return 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i][0] = 1;
		while(a[i] - a[last + 1] >= t && last + 1 < i) last++;
		for (register int j = 1; j <= cnt; j++)
		{
			sum[i][j] = (sum[i - 1][j] + sum[last][j - 1]) % mo;
		}
	}
//	printf("%d %d\n", t, sum[n][k]);
	return sum[n][k];
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= ((a[n] - a[1]) / (k - 1)); i++)
	{
		ans = (ans + work(i)) % mo;
	}
	printf("%d", ans);
	return 0;
}