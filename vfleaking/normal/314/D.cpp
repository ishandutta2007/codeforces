#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

inline int getint()
{
	char c;
	while (c = getchar(), ('0' > c || c > '9') && c != '-');

	if (c != '-')
	{
		int res = c - '0';
		while (c = getchar(), '0' <= c && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
	else
	{
		int res = 0;
		while (c = getchar(), '0' <= c && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
}

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

struct point
{
	int x, y;
};

inline bool cmpByX(const point &lhs, const point &rhs)
{
	return lhs.x < rhs.x;
}

int n;
point po[MaxN];
int preMinY[MaxN], preMaxY[MaxN];
int sufMinY[MaxN], sufMaxY[MaxN];

inline bool check(const s64 &l)
{
	int le = 0, ri = 0;
	for (int i = 0; i < n; i++)
	{
		while (le < n && po[le].x * 2ll + l < po[i].x * 2ll - l)
			le++;
		while (ri < n && po[ri].x * 2ll - l <= po[i].x * 2ll - l)
			ri++;
		s64 yl = INT_MIN, yr = INT_MAX;
		if (le > 0)
			relax(yl, preMaxY[le - 1] * 2ll - l), tension(yr, preMinY[le - 1] * 2ll + l);
		if (ri < n)
			relax(yl, sufMaxY[ri] * 2ll - l), tension(yr, sufMinY[ri] * 2ll + l);
		if (yl <= yr)
			return true;
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = getint(), y = getint();
		po[i].x = x + y, po[i].y = x - y;
	}

	sort(po, po + n, cmpByX);

	preMinY[0] = po[0].y;
	for (int i = 1; i < n; i++)
		preMinY[i] = min(preMinY[i - 1], po[i].y);
	preMaxY[0] = po[0].y;
	for (int i = 1; i < n; i++)
		preMaxY[i] = max(preMaxY[i - 1], po[i].y);

	sufMinY[n - 1] = po[n - 1].y;
	for (int i = n - 2; i >= 0; i--)
		sufMinY[i] = min(sufMinY[i + 1], po[i].y);
	sufMaxY[n - 1] = po[n - 1].y;
	for (int i = n - 2; i >= 0; i--)
		sufMaxY[i] = max(sufMaxY[i + 1], po[i].y);

	s64 le = 0, ri = 2000000000000000ll;
	while (le < ri)
	{
		double mid = le + ri >> 1;
		if (!check(mid))
			le = mid + 1;
		else
			ri = mid;
	}

	cout << fixed << setprecision(7) << (le / 2.0) << endl;

	return 0;
}