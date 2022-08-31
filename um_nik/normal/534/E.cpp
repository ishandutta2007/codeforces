#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int N = (int)4e5 + 200;
int n, m;
ll ans0;
ll x[N];
int a[N];

ll solve()
{
	if (m == 1) return 0;
	if (m == 2 * n - 2)
	{
		ll p = x[1] - x[0];
		for (int i = 1; i < n; i++)
			if (x[i] - x[i - 1] != p)
				return -1;
		return 2 * (x[n - 1] - x[0]) - p;
	}
	if (a[0] == 0)
	{
		if (a[n - 1] == 0)
		{
			int l = 0;
			while(a[l] == 0) l++;
			int r = n - 1;
			while(a[r] == 0) r--;
			return x[r] - x[l];
		}
		else
		{
			int l = 0;
			while(a[l] == 0) l++;
			int r = l;
			while(r < n - 1 && a[r] == 1) r++;
			return 2 * x[n - 1] - x[l] - x[r];
		}
	}
	else
	{
		if (a[n - 1] == 0)
		{
			int r = n - 1;
			while(a[r] == 0) r--;
			int l = r;
			while(l > 0 && a[l] == 1) l--;
			return x[r] + x[l] - 2 * x[0];
		}
		else
		{
			int l = 1;
			while(a[l] == 2) l++;
			l--;
			int r = n - 2;
			while(a[r] == 2) r--;
			r++;
			return (x[n - 1] - x[0]) + (x[l] - x[0]) + (x[n - 1] - x[r]);
		}
	}
	throw;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &x[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int y;
		scanf("%d", &y);
		y--;
		a[y]++;
	}
	while(m > 2 * n - 2)
	{
		ans0 += 2 * (x[n - 1] - x[0]);
		m -= 2 * n - 2;
		for (int i = 1; i < n - 1; i++)
			a[i] -= 2;
		a[0]--;
		a[n - 1]--;
	}
	ll ans1 = solve();
	if (ans1 == -1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%I64d\n", ans0 + ans1);

	return 0;
}