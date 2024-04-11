#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int ND = 19;
const int M = 6;
const int MaxAdd = 4;

int a[ND + 1];
bool f[ND + 1][MaxAdd + 1];

inline void solve(s64 n)
{
	for (int d = 1; d <= ND; d++)
		a[d] = n % 10, n /= 10;

	for (int d = 0; d <= ND; d++)
		for (int add = 0; add <= MaxAdd; add++)
			f[d][add] = false;

	f[0][0] = true;
	for (int d = 1; d <= ND; d++)
		for (int n4 = 0; n4 <= M; n4++)
			for (int n7 = 0; n4 + n7 <= M; n7++)
			{
				int t = n4 * 4 + n7 * 7;
				int add = (a[d] - t % 10 + 10) % 10;
				t += add;
				if (add > MaxAdd)
					continue;
				f[d][t / 10] |= f[d - 1][add];
			}

	if (!f[ND][0])
	{
		cout << "-1" << endl;
		return;
	}

	int curRest = 0;
	static s64 res[M];
	for (int i = 0; i < M; i++)
		res[i] = 0;
	for (int d = ND; d >= 1; d--)
	{
		curRest = curRest * 10 + a[d];
		bool ok = false;
		for (int n4 = 0; n4 <= M && !ok; n4++)
			for (int n7 = 0; n4 + n7 <= M && !ok; n7++)
			{
				int t = n4 * 4 + n7 * 7;
				int add = curRest - t;
				if (0 > add || add > MaxAdd)
					continue;
				if (!f[d - 1][add])
					continue;
				curRest -= t;
				ok = true;
				for (int i = 0; i < n4; i++)
					res[i] = res[i] * 10 + 4;
				for (int i = n4; i < n4 + n7; i++)
					res[i] = res[i] * 10 + 7;
				for (int i = n4 + n7; i < M; i++)
					res[i] = res[i] * 10;
			}
	}

	for (int i = 0; i < M; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main()
{
	int nCases;
	cin >> nCases;

	while (nCases--)
	{
		s64 n;
		cin >> n;
		solve(n);
	}

	return 0;
}