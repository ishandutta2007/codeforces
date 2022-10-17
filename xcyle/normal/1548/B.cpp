#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 200005
using namespace std;
int T, n;
long long a[maxn];
long long d[maxn][25];
long long gcd(long long x, long long y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++) 
	{
		a[i] -= a[i + 1];
		if(a[i] < 0) a[i] = -a[i];
	}
	n--;
	for (int i = n; i >= 1; i--)
	{
		d[i][0] = a[i];
		for (int j = 1; j <= 20; j++)
		{
			if(i + (1 << j) - 1 > n) continue;
			d[i][j] = gcd(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
		}
	}
	int ans = 1;
	long long tmp;
	for (int i = 1; i <= n; i++)
	{
		if(a[i] == 1) continue;
		tmp = a[i];
		int now = i + 1;
		for (int j = 20; j >= 0; j--)
		{
			if(now + (1 << j) - 1 > n) continue;
			if(gcd(tmp, d[now][j]) != 1)
			{
				tmp = gcd(tmp, d[now][j]);
				now += (1 << j);
			}
		}
		ans = max(ans, now - i + 1);
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}