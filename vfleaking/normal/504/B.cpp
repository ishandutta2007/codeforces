#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 200000;

int n;

int bit[MaxN];
inline void bit_add(int p, int v)
{
	if (p == 0)
		bit[p] += v;
	else
	{
		for (int i = p; i < n; i += i & -i)
			bit[i] += v;
	}
}
inline int bit_query(int p)
{
	int res = bit[0];
	for (int i = p; i > 0; i -= i & -i)
		res += bit[i];
	return res;
}

int main()
{
	static int sum[MaxN];

	cin >> n;
	for (int t = 0; t < 2; t++)
	{
		static int a[MaxN];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i < n; i++)
			bit[i] = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			sum[n - 1 - i] += bit_query(a[i]);
			bit_add(a[i], 1);
		}
	}

	for (int i = 0, sh = 0; i < n; i++)
	{
		sum[i] += sh;
		sh = sum[i] / (i + 1);
		sum[i] %= i + 1;
	}

	for (int i = 0; i < n; i++)
		bit[i] = 0;
	for (int i = 0; i < n; i++)
		bit_add(i, 1);

	for (int i = 0; i < n; i++)
	{
		int vL = 0, vR = n;
		while (vL != vR)
		{
			int vM = (vL + vR) >> 1;
			if (bit_query(vM) < sum[n - 1 - i] + 1)
				vL = vM + 1;
			else
				vR = vM;
		}
		printf("%d ", vL);
		bit_add(vL, -1);
	}
	printf("\n");

	return 0;
}