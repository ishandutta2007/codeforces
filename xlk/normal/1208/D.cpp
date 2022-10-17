#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int z[200020];
ll a[200020];
ll c[200020];
void R(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int A(ll x)
{
	int re = 0;
	for (int i = 1 << 20; i > 0; i >>= 1)
	{
		if (re + i <= n && c[re + i] <= x)
		{
			x -= c[re += i];
		}
	}
	return re + 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		R(i, i);
	}
	for (int i = n; i > 0; i--)
	{
		z[i] = A(a[i]);
		R(z[i], -z[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", z[i], i == n ? '\n' : ' ');
	}
	return 0;
}