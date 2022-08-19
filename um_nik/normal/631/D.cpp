#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

const int N = 400400;
int n, m;
ll a[N][2];
ll b[N][2];
ll s[N][2];
int z[N];

void read(int &p, ll d[N][2])
{
	int sz = 0;
	while(p--)
	{
		ll x;
		char c;
		scanf("%lld-%c", &x, &c);
		ll t = (ll)c;
		if (sz > 0 && d[sz - 1][1] == t)
			d[sz - 1][0] += x;
		else
		{
			d[sz][0] = x;
			d[sz][1] = t;
			sz++;
		}
	}
	p = sz;
	return;
}

void solve1()
{
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][1] != b[0][1]) continue;
		ans += max(0LL, a[i][0] - b[0][0] + 1);
	}
	printf("%lld\n", ans);
	return;
}
void solve2()
{
	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i][1] != b[0][1] || a[i + 1][1] != b[1][1]) continue;
		if (a[i][0] >= b[0][0] && a[i + 1][0] >= b[1][0])
			ans++;
	}
	printf("%lld\n", ans);
	return;
}

void calcZ(int k)
{
	int l = 0, r = 0;
	for (int i = 1; i < k; i++)
	{
		if (i < r)
			z[i] = min(z[i - l], r - i);
		while(i + z[i] < k && s[i + z[i]][0] == s[z[i]][0] && s[i + z[i]][1] == s[z[i]][1])
			z[i]++;
		if (i + z[i] > r)
		{
			r = i + z[i];
			l = i;
		}
	}
	return;
}
void solve()
{
	int k = 0;
	for (int i = 1; i < m - 1; i++)
	{
		s[k][0] = b[i][0];
		s[k][1] = b[i][1];
		k++;
	}
	s[k][0] = s[k][1] = -1;
	k++;
	for (int i = 0; i < n; i++)
	{
		s[k][0] = a[i][0];
		s[k][1] = a[i][1];
		k++;
	}
	calcZ(k);
	ll ans = 0;
	for (int i = 0; i + m <= n; i++)
	{
		if (a[i][1] != b[0][1] || a[i + m - 1][1] != b[m - 1][1]) continue;
		if (a[i][0] < b[0][0] || a[i + m - 1][0] < b[m - 1][0]) continue;
		if (z[m + i] >= m - 2)
			ans++;
	}
	printf("%lld\n", ans);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	read(n, a);
	read(m, b);

	/*
	for (int i = 0; i < n; i++)
		printf("(%lld %lld) ", a[i][0], a[i][1]);
	printf("\n");
	for (int i = 0; i < m; i++)
		printf("(%lld %lld) ", b[i][0], b[i][1]);
	printf("\n");
	*/

	if (m == 1)
		solve1();
	else if (m == 2)
		solve2();
	else
		solve();

	return 0;
}