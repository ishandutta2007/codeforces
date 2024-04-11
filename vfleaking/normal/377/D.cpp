#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int MaxN = 100000;

const int MaxR = 300000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

struct worker
{
	int l, v, r;
};

struct message
{
	int delta;
	PII maxVal;

	inline void add(int t)
	{
		delta += t;
		maxVal.first += t;
	}
};

message tr[MaxR * 4 + 1];

void seg_build(const int &p, const int &pL, const int &pR)
{
	tr[p].maxVal.second = pR;
	if (pL == pR)
		return;
	else
	{
		int pMid = (pL + pR) >> 1;
		seg_build(p << 1 | 0, pL, pMid);
		seg_build(p << 1 | 1, pMid + 1, pR);
	}
}
void seg_add(const int &p, const int &pL, const int &pR, const int &qL, const int &qR, const int &delta)
{
	if (qL <= pL && pR <= qR)
	{
		tr[p].add(delta);
		return;
	}

	if (tr[p].delta != 0)
	{
		tr[p << 1 | 0].add(tr[p].delta);
		tr[p << 1 | 1].add(tr[p].delta);
		tr[p].delta = 0;
	}

	int pMid = (pL + pR) >> 1;
	if (qL <= pMid)
		seg_add(p << 1 | 0, pL, pMid, qL, qR, delta);
	if (pMid < qR)
		seg_add(p << 1 | 1, pMid + 1, pR, qL, qR, delta);
	tr[p].maxVal = max(tr[p << 1 | 0].maxVal, tr[p << 1 | 1].maxVal);
}
PII seg_query(const int &p, const int &pL, const int &pR, const int &qL, const int &qR)
{
	if (qL <= pL && pR <= qR)
		return tr[p].maxVal;

	if (tr[p].delta != 0)
	{
		tr[p << 1 | 0].add(tr[p].delta);
		tr[p << 1 | 1].add(tr[p].delta);
		tr[p].delta = 0;
	}

	PII res(-1, -1);

	int pMid = (pL + pR) >> 1;
	if (qL <= pMid)
		relax(res, seg_query(p << 1 | 0, pL, pMid, qL, qR));
	if (pMid < qR)
		relax(res, seg_query(p << 1 | 1, pMid + 1, pR, qL, qR));
	return res;
}

int main()
{
	int n;
	static worker a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &a[i].l, &a[i].v, &a[i].r);

	static vector<int> insA[MaxR + 1];
	static vector<int> delA[MaxR + 2];

	for (int i = 1; i <= n; i++)
		insA[a[i].l].push_back(i), delA[a[i].v + 1].push_back(i);

	int best = 0, bestL = 0, bestR = MaxR;

	seg_build(1, 1, MaxR);

	for (int i = 1; i <= MaxR; i++)
	{
		for (vector<int>::iterator it = insA[i].begin(); it != insA[i].end(); it++)
			seg_add(1, 1, MaxR, a[*it].v, a[*it].r, 1);
		for (vector<int>::iterator it = delA[i].begin(); it != delA[i].end(); it++)
			seg_add(1, 1, MaxR, a[*it].v, a[*it].r, -1);

		PII ret = seg_query(1, 1, MaxR, i, MaxR);
		if (ret.first > best)
			best = ret.first, bestL = i, bestR = ret.second;
	}

	cout << best << endl;
	for (int i = 1; i <= n; i++)
		if (a[i].l <= bestL && bestL <= a[i].v && a[i].v <= bestR && bestR <= a[i].r)
			printf("%d ", i);
	cout << endl;

	return 0;
}