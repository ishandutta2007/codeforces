#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long s64;

const int MaxN = 1000000;
const int MaxM = 1000000;
const int MaxG = 1000000;

inline int gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int main()
{
	s64 nA, nB;
	int aL, bL;
	static char a[MaxN + 1], b[MaxM + 1];

	cin >> nA >> nB;
	scanf("%s", a);
	scanf("%s", b);

	aL = strlen(a);
	bL = strlen(b);

	int g = gcd(aL, bL);

	static s64 res = (s64)aL * bL / g;
	for (char c = 'a'; c <= 'z'; c++)
		for (int p = 0; p < g; p++)
		{
			int cntA = 0;
			for (int i = p; i < aL; i += g)
				if (a[i] == c)
					cntA++;

			int cntB = 0;
			for (int i = p; i < bL; i += g)
				if (b[i] == c)
					cntB++;
			res -= (s64)cntA * cntB;
		}

	cout << res * (nA / (bL / g)) << endl;

	return 0;
}