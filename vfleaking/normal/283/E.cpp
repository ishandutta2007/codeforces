#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxNQ = 100000;

struct node
{
	bool tag_flip;
	int sum;
};

node seg[MaxN * 4 + 1];

inline void seg_tag_flip(int p, int pL, int pR)
{
	seg[p].tag_flip = !seg[p].tag_flip;
	seg[p].sum = pR - pL - seg[p].sum;
}
inline void seg_tag_down(int p, int pL, int pR)
{
	if (seg[p].tag_flip)
	{
		int pM = (pL + pR) >> 1;
		seg_tag_flip(p << 1 | 0, pL, pM);
		seg_tag_flip(p << 1 | 1, pM, pR);
		seg[p].tag_flip = false;
	}
}
inline void seg_upd(int p)
{
	seg[p].sum = seg[p << 1 | 0].sum + seg[p << 1 | 1].sum;
}
void seg_init(int p, int pL, int pR)
{
	if (pL + 1 == pR)
		seg[p].sum = 0;
	else
	{
		int pM = (pL + pR) >> 1;
		seg_init(p << 1 | 0, pL, pM);
		seg_init(p << 1 | 1, pM, pR);
		seg_upd(p);
	}
}
void seg_flip(int p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && pR <= qR)
	{
		seg_tag_flip(p, pL, pR);
		return;
	}
	seg_tag_down(p, pL, pR);
	int pM = (pL + pR) >> 1;
	if (qL < pM)
		seg_flip(p << 1 | 0, pL, pM, qL, qR);
	if (pM < qR)
		seg_flip(p << 1 | 1, pM, pR, qL, qR);
	seg_upd(p);
}
int seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && pR <= qR)
		return seg[p].sum;
	seg_tag_down(p, pL, pR);
	int res = 0;
	int pM = (pL + pR) >> 1;
	if (qL < pM)
		res += seg_query(p << 1 | 0, pL, pM, qL, qR);
	if (pM < qR)
		res += seg_query(p << 1 | 1, pM, pR, qL, qR);
	return res;
}

int main()
{
	int n, nQ;
	static int a[MaxN];
	static pair<int, int> qu[MaxN];

	cin >> n >> nQ;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	for (int i = 0; i < nQ; i++)
	{
		scanf("%d %d", &qu[i].first, &qu[i].second);
		qu[i].first = lower_bound(a, a + n, qu[i].first) - a;
		qu[i].second = upper_bound(a, a + n, qu[i].second) - a;
	}

	static int deg[MaxN + 1];
	sort(qu, qu + nQ);
	seg_init(1, 0, n);
	for (int i = 0, j = 0; i < n - 1; i++)
	{
		while (j < nQ && qu[j].first == i)
		{
			if (qu[j].first < qu[j].second)
				seg_flip(1, 0, n, qu[j].first, qu[j].second);
			j++;
		}
		deg[i] += seg_query(1, 0, n, i + 1, n);
	}

	for (int i = 0; i < nQ; i++)
		swap(qu[i].first, qu[i].second);
	sort(qu, qu + nQ);
	reverse(qu, qu + nQ);
	seg_init(1, 0, n);
	for (int i = n - 1, j = 0; i >= 1; i--)
	{
		while (j < nQ && qu[j].first == i + 1)
		{
			if (qu[j].second < qu[j].first)
				seg_flip(1, 0, n, qu[j].second, qu[j].first);
			j++;
		}
		deg[i] += i - seg_query(1, 0, n, 0, i);
	}

	s64 res = (s64)n * (n - 1) * (n - 2) / 6;
	for (int i = 0; i < n; i++)
		res -= (s64)deg[i] * (deg[i] - 1) / 2;

	cout << res << endl;

	return 0;
}