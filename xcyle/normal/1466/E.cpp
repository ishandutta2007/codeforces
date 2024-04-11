#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstring>
#define maxn 500005
using namespace std;
const long long mo = 1e9 + 7;
int T;
long long n;
long long a[maxn];
long long f[120][2];
long long pow[200];
void solve()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	memset(f, 0ll, sizeof(f));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			f[j][(a[i] >> j) & 1]++;
		} 
	}
	pow[0] = 1;
	for (int i = 1; i <= 150; i++)
	{
		pow[i] = pow[i - 1] * 2 % mo;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		long long cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < 60; j++)
		{
			if((a[i] >> j) & 1) cnt1 = (cnt1 + pow[j] * f[j][1] % mo) % mo;
		}
		for (int j = 0; j < 60; j++)
		{
			if((a[i] >> j) & 1) cnt2 = (cnt2 + pow[j] * n % mo) % mo;
			else cnt2 = (cnt2 + pow[j] * f[j][1] % mo) % mo;
		}
		ans = (ans + cnt1 * cnt2 % mo) % mo;
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}