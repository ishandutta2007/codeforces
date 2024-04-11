#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 10000;
const int L = 12;

inline int lowbit(int x)
{
	return x & -x;
}

int main()
{
	int n;
	static int cntFirst[MaxN], cntSecond[MaxN];
	static int first[MaxN], second[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		static char str[4];
		scanf("%s", str);
		for (int j = 0; j < 3; j++)
		{
			int idx = str[j] - 'a';
			if (idx < L)
				cntFirst[i]++, first[i] |= 1 << idx;
			else
				cntSecond[i]++, second[i] |= 1 << (idx - L);
		}
	}

	static int f[1 << L], g[1 << L];
	for (int status = 0; status < (1 << L); status++)
	{
		for (int i = 0; i < n; i++)
		{
			if ((~status & first[i]) == 0 && second[i] == 0)
				f[status]++;
			if (first[i] == 0 && (~status & second[i]) == 0)
				g[status]++;
		}
	}

	static int f2[1 << L][L], g2[1 << L][L];
	for (int status = 0; status < (1 << L); status++)
		for (int v = 0; v < L; v++)
		{
			for (int i = 0; i < n; i++)
			{
				if ((~status & first[i]) == 0 && (cntSecond[i] == 1 && second[i] == (1 << v)))
					f2[status][v]++;
				if ((cntFirst[i] == 1 && first[i] == (1 << v)) && (~status & second[i]) == 0)
					g2[status][v]++;
			}
		}

	int res = 0;
	for (int status = 0; status < (1 << (L + L)); status++)
	{
		int part1 = status & ((1 << L) - 1), part2 = status >> L;
		int cur = f[part1] + g[part2];

		for (int v = 0; v < L; v++)
			if (part2 >> v & 1)
				cur += f2[part1][v];
		for (int v = 0; v < L; v++)
			if (part1 >> v & 1)
				cur += g2[part2][v];
		res ^= (n - cur) * (n - cur);
	}

	cout << res << endl;

	return 0;
}