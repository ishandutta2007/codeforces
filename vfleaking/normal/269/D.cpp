#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int MaxN = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

struct board
{
	int l, r, h, f;

	board(){}
	board(const int &_l, const int &_r, const int &_h, const int &_f)
		: l(_l), r(_r), h(_h), f(_f){}
};

inline bool lessH(const board &lhs, const board &rhs)
{
	return lhs.h < rhs.h;
}

inline bool isUnder(const board &a, const board &b)
{
	return max(a.l, b.l) < min(a.r, b.r) && a.h < b.h;
}

int main()
{
	int n, totH;
	static board a[MaxN + 1];

	cin >> n >> totH;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &a[i].h, &a[i].l, &a[i].r);
	a[n].h = totH, a[n].l = -1000000000, a[n].r = 1000000000;

	sort(a, a + n, lessH);

	const int INF = 1000000000;

	map< int, board> ma;
	ma[-INF - 1] = board(-INF - 1, INF + 1, 0, (INF + 1) * 2);
	ma[INF + 1] = board(INF + 1, INF + 2, 0, 1);

	for (int i = 0; i <= n; i++)
	{
		map<int, board>::iterator itL = ma.upper_bound(a[i].l);
		map<int, board>::iterator itR = ma.lower_bound(a[i].r);

		a[i].f = 0;
		for (map<int, board>::iterator it = itL; it != itR; it++)
		{
			map<int, board>::iterator prev = (--it)++;
			map<int, board>::iterator next = (++it)--;
			if (isUnder(it->second, prev->second) && isUnder(prev->second, a[i]))
				continue;
			if (isUnder(it->second, next->second) && isUnder(next->second, a[i]))
				continue;
			relax(a[i].f, min(it->second.f, min(next->first, a[i].r) - max(it->first, a[i].l)));
		}

		map<int, board>::iterator prev = (--itL)++;
		if (!(itL != itR && isUnder(prev->second, itL->second) && isUnder(itL->second, a[i])))
			relax(a[i].f, min(prev->second.f, min(itL->first, a[i].r) - a[i].l));
		board vR = ((--itR)++)->second;

		ma.erase(itL, itR);

		ma[a[i].l] = a[i];
		if (itR->first != a[i].r)
			ma[a[i].r] = vR;

		if (i == n)
			cout << a[i].f << endl;
	}

	return 0;
}