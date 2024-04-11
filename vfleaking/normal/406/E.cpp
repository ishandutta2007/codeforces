#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxM = 100000;

struct bestMsg
{
	int val;
	s64 cnt;

	bestMsg(){}
	bestMsg(const int &_val, const s64 &_cnt)
		: val(_val), cnt(_cnt){}

	inline bestMsg &operator+=(const bestMsg &rhs)
	{
		if (rhs.cnt == 0)
			return *this;
		if (cnt == 0 || rhs.val > val)
			*this = rhs;
		else if (rhs.val == val)
			cnt += rhs.cnt;
		return *this;
	}
};

int n;

bestMsg solve1(int *a, int a_n)
{
	if (a_n < 3)
		return bestMsg(0, 0);
	if (a[0] == a[a_n - 1])
		return bestMsg(0, (s64)a_n * (a_n - 1) * (a_n - 2) / 6);
	int nL = 0, nR = 0;
	while (a[nL] == a[0])
		nL++;
	while (a[a_n - nR - 1] == a[a_n - 1])
		nR++;
	int nM = a_n - nL - nR;
	return bestMsg(2 * (a[a_n - 1] - a[0]), (s64)nL * nR * nM + (s64)nL * (nL - 1) / 2 * nR + (s64)nL * nR * (nR - 1) / 2);
}
bestMsg solve2(int *a, int a_n, int *b, int b_n)
{
	bestMsg res(0, 0);

	static int low[MaxM], up[MaxM];
	for (int i = 0, j = 0; i < a_n; i++)
	{
		while (j < b_n && b[j] < a[i])
			j++;
		low[i] = j;
	}
	for (int i = 0, j = 0; i < a_n; i++)
	{
		while (j < b_n && b[j] <= a[i])
			j++;
		up[i] = j;
	}

	static s64 sumLow[MaxM];
	sumLow[0] = 0;
	for (int i = 0; i < a_n; i++)
		sumLow[i + 1] = sumLow[i] + low[i];

	static int nSame[MaxM];
	for (int i = 0, j = 0; i < b_n; i = j)
	{
		while (j < b_n && b[i] == b[j])
			j++;
		for (int k = i; k < j; k++)
			nSame[k] = j - i;
	}

	for (int i = 0; i < a_n; i++)
		res += bestMsg(n * 2, (s64)up[i] * i - sumLow[i]);

	for (int i = 0; i < a_n; i++)
		if (low[i] > 0)
			res += bestMsg(n * 2 - 2 * a[i] + 2 * b[low[i] - 1], (s64)(a_n - i - 1) * nSame[low[i] - 1]);
	for (int j = 0; j < a_n; j++)
		if (up[j] < b_n)
			res += bestMsg(n * 2 + 2 * a[j] - 2 * b[up[j]], (s64)j * nSame[up[j]]);
	return res;
}

int main()
{
	int m;
	int a_n = 0;
	static int a[MaxM + 1];
	int b_n = 0;
	static int b[MaxM + 1];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, f;
		cin >> s >> f;
		if (s == 0)
			a[a_n++] = f;
		else
			b[b_n++] = f;
	}

	sort(a, a + a_n);
	sort(b, b + b_n);

	bestMsg best(0, 0);
	best += solve1(a, a_n);
	best += solve1(b, b_n);
	best += solve2(a, a_n, b, b_n);
	best += solve2(b, b_n, a, a_n);
	cout << best.cnt << endl;

	return 0;
}