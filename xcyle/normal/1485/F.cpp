#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 200005
using namespace std;
const int mo = 1e9 + 7;
int t, n, f[maxn], res[maxn];
long long b[maxn], sum[maxn], tmp[maxn];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		b[0] = 0;
		for (int i = 1; i <= n; i++) 
		{
			scanf("%lld", &b[i]);
			b[i] += b[i - 1];
			tmp[i] = b[i];
		}
		tmp[n + 1] = 0;
		sort(tmp + 1, tmp + n + 2);
		int len = unique(tmp + 1, tmp + n + 2) - tmp - 1;
		for (int i = 0; i <= n; i++)
		{
			b[i] = lower_bound(tmp + 1, tmp + len + 1, b[i]) - tmp;
		}
		for (int i = 1; i <= len; i++) res[i] = 0;
		int temp = 0, ans = 0;
		temp = ans = 1;
		res[b[0]]++;
		for (int i = 1; i <= n; i++)
		{
			f[i] = (temp - res[b[i - 1]] + mo) % mo;
			temp = (temp + f[i]) % mo;
			res[b[i - 1]] = (res[b[i - 1]] + f[i]) % mo; 
			ans = (ans + f[i]) % mo;
//			printf("%d ", f[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}