#include <bits/stdc++.h>
using namespace std;

long long a[100005];
long long b[100005];
pair<long long, int> c[100005];

int main()
{
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i].first);
		c[i].second = i;
	}
	sort(c, c + n);

	long long last;

	for (int i = 0; i < n; i++)
	{
		int idx = c[i].second;
		if (i == 0)
		{
			b[idx] = l;
		}
		else
		{
			b[idx] = max(last + 1, l - a[idx]) + a[idx];
		}

		if (b[idx] > r)
		{
			printf("-1\n");
			return 0;
		}

		last = b[idx] - a[idx];
	}

	for (int i = 0; i < n; i++) printf("%lld ", b[i]);
	printf("\n");
}