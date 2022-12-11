#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int mod = (int)1e9;
const int N = (int)2e5;
int a[N];
int f[N];

int add(int a, int b)
{
	return (a + b < mod ? a + b : a + b - mod);
}

int mult(int a, int b)
{
	ll c = (ll)a * (ll)b;
	return (int)(c % (ll)mod);
}

int getSum(int l, int r)
{
	int ans = 0;
	int ind = 0;
	for (int i = l - 1; i < r; i++)
	{
		ans = add(ans, mult(f[ind], a[i]));
		ind++;
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < 10000; i++)
		f[i] = add(f[i - 1], f[i - 2]);

	for (int i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x, v;
			scanf("%d%d", &x, &v);
			a[x - 1] = v;
		}
		else if (t == 2)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", getSum(l, r));
		}
		else
		{
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
			for (int s = l - 1; s < r; s++)
				a[s] = add(a[s], d);
		}
	}

	return 0;
}