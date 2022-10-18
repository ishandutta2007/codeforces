#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned u32;

const int MaxN = 100000;
const int MaxHalf = MaxN / 2;

int main()
{
	int n;
	static char s[MaxN + 1];

	cin >> n;
	scanf("%s", s);

	if (n % 2 == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	int half = n >> 1;

	int nL = 0;
	static u32 f[MaxHalf + 1];
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != '?')
			nL++;
		else
		{
			for (int j = i + 1 >> 1, endj = max(i - half + 1, 1); j >= endj; j--)
				f[j] += f[j - 1];
		}
	}

	u32 res = f[half];
	for (int i = 0; i < half - nL; i++)
		res *= 25;
	cout << res << endl;

	return 0;
}