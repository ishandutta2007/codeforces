#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 20;

s64 invCnt[MaxN + 1][2];

void build(int dep, int *a, int n)
{
	if (n == 1)
		return;

	int m = n / 2;
	build(dep + 1, a, m);
	build(dep + 1, a + m, m);

	int out_n = 0;
	static int type[1 << MaxN];
	static int out[1 << MaxN];

	int i = 0, j = m;
	while (i < m || j < n)
	{
		if (i < m && (j == n || a[i] < a[j]))
			type[out_n] = 0, out[out_n++] = a[i++];
		else
			type[out_n] = 1, out[out_n++] = a[j++];
	}

	for (int i = 0, j = 0, r = 0; i < out_n; i++)
	{
		while (j < out_n && out[j] < out[i])
		{
			if (type[j] == 1)
				r++;
			j++;
		}

		if (type[i] == 0)
			invCnt[dep][0] += r;
	}
	for (int i = 0, j = 0, r = 0; i < out_n; i++)
	{
		while (j < out_n && out[j] < out[i])
		{
			if (type[j] == 0)
				r++;
			j++;
		}

		if (type[i] == 1)
			invCnt[dep][1] += r;
	}

	copy(out, out + out_n, a);
}

int main()
{
	int n;
	static int a[1 << MaxN];

	cin >> n;
	for (int i = 0; i < (1 << n); i++)
		scanf("%d", &a[i]);

	build(0, a, 1 << n);

	static bool revB[MaxN + 1];
	int m;
	cin >> m;
	while (m--)
	{
		int q;
		scanf("%d", &q);

		q = n - q;
		revB[q] = !revB[q];

		s64 res = 0;
		bool b = false;
		for (int i = 0; i < n; i++)
		{
			b ^= revB[i];
			res += invCnt[i][b];
		}
		printf("%I64d\n", res); //!!!!
	}

    return 0;
}