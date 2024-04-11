#include <bits/stdc++.h>
using namespace std;
int t, n;
long long s;
int l[200020];
int r[200020];
bool ok(int M)
{
	long long c = s;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		c -= l[i];
		if (M <= l[i])
		{
			a.push_back(0);
		}
		else if (M <= r[i])
		{
			a.push_back(M - l[i]);
		}
	}
	sort(a.begin(), a.end());
	if (a.size() < (n + 1) / 2)
	{
		return false;
	}
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		c -= a[i];
	}
	return c >= 0;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%lld", &n, &s);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
		}
		int L = 0, R = 1e9 + 1;
		while (L < R - 1)
		{
			int M = (L + R) / 2;
			if (ok(M))
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		printf("%d\n", L);
	}
	return 0;
}