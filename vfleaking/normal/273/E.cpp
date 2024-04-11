#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

typedef long long s64;

const int P = 1000000007;

inline int mex(int a, int b)
{
	if (a != 0 && b != 0)
		return 0;
	if (a != 1 && b != 1)
		return 1;
	return 2;
}

const int MaxN = 1000;
const int MaxSegN = 150;

int main()
{
	int n, m;
	cin >> n >> m;

	static int fact[MaxN + 1];
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = (s64)fact[i - 1] * i % P;

	static int preRev[MaxN + 1];
	preRev[1] = 1;
	for (int i = 2; i <= n; i++)
		preRev[i] = (P - (s64)preRev[i % P] * (P / i) % P) % P;

	int seg_n = 0;
	static int segL[MaxSegN];
	static int segV[MaxSegN];

	segL[seg_n] = 1, segV[seg_n] = 0, seg_n++;
	for (int i = 3, j = 0, k = 0; i < m;)
	{
		segL[seg_n] = i, segV[seg_n] = mex(segV[j], segV[k]);
		if (segV[seg_n] != segV[seg_n - 1])
			seg_n++;
		i = min((segL[j + 1] - 1) * 3ll / 2 + 1, segL[k + 1] * 3ll);
		if (i >= m)
			i = m;
		if (segL[j + 1] == i - i / 3)
			j++;
		if (segL[k + 1] == i / 3)
			k++;
	}

	static s64 cnt[3];
	for (int i = 0; i < seg_n; i++)
	{
		int l = segL[i], r = i + 1 < seg_n ? segL[i + 1] : m;
		cnt[segV[i]] += (s64)m * (r - l) - (s64)r * (r - 1) / 2 + (s64)l * (l - 1) / 2;
	}
	for (int i = 0; i < 3; i++)
		cnt[i] %= P;

	static int f[MaxN + 1][4];
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
				f[i][j ^ k] = (f[i][j ^ k] + (s64)f[i - 1][j] * cnt[k]) % P;
	cout << ((s64)f[n][1] + f[n][2] + f[n][3]) % P << endl;

	return 0;
}