#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;

int main()
{
	int n, m;
	int a_n = 0;
	static pair<int, int> a[MaxM * 2];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int l, r, t;
		scanf("%d %d %d", &l, &r, &t);
		a[a_n++] = make_pair(l, t);
		a[a_n++] = make_pair(r, -t - 1);
	}
	sort(a, a + a_n);

	int b_n = 0;
	static pair<int, int> b[MaxM * 4 + MaxN];

	multiset<int> tS;
	int lastT = -1;
	for (int i = 0, j = 0; i < a_n; i = j)
	{
		while (j < a_n && a[i].first == a[j].first)
			j++;

		for (int k = i; k < j; k++)
		{
			if (a[k].second >= 0)
				tS.insert(a[k].second);
			else
				tS.erase(tS.find(-a[k].second - 1));
		}

		int curT = tS.empty() ? -1 : *tS.begin();
		if (lastT != -1)
			b[b_n++] = make_pair(lastT - a[i].first, 1);
		if (curT != -1)
			b[b_n++] = make_pair(curT - a[i].first, -1);

		lastT = curT;
	}

	static int qres[MaxN];
	for (int i = 0; i < n; i++)
	{
		int q;
		scanf("%d", &q);
		b[b_n++] = make_pair(q, i + 2);
	}
	sort(b, b + b_n);

	int curL = 0, curD = 0;
	for (int i = 0; i < b_n; i++)
	{
		if (i > 0)
			curL += curD * (b[i].first - lastT);
		if (b[i].second <= 1)
			curD += b[i].second;
		else
			qres[b[i].second - 2] = curL;
		lastT = b[i].first;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", qres[i]);

	return 0;
}