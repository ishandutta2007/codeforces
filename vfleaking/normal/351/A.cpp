#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MaxN = 2000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int main()
{
	int n;
	static int a[MaxN * 2];

	cin >> n;
	for (int i = 0; i < n * 2; i++)
	{
		char c;
		while (c = getchar(), c != '.');

		a[i] = 0;
		for (int k = 0; k < 3; k++)
			a[i] = a[i] * 10 + getchar() - '0';
	}

	sort(a, a + n * 2);

	int cntZero = 0;
	while (cntZero < n * 2 && a[cntZero] == 0)
		cntZero++;

	int inh = 0;
	for (int i = cntZero; i < 2 * n; i++)
		inh -= a[i];

	int res = INT_MAX;
	if (cntZero > n)
	{
		for (int i = 0; i <= n * 2 - cntZero; i++)
			tension(res, abs(inh + 1000 * i));
	}
	else
	{
		for (int i = n - cntZero; i <= n; i++)
			tension(res, abs(inh + 1000 * i));
	}

	printf("%d.%03d\n", res / 1000, res % 1000);

	return 0;
}