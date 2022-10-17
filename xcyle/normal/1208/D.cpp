#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 200005
using namespace std;
int n, id[maxn], ans[maxn];
long long sum[maxn];
long long t[maxn];
void add(int x, int data)
{
	for (; x <= n; x += (x & (-x))) t[x] += data;
}

int que(long long x)
{
	int now = 0;
	for (int i = 20; i >= 0; i--)
	{
		if(now + (1 << i) > n || x < t[now + (1 << i)]) continue;
		now += (1 << i);
		x -= t[now];
	}
	return now + 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &sum[i]);
	for (int i = 1; i <= n; i++) add(i, i);
	for (int i = n; i >= 1; i--)
	{
		ans[i] = que(sum[i]);
		add(ans[i], -ans[i]);
		
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}