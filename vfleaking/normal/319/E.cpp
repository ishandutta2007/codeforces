#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1000000000;

const int MaxN = 100000;

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

struct node
{
	vector<int> li;
};
node seg[MaxN * 8 + 1];

int ufs[MaxN + 1];
int aL[MaxN + 1], aR[MaxN + 1];
int myL[MaxN + 1], myR[MaxN + 1];

int ufs_find(int v)
{
	return ufs[v] == v ? v : ufs[v] = ufs_find(ufs[v]);
}

void seg_union(int p, int pL, int pR, int q, int v)
{
	for (vector<int>::iterator it = seg[p].li.begin(); it != seg[p].li.end(); it++)
	{
		int x = ufs_find(*it);
		tension(myL[v], myL[x]);
		relax(myR[v], myR[x]);
		ufs[x] = v;
	}
	seg[p].li.clear();

	if (pL == pR)
		return;

	int pM = (pL + pR) / 2;
	if (q <= pM)
		seg_union(p << 1 | 0, pL, pM, q, v);
	else
		seg_union(p << 1 | 1, pM + 1, pR, q, v);
}
void seg_cover(int p, int pL, int pR, int qL, int qR, int v)
{
	if (qL <= pL && pR <= qR)
	{
		seg[p].li.push_back(v);
		return;
	}
	int pM = (pL + pR) / 2;
	if (qL <= pM)
		seg_cover(p << 1 | 0, pL, pM, qL, qR, v);
	if (pM < qR)
		seg_cover(p << 1 | 1, pM + 1, pR, qL, qR, v);
}

int main()
{
	int n;
	int a_n = 0;
	cin >> n;

	static int q_type[MaxN], q_x[MaxN], q_y[MaxN];
	int seqX_n = 0;
	static int seqX[MaxN * 2];

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &q_type[i], &q_x[i], &q_y[i]);
		if (q_type[i] == 1)
		{
			seqX[seqX_n++] = q_x[i];
			seqX[seqX_n++] = q_y[i];
		}
	}

	sort(seqX, seqX + seqX_n);
	seqX_n = unique(seqX, seqX + seqX_n) - seqX;

	for (int i = 0; i < n; i++)
	{
		int type = q_type[i], x = q_x[i], y = q_y[i];
		if (type == 1)
		{
			x = lower_bound(seqX, seqX + seqX_n, x) - seqX + 1;
			y = lower_bound(seqX, seqX + seqX_n, y) - seqX + 1;

			a_n++;
			ufs[a_n] = a_n;
			aL[a_n] = myL[a_n] = x, aR[a_n] = myR[a_n] = y;

			seg_union(1, 1, seqX_n, x, a_n);
			seg_union(1, 1, seqX_n, y, a_n);
			if (myR[a_n] - myL[a_n] >= 2)
				seg_cover(1, 1, seqX_n, myL[a_n] + 1, myR[a_n] - 1, a_n);
		}
		else
		{
			x = ufs_find(x), y = ufs_find(y);
			if (x == y || (myL[y] <= myL[x] && myR[x] <= myR[y] && (myL[y] != myL[x] || myR[x] != myR[y] || aL[x] != myL[x] || aR[x] != myR[x])))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}