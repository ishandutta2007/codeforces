#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int bit_n;
int bit[MaxN * 2 + 1];

void bit_add(int p, int v)
{
	while (p <= bit_n)
		bit[p] += v, p += p & -p;
}
int bit_query(int p)
{
	int res = 0;
	while (p > 0)
		res += bit[p], p -= p & -p;
	return res;
}

int main()
{
	int n;
	static pair<int, int> a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].first, &a[i].second);
		if (a[i].first > a[i].second)
			swap(a[i].first, a[i].second);
	}

	sort(a, a + n);

	bit_n = n * 2;

	static int nI[MaxN];
	static int nO[MaxN];
	fill(bit + 1, bit + bit_n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		nO[i] += i - bit_query(a[i].second);
		nO[i] += bit_query(a[i].first);
		bit_add(a[i].second, 1);
	}
	fill(bit + 1, bit + bit_n + 1, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		nO[i] += (n - 1 - i) - bit_query(a[i].second);
		bit_add(a[i].first, 1);
	}
	fill(bit + 1, bit + bit_n + 1, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		nI[i] = bit_query(a[i].second);
		bit_add(a[i].second, 1);
	}

	s64 res = 0;
	for (int i = 0; i < n; i++)
	{
		res += (s64)nI[i] * nO[i] * 2;
		res += (s64)(nI[i] + nO[i]) * (n - 1 - nI[i] - nO[i]);
	}
	res /= 2;
	res = (s64)n * (n - 1) * (n - 2) / 6 - res;
	cout << res << endl;

	return 0;
}