#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxK = 50;
const int MaxN = 100;
const int MaxM = 100;

int k, x, n, m;

s64 nAC[MaxK + 1];
char sC[MaxK + 1], eC[MaxK + 1];

inline int getLim(int l, char s, char e)
{
	if (s != 'A')
		l--;
	if (e != 'C')
		l--;
	return l / 2;
}

inline bool calc()
{
	char cT[] = {'A', 'C', 'O'};

	for (int cTs1 = 0; cTs1 < 3; cTs1++)
		for (int cTe1 = 0; cTe1 < 3; cTe1++)
			for (int cTs2 = 0; cTs2 < 3; cTs2++)
				for (int cTe2 = 0; cTe2 < 3; cTe2++)
				{
					sC[1] = cT[cTs1], eC[1] = cT[cTe1];
					sC[2] = cT[cTs2], eC[2] = cT[cTe2];

					if (n == 1 && sC[1] != eC[1])
						continue;
					if (m == 1 && sC[2] != eC[2])
						continue;

					int limAC1 = getLim(n, sC[1], eC[1]);
					int limAC2 = getLim(m, sC[2], eC[2]);

					for (nAC[1] = 0; nAC[1] <= limAC1; nAC[1]++)
						for (nAC[2] = 0; nAC[2] <= limAC2; nAC[2]++)
						{
							if (n == 2 && sC[1] == 'A' && eC[1] == 'C' && nAC[1] == 0)
								continue;
							if (m == 2 && sC[2] == 'A' && eC[2] == 'C' && nAC[2] == 0)
								continue;

							for (int i = 3; i <= k; i++)
							{
								nAC[i] = nAC[i - 2] + nAC[i - 1] + (eC[i - 2] == 'A' && sC[i - 1] == 'C');
								sC[i] = sC[i - 2];
								eC[i] = eC[i - 1];
							}
							if (nAC[k] == x)
								return true;
						}
				}
	return false;
}

int main()
{
	cin >> k >> x >> n >> m;

	if (!calc())
		cout << "Happy new year!" << endl;
	else
	{
		static char str1[MaxN + 1], str2[MaxM + 1];
		for (int i = 0; i < n; i++)
			str1[i] = 'O';
		str1[0] = sC[1], str1[n - 1] = eC[1];
		for (int i = 0, j = sC[1] == 'A' ? 0 : 1; i < nAC[1]; i++, j += 2)
			str1[j] = 'A', str1[j + 1] = 'C';

		for (int i = 0; i < m; i++)
			str2[i] = 'O';
		str2[0] = sC[2], str2[m - 1] = eC[2];
		for (int i = 0, j = sC[2] == 'A' ? 0 : 1; i < nAC[2]; i++, j += 2)
			str2[j] = 'A', str2[j + 1] = 'C';
		cout << str1 << endl;
		cout << str2 << endl;
	}

	return 0;
}