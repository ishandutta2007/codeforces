#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxNP = 20;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int n;
int pli_n;
int pli[MaxNP];

int modpow(int a, int m)
{
	int res = 1, t = a % n;
	for (int i = m; i > 0; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * t % n;
		t = (s64)t * t % n;
	}
	return res;
}

bool isGood(int b)
{
	if (b % n == 0)
		return false;
	for (int i = 0; i < pli_n; i++)
		if (modpow(b, (n - 1) / pli[i]) == 1)
			return false;
	return true;
}

int main()
{
	int maxB;
	cin >> n >> maxB;
	
	if (n == 1)
	{
		printf("%d\n", maxB >= 3 ? maxB - 1 : -1);
		return 0;
	}

	n++;

	pli_n = 0;
	int tn = n - 1;
	for (int i = 2; i * i <= tn; i++)
		if (tn % i == 0)
		{
			pli[pli_n++] = i;
			while (tn % i == 0)
				tn /= i;
		}
	if (tn > 1)
		pli[pli_n++] = tn;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			printf("-1\n");
			return 0;
		}

	for (int b = maxB - 1; b >= 2; b--)
		if (isGood(b))
		{
			printf("%d\n", b);
			return 0;
		}
	printf("-1\n");
	return 0;
}