#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 2020;
int n;
ll a[N][N];

bool check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] <= 0)
				return false;
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[0][i];
	for (int i = 0; i < n; i++)
	{
		ll cur = sum;
		for (int j = 0; j < n; j++)
			cur -= a[i][j];
		if (cur != 0) return false;
		cur = sum;
		for (int j = 0; j < n; j++)
			cur -= a[j][i];
		if (cur != 0) return false;
	}
	ll cur = sum;
	for (int i = 0; i < n; i++)
		cur -= a[i][i];
	if (cur != 0) return false;
	cur = sum;
	for (int i = 0; i < n; i++)
		cur -= a[i][n - 1 - i];
	if (cur != 0) return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &a[i][j]);
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	bool ok = 1;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		ok &= (a[0][i] > 0);
		sum += a[0][i];
	}
	if (!ok)
	{
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[1][i];
	}
	for (int x = 0; x < n; x++)
	{
		int y = -1;
		ll cur = sum;
		for (int i = 0; i < n; i++)
		{
			if (a[x][i] == 0)
				y = i;
			else
				cur -= a[x][i];
		}
		if (y != -1)
		{
			a[x][y] = cur;
			if (check())
				printf("%lld\n", cur);
			else
				printf("-1\n");
			return 0;
		}
	}
	throw;

	return 0;
}