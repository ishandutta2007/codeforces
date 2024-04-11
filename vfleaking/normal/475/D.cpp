#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxLogN = 17;

int gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int n;
int preLog2[MaxN + 1];
int st[MaxN + 1][MaxLogN + 1];

int query(int l, int r)
{
	int t = preLog2[r - l + 1];
	return gcd(st[l][t], st[r - (1 << t) + 1][t]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &st[i][0]);

	preLog2[1] = 0;
	for (int x = 2; x <= n; x++)
		preLog2[x] = preLog2[x >> 1] + 1;

	for (int i = n; i >= 1; i--)
		for (int j = 0; i + (1 << (j + 1)) - 1 <= n; j++)
			st[i][j + 1] = gcd(st[i][j], st[i + (1 << j)][j]);

	map<int, s64> res;
	for (int i = 1; i <= n; i++)
	{
		for (int p = i, np, val = st[i][0]; p <= n; p = np)
		{
			int le = p + 1, ri = n + 1;
			while (le != ri)
			{
				int mid = (le + ri) >> 1;
				if (query(i, mid) == val)
					le = mid + 1;
				else
					ri = mid;
			}
			np = le;
			res[val] += np - p;
			if (np <= n)
				val = query(i, np);
		}
	}

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int x;
		scanf("%d", &x);
		cout << res[x] << endl;
	}

	return 0;
}