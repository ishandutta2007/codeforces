#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1000000007;

const int MaxN = 1000000;

int main()
{
	int n, m, l;
	int al = 0, ar;

	int n_del = 0;

	cin >> n >> m >> l;
	l++;
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		if (v + 1 == u)
			continue;
		if (u - v != l)
		{
			cout << 0 << endl;
			return 0;
		}

		if (!al)
			al = ar = u;
		else if (v >= al)
		{
			cout << 0 << endl;
			return 0;
		}
		else
			ar = u, n_del++;
	}

	static int pow2[MaxN + 1];
	pow2[0] = 1;
	for (int i = 1; i <= n; i++)
		pow2[i] = pow2[i - 1] * 2 % M;

	int res = 0;
	if (al)
	{
		for (int i = max(l, ar - l) + 1; i < al; i++)
			res = (res + pow2[min(n - i, l - 1) - n_del - 1]) % M;
		res = (res + pow2[min(n - al, l - 1) - n_del]) % M;
	}
	else
	{
		res = (res + 1) % M;
		for (int i = l + 1; i <= n; i++)
			res = (res + pow2[min(n - i, l - 1)]) % M;
	}

	cout << res << endl;

	return 0;
}