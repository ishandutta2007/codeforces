#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int main()
{
	int n;
	static int px[MaxN];
	static int py[MaxN];
	static pair<int, int> lx[MaxN];
	static pair<int, int> ly[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &px[i], &py[i]);
		lx[i] = make_pair(px[i], i);
		ly[i] = make_pair(py[i], i);
	}
	sort(lx, lx + n);
	sort(ly, ly + n);
	for (int i = 0; i < n; i++)
		px[lx[i].second] = i;
	for (int i = 0; i < n; i++)
		py[ly[i].second] = i;

	int m = n / 2;

	static bool has[2][2];
	for (int i = 0; i < n; i++)
		has[px[i] >= m][py[i] >= m] = true;

	s64 res = 0;
	if (n % 2 == 0)
	{
		for (int i = 0; i < m; i++)
			res -= lx[i].first, res -= ly[i].first;
		for (int i = m; i < n; i++)
			res += lx[i].first, res += ly[i].first;
		if (has[0][0] && has[0][1])
			res += max(lx[m - 1].first - lx[m].first, ly[m - 1].first - ly[m].first);
	}
	else
	{
		for (int i = 0; i < m; i++)
			res -= lx[i].first, res -= ly[i].first;
		for (int i = m + 1; i < n; i++)
			res += lx[i].first, res += ly[i].first;
		if (has[0][0] && has[0][1] && py[lx[m].second] == m)
			res += max(max(lx[m].first - lx[m + 1].first, ly[m].first - ly[m + 1].first), max(lx[m - 1].first - lx[m].first, ly[m - 1].first - ly[m].first));
	}

	res *= 2;

	cout << res << endl;

	return 0;
}