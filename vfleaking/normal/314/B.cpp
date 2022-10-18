#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int MaxAL = 100;
const int MaxBL = 100;

const int NLetter = 26;

int main()
{
	int aR, bR;
	static char a[1 + MaxAL + 1], b[1 + MaxBL + 1];

	cin >> aR >> bR;
	scanf("%s", a + 1);
	scanf("%s", b + 1);

	int aL = strlen(a + 1), bL = strlen(b + 1);

	static bool bookA[NLetter];
	for (int i = 1; i <= aL; i++)
		bookA[a[i] - 'a'] = true;

	for (int i = 1; i <= bL; i++)
		if (!bookA[b[i] - 'a'])
		{
			cout << 0 << endl;
			return 0;
		}

	static int nextC[MaxAL + 1][NLetter];
	for (int i = 0; i <= aL; i++)
		for (int c = 0; c < NLetter; c++)
		{
			if (!bookA[c])
				nextC[i][c] = -1;
			else
			{
				int j = i + 1;
				while (true)
				{
					if (j > aL)
						j -= aL;
					if (a[j] == 'a' + c)
						break;

					j++;
				}

				nextC[i][c] = j;
			}
		}

	static PII nextB[MaxAL + 1];
	for (int i = 0; i <= aL; i++)
	{
		nextB[i].first = 0, nextB[i].second = i;

		for (int j = 1; j <= bL; j++)
		{
			int k = nextC[nextB[i].second][b[j] - 'a'];
			if (k <= nextB[i].second)
				nextB[i].first++;
			nextB[i].second = k;
		}
	}

	static bool bookV[MaxAL + 1];
	int startC;
	for (startC = 0; !bookV[startC]; startC = nextB[startC].second)
		bookV[startC] = true;

	int inh = 0, inh_cnt = 0;
	for (int i = 0; i != startC; i = nextB[i].second)
	{
		if (inh + nextB[i].first >= aR)
		{
			cout << inh_cnt / bR << endl;
			return 0;
		}
		inh += nextB[i].first, inh_cnt++;
	}

	int cw = 0;
	int c_cnt = 0;
	int ti = startC;
	do
	{
		cw += nextB[ti].first;
		ti = nextB[ti].second;
		c_cnt++;
	}
	while (ti != startC);

	int res = inh_cnt + (aR - inh - 1) / cw * c_cnt;
	int rest = (aR - inh - 1) % cw;
	
	ti = startC;
	do
	{
		if (rest - nextB[ti].first < 0)
			break;
		rest -= nextB[ti].first;
		ti = nextB[ti].second;
		res++;
	}
	while (true);

	res /= bR;

	cout << res << endl;

	return 0;
}