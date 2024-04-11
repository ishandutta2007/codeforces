#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxA = 1000000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n, lim;
	static int sumA[MaxA + 1];

	cin >> n >> lim;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		sumA[a]++;
	}

	for (int i = 1; i <= MaxA; i++)
		sumA[i] += sumA[i - 1];

	int res = 1;
	for (int cur = 2; cur <= MaxA; cur++)
	{
		if (cur <= lim + 1)
		{
			if (sumA[cur - 1] == 0)
				res = cur;
			continue;
		}

		int cntAll = 0;
		for (int i = cur; i <= MaxA; i += cur)
			cntAll += sumA[min(i + lim, MaxA)] - sumA[i - 1];
		if (cntAll == n)
			res = cur;
	}

	cout << res << endl;

	return 0;
}