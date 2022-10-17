#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define maxn 200005
using namespace std;
int T, n, a[maxn], x, y, z;
long long ans = 0;
void work()
{
	for (int j = 1; j <= n; j++)
	{
		if(a[j] == x)
		{
			ans += abs(y - j);
			y += 2;
		}
		else 
		{
			ans += abs(z - j);
			z += 2;
		}
	}
}
void solve()
{
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] & 1) cnt++;
		else cnt--;
		a[i] &= 1;
	}
	if(cnt != 0 && cnt != 1 && cnt != -1) 
	{
		printf("-1\n");
		return;
	}
	ans = 0;
	x = a[1], y = 1, z = 2;
	if(n & 1)
	{
		if(cnt != 0) x = (cnt + 1) / 2;
		work();
		ans /= 2;
		printf("%d\n", ans);
	}
	else
	{
		x = 1;
		work();
		ans /= 2;
		x = 0, y = 1, z = 2;
		long long tmp = ans;
		ans = 0;
		work();
		tmp = min(tmp, ans / 2);
		printf("%d\n", tmp);
	}
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}