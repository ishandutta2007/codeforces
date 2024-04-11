#include <iostream>
#include <cstdio>
#include <climits>
#include <set>
using namespace std;

const int MaxN = 200000;
const int INF = 1000000000;

struct node
{
	int minVal;
	int delta;
};

node seg[MaxN * 4 + 1];

void seg_set(int p, int pL, int pR, int q, int val)
{
	if (pL == pR)
	{
		seg[p].minVal = val;
		return;
	}

	if (seg[p].delta != 0)
	{
		seg[p << 1 | 0].minVal += seg[p].delta;
		seg[p << 1 | 0].delta  += seg[p].delta;

		seg[p << 1 | 1].minVal += seg[p].delta;
		seg[p << 1 | 1].delta  += seg[p].delta;

		seg[p].delta = 0;
	}

	int pMid = (pL + pR) >> 1;
	if (q <= pMid)
		seg_set(p << 1 | 0, pL, pMid, q, val);
	else
		seg_set(p << 1 | 1, pMid + 1, pR, q, val);
	seg[p].minVal = min(seg[p << 1 | 0].minVal, seg[p << 1 | 1].minVal);
}

void seg_add(int p, int pL, int pR, int qL, int qR, int delta)
{
	if (qL <= pL && pR <= qR)
	{
		seg[p].minVal += delta;
		seg[p].delta  += delta;
		return;
	}

	if (seg[p].delta != 0)
	{
		seg[p << 1 | 0].minVal += seg[p].delta;
		seg[p << 1 | 0].delta  += seg[p].delta;

		seg[p << 1 | 1].minVal += seg[p].delta;
		seg[p << 1 | 1].delta  += seg[p].delta;

		seg[p].delta = 0;
	}

	int pMid = (pL + pR) >> 1;
	if (qL <= pMid)
		seg_add(p << 1 | 0, pL, pMid, qL, qR, delta);
	if (pMid < qR)
		seg_add(p << 1 | 1, pMid + 1, pR, qL, qR, delta);
	seg[p].minVal = min(seg[p << 1 | 0].minVal, seg[p << 1 | 1].minVal);
}
int seg_query(int p, int pL, int pR, int lim)
{
	if (pL == pR)
		return pL;

	if (seg[p].delta != 0)
	{
		seg[p << 1 | 0].minVal += seg[p].delta;
		seg[p << 1 | 0].delta  += seg[p].delta;

		seg[p << 1 | 1].minVal += seg[p].delta;
		seg[p << 1 | 1].delta  += seg[p].delta;

		seg[p].delta = 0;
	}

	int pMid = (pL + pR) >> 1;
	if (seg[p << 1 | 0].minVal <= lim)
		return seg_query(p << 1 | 0, pL, pMid, lim);
	else
		return seg_query(p << 1 | 1, pMid + 1, pR, lim);

}

int main()
{
	int n, lim, d;
	static int a[MaxN + 1];
	static int ar[MaxN + 1], aq[MaxN + 1];

	cin >> n >> lim >> d;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int bestL = n + 1, bestR = 0;

	if (d == 0)
	{
		for (int i = 1, j = 1; i <= n; i = j)
		{
			while (j <= n && a[i] == a[j])
				j++;
			if (j - i - 1 > bestR - bestL)
				bestL = i, bestR = j - 1;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
			ar[i] = (a[i] % d + d) % d, aq[i] = (a[i] - ar[i]) / d;

		seg_add(1, 1, n, 1, n, INF);

		for (int i = 1, j = 1; i <= n; i = j)
		{
			while (j <= n && ar[i] == ar[j])
				j++;

			int qMin_top, qMin_bot;
			static int qMin[MaxN + 1];
			int qMax_top, qMax_bot;
			static int qMax[MaxN + 1];

			qMin[0] = i - 1;
			qMin_top = qMin_bot = 1;

			qMax[0] = i - 1;
			qMax_top = qMax_bot = 1;

			set<int> book;
			for (int p = i, sp = i; p < j; p++)
			{
				while (book.count(a[p]))
				{
					seg_set(1, 1, n, sp, INF), book.erase(a[sp]);
					sp++;
				}
				book.insert(a[p]);

				seg_set(1, 1, n, p, p);
				while (qMin_bot > qMin_top && a[p] < a[qMin[qMin_bot - 1]])
				{
					seg_add(1, 1, n, qMin[qMin_bot - 2] + 1, qMin[qMin_bot - 1], aq[qMin[qMin_bot - 1]]);
					qMin_bot--;
				}
				qMin[qMin_bot++] = p;
				seg_add(1, 1, n, qMin[qMin_bot - 2] + 1, qMin[qMin_bot - 1], -aq[qMin[qMin_bot - 1]]);

				while (qMax_bot > qMax_top && a[p] > a[qMax[qMax_bot - 1]])
				{
					seg_add(1, 1, n, qMax[qMax_bot - 2] + 1, qMax[qMax_bot - 1], -aq[qMax[qMax_bot - 1]]);
					qMax_bot--;
				}
				qMax[qMax_bot++] = p;
				seg_add(1, 1, n, qMax[qMax_bot - 2] + 1, qMax[qMax_bot - 1], aq[qMax[qMax_bot - 1]]);

				int q = seg_query(1, 1, n, p + lim);
				if (p - q > bestR - bestL)
					bestL = q, bestR = p;
			}

			for (int p = i; p < j; p++)
				seg_set(1, 1, n, p, INF);
		}
	}

	cout << bestL << " " << bestR << endl;

	return 0;
}