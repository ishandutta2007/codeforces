#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long s64;
typedef pair<int, int> PII;

const int MaxN = 200000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}
template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n;
	s64 s;
	PII a[MaxN];

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);

	sort(a, a + n);
	
	int tn = 0;
	int p = n - 1;
	while (a[p].second != 0)
		p--;
	for (int i = p, j = p; i < n; i = j)
	{
		while (j < n && a[i].first == a[j].first)
			j++;
		a[tn++] = a[i];
	}
	n = tn;

	int nS = 0;
	static s64 sX[MaxN], sY[MaxN];
	static s64 sK[MaxN], sB[MaxN];

	sX[nS] = 0, sY[nS] = 0, sK[nS] = a[0].first, sB[nS] = 0;
	nS++;

	for (int i = 1; i < n; i++)
	{
		p = upper_bound(sY, sY + nS, a[i].second) - sY - 1;
		s64 stX = (a[i].second - sB[p] + sK[p] - 1) / sK[p];
		if (p + 1 < nS)
			tension(stX, sX[p + 1]);
		s64 stY = sK[p] * stX + sB[p];
		if (p + 1 < nS && stX == sX[p + 1])
			relax(stY, sY[p + 1]);
		stY -= a[i].second;

		s64 curK = a[i].first, curB = stY - curK * stX;
		while (sK[nS - 1] * sX[nS - 1] + sB[nS - 1] < curK * sX[nS - 1] + curB)
			nS--;
		sX[nS] = (sB[nS - 1] - curB) / (curK - sK[nS - 1]) + 1, sY[nS] = curK * sX[nS] + curB, sK[nS] = curK, sB[nS] = curB;
		nS++;
	}

	p = upper_bound(sY, sY + nS, s) - sY - 1;
	s64 res = (s - sB[p] + sK[p] - 1) / sK[p];
	if (p + 1 < nS)
		tension(res, sX[p + 1]);
	cout << res << endl;

	return 0;
}