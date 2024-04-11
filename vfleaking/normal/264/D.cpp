#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long s64;

const int MaxN = 1000000;
const int MaxM = 1000000;

inline int toInt(char c)
{
	switch (c)
	{
		case 'R':
			return 0;
		case 'G':
			return 1;
		case 'B':
			return 2;
		default:
			return -1;
	}
}

int main()
{
	int n;
	static char s1[1 + MaxN + 1];
	int m;
	static char s2[1 + MaxM + 1];

	static int cnt[1 + MaxN][3][3];

	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);

	n = strlen(s1 + 1);
	m = strlen(s2 + 1);

	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			cnt[0][x][y] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				cnt[i][x][y] = cnt[i - 1][x][y];
		if (i >= 2)
			cnt[i][toInt(s2[i - 1])][toInt(s2[i])]++;
	}
	for (int i = m + 1; i <= n; i++)
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				cnt[i][x][y] = cnt[i - 1][x][y];

	static int possL[MaxN + 1], possR[MaxN + 1];
	for (int i = 1, j = 1; i <= n; i++)
	{
		possL[i] = j;

		if (j <= m && s1[i] == s2[j])
			j++;
	}
	for (int i = 1, j = 1; i <= n; i++)
	{
		while (j < m && s1[i] != s2[j])
			j++;
		possR[i] = j;
		if (j < m)
			j++;
	}

	s64 res = 0ll;
	for (int i = 1; i <= n; i++)
	{
		if (possL[i] > m)
			continue;
		res += possR[i] - possL[i] + 1;
		if (i >= 2)
		{
			int x = toInt(s1[i]), y = toInt(s1[i - 1]);
			if (x != y)
				res -= cnt[possR[i]][x][y] - cnt[possL[i] - 1][x][y];
		}
	}
	cout << res << endl;

	return 0;
}