#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 2000;
const int MaxL = MaxN * MaxN;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int l = a * b;

	int pli_n = 0;
	static int pli[MaxL];
	static int mu[MaxL + 1];
	static bool isP[MaxL + 1];

	mu[1] = 1;
	fill(isP + 2, isP + l + 1, true);
	for (int i = 2; i <= l; i++)
	{
		if (isP[i])
		{
			pli[pli_n++] = i;
			mu[i] = -1;
		}

		for (int j = 0; j < pli_n && i * pli[j] <= l; j++)
		{
			isP[i * pli[j]] = false;
			if (i % pli[j] == 0)
			{
				mu[i * pli[j]] = 0;
				break;
			}
			else
				mu[i * pli[j]] = -mu[i];
		}
	}

	static int f[MaxL + 1];
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			f[i * j]++;

	static int h[MaxL + 1];
	for (int i = 1; i <= c; i++)
	{
		int cur = 0;
		for (int j = 1; j <= c / i; j++)
			cur += c / i / j;
		cur *= mu[i];
		for (int j = i; j <= l; j += i)
			h[j] += cur;
	}

	int res = 0;
	for (int i = 1; i <= l; i++)
	{
		int curA = 0;
		for (int j = i; j <= l; j += i)
			curA += f[j];
		int curB = h[i];
		res += curA * curB;
	}
	cout << (res & 0x3fffffff) << endl;

	return 0;
}