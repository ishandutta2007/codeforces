#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 200200;
const int K = 30;
ll a[N], b[N], c[N];
int n;
ll S;
ll d[K];

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &c[i]);
	S = 0;
	for (int i = 0; i < n; i++)
		S += b[i] + c[i];
	if (S % (2 * n) != 0)
	{
		printf("-1\n");
		return 0;
	}
	S /= 2 * n;
	for (int i = 0; i < n; i++)
	{
		if (S > b[i] + c[i])
		{
			printf("-1\n");
			return 0;
		}
		a[i] = b[i] + c[i] - S;
		if (a[i] % n != 0)
		{
			printf("-1\n");
			return 0;
		}
		a[i] /= n;
		if (a[i] >= (1LL << K))
		{
			printf("-1\n");
			return 0;
		}
		for (int j = 0; j < K; j++)
			if ((a[i] >> j) & 1)
				d[j]++;
	}
	for (int i = 0; i < n; i++)
	{
		ll x = 0, y = 0;
		for (int j = 0; j < K; j++)
		{
			if ((a[i] >> j) & 1)
			{
				x += d[j] << j;
				y += (ll)n << j;
			}
			else
			{
				y += d[j] << j;
			}
		}
		if (x != b[i] || y != c[i])
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");

	return 0;
}