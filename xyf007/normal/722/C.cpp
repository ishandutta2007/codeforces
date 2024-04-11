#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
long long n, a[100001], fa[100001], sum[100001], order[100001];
stack<long long> ans;
void checkmax(long long &x, long long y)
{
	if (x < y)
	{
		x = y;
	}
}
long long find(long long x)
{
	if (fa[x] == x)
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &order[i]);
	}
	ans.push(0);
	long long maxx = 0;
	for (int i = n; i > 1; i--)
	{
		long long x = order[i];
		if (!fa[x])
		{
			fa[x] = x;
			sum[x] = a[x];
		}
		long long fx = find(x);
		if (x > 1 && fa[x - 1])
		{
			long long fy = find(x - 1);
			if (fx != fy)
			{
				sum[x] += sum[fy];
				sum[fy] = 0;
				fa[fy] = x;
			}
		}
		if (x < n && fa[x + 1])
		{
			long long fy = find(x + 1);
			if (fx != fy)
			{
				sum[x] += sum[fy];
				sum[fy] = 0;
				fa[fy] = x;
			}
		}
		checkmax(maxx, sum[x]);
		ans.push(maxx);
	}
	while (!ans.empty())
	{
		printf("%lld\n", ans.top());
		ans.pop();
	}
	return 0;
}//