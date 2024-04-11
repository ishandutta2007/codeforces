#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		w |= ch == '-';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return w ? -x : x;
}
int n;
ll a[maxn];
int sum[maxn];
int num[maxn][2];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 63; j++) cnt += ((a[i] >> j) & 1);
		sum[i] = sum[i - 1] + cnt;
	}
	long long ans = 0;
	for (int i = n; i >= 1; i--)
	{
		num[i][0] = num[i + 1][0], num[i][1] = num[i + 1][1];
		num[i][sum[i] & 1]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int mx = 0;
		for (int j = i; j <= min(n, i + 130); j++)
		{
			mx = max(mx, sum[j] - sum[j - 1]);
			if((sum[j] - sum[i - 1]) % 2 == 0 && (sum[j] - sum[i - 1]) >= 2 * mx) ans++;
//			printf("%d %d %d %d %d\n", i, j, sum[j] - sum[i - 1], mx, ans);
		}
		if(n > i + 130) ans += num[i + 131][sum[i - 1] & 1];
	}
	printf("%lld\n", ans);
	return 0;
}