#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 7005
using namespace std;
int n;
long long a[maxn], b[maxn];
int d[maxn], vis[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += b[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if((a[i] & a[j]) != a[i]) d[i]++;
		}
//		printf("%d\n", d[i]);
	}
	int cnt = n;
	while(1)
	{
		int flag = -1;
		for (int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			if(d[i] == cnt - 1)
			{
				flag = i;
				break;
			}
		} 
		if(flag == -1) break;
		cnt--;
		ans -= b[flag];
		vis[flag] = 1;
		for (int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			if((a[i] & a[flag]) != a[i]) d[i]--;
		}
//		for (int i = 1; i <= n; i++) printf("%d ", d[i]);
	}
	printf("%lld\n", ans);
	return 0;
}