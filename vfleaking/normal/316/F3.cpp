#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
using namespace std;

const double PI = acos(-1);

const int MaxH = 1600;
const int MaxW = 1600;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int hA, wA;
int a[1 + MaxH + 1][1 + MaxW + 1];

int countRays(int sx, int sy)
{
	int q_n = 0;
	static pair<int, int> q[MaxH * MaxW];
	a[sx][sy] = 0, q[q_n++] = make_pair(sx, sy);
	for (int i = 0; i < q_n; i++)
	{
		pair<int, int> v = q[i];
		int x = v.first, y = v.second;
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
				if (a[x + dx][y + dy])
					a[x + dx][y + dy] = 0, q[q_n++] = make_pair(x + dx, y + dy);
	}

	static bool book[1 + MaxH + 1][1 + MaxW + 1];
	for (int i = 0; i < q_n; i++)
		book[q[i].first][q[i].second] = true;

	vector< pair<int, int> > rays;

	for (int i = 0; i < q_n; i++)
	{
		int v = 0;
		for (int dx = -3; dx <= 3; dx++)
			for (int dy = -3; dy <= 3; dy++)
				v += book[q[i].first + dx][q[i].second + dy];
		if (v <= 15)
		{
			bool ok = true;
			for (int j = 0; j < (int)rays.size(); j++)
				if (abs(q[i].first - rays[j].first) + abs(q[i].second - rays[j].second) <= 3)
					ok = false;
			if (ok)
				rays.push_back(q[i]);
		}
	}

	for (int i = 0; i < q_n; i++)
		book[q[i].first][q[i].second] = false;

	return rays.size();
}

int main()
{
	cin >> hA >> wA;
	for (int x = 1; x <= hA; x++)
		for (int y = 1; y <= wA; y++)
			scanf("%d", &a[x][y]);

	vector<int> res;
	for (int x = 1; x <= hA; x++)
		for (int y = 1; y <= wA; y++)
			if (a[x][y])
				res.push_back(countRays(x, y));
	sort(res.begin(), res.end());

	cout << res.size() << endl;
	for (int i = 0; i < (int)res.size(); i++)
		printf("%d ", res[i]);
	printf("\n");

	return 0;
}