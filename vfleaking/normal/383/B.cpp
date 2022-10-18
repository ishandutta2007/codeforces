#include <iostream>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int MaxM = 100000;

struct segment
{
	int top, block;
};

int main()
{
	int n, m;
	static PII a[MaxM];

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = PII(x, y);
	}

	sort(a, a + m);
	int lastX = 0;

	int seg_n = 0;
	static segment seg[MaxM];
	seg[seg_n].top = 1;
	seg[seg_n].block = 2;
	seg_n++;

	for (int i = 0, j = 0; i < m; i = j)
	{
		while (j < m && a[i].first == a[j].first)
			j++;

		if (a[i].first != lastX + 1)
		{
			seg[0].block = n + 1;
			seg_n = 1;
		}

		int tseg_n = 0;
		static segment tseg[MaxM];

		int p = 0;
		for (int k = i; k < j; k++)
		{
			int pTop = -1;
			while (p < seg_n && seg[p].block <= a[k].second)
			{
				if (pTop == -1)
					pTop = seg[p].top;
				p++;
			}
			if (p < seg_n && seg[p].top <= a[k].second)
			{
				if (seg[p].top < a[k].second && pTop == -1)
					pTop = seg[p].top;
				if (pTop != -1)
				{
					tseg[tseg_n].top = pTop;
					tseg[tseg_n].block = a[k].second;
					tseg_n++;
				}

				if (a[k].second + 1 < seg[p].block)
					seg[p].top = a[k].second + 1;
				else
					p++;
			}
			else
			{
				if (pTop != -1)
				{
					tseg[tseg_n].top = pTop;
					tseg[tseg_n].block = a[k].second;
					tseg_n++;
				}
			}
		}
		if (p < seg_n)
		{
			tseg[tseg_n].top = seg[p].top;
			tseg[tseg_n].block = n + 1;
			tseg_n++;
		}

		seg_n = tseg_n;
		copy(tseg, tseg + tseg_n, seg);

		lastX = a[i].first;

		if (seg_n == 0)
		{
			cout << "-1" << endl;
			return 0;
		}
	}

	if (lastX != n)
	{
		seg[0].block = n + 1;
		seg_n = 1;
	}

	if (!(seg[seg_n - 1].top <= n && n < seg[seg_n - 1].block))
		cout << "-1" << endl;
	else
		cout << (n - 1) * 2 << endl;

	return 0;
}