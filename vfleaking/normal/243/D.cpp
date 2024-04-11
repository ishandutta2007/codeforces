#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxN = 1000;
const int MaxLN = (MaxN + 1) * (MaxN + 1);

inline int getint()
{
	char c;
	while (c = getchar(), '0' > c || c > '9');

	int res = c - '0';
	while (c = getchar(), '0' <= c && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}
template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

struct node
{
	int tag_max;
	int valMin;
};
node seg[MaxLN * 4 + 1];

void seg_tag_max(int p, int val)
{
	relax(seg[p].tag_max, val);
	relax(seg[p].valMin, val);
}
void seg_tag_down(int p)
{
	seg_tag_max(p << 1 | 0, seg[p].tag_max);
	seg_tag_max(p << 1 | 1, seg[p].tag_max);
	seg[p].tag_max = 0;
}
void seg_upd(int p)
{
	seg[p].valMin = min(seg[p << 1 | 0].valMin, seg[p << 1 | 1].valMin);
}
void seg_cover(int p, int pL, int pR, int qL, int qR, int val)
{
	if (qL <= pL && pR <= qR)
	{
		seg_tag_max(p, val);
		return;
	}
	seg_tag_down(p);
	int pM = (pL + pR) >> 1;

	if (qL < pM)
		seg_cover(p << 1 | 0, pL, pM, qL, qR, val);
	if (pM < qR)
		seg_cover(p << 1 | 1, pM, pR, qL, qR, val);
	seg_upd(p);
}
int seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && pR <= qR)
		return seg[p].valMin;
	seg_tag_down(p);
	int pM = (pL + pR) >> 1;

	int res = INT_MAX;
	if (qL < pM)
		tension(res, seg_query(p << 1 | 0, pL, pM, qL, qR));
	if (pM < qR)
		tension(res, seg_query(p << 1 | 1, pM, pR, qL, qR));
	return res;
}

int main()
{
	int n, vx, vy;
	static int a[MaxN][MaxN];

	cin >> n >> vx >> vy;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			a[x][y] = getint();

	if (vx < 0)
	{
		for (int x = 0; x < n - 1 - x; x++)
			for (int y = 0; y < n; y++)
				swap(a[x][y], a[n - 1 - x][y]);
		vx = -vx;
	}
	if (vy < 0)
	{
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n - 1 - y; y++)
				swap(a[x][y], a[x][n - 1 - y]);
		vy = -vy;
	}

	int seqL_n = 0;
	static int seqL[MaxLN];
	for (int x = 0; x <= n; x++)
		for (int y = 0; y <= n; y++)
			seqL[seqL_n++] = x * vy - y * vx;
	sort(seqL, seqL + seqL_n);
	seqL_n = unique(seqL, seqL + seqL_n) - seqL;

	s64 res = 0;
	for (int cx = 0; cx < n; cx++)
		for (int cy = 0; cy < n; cy++)
		{
			int qL = lower_bound(seqL, seqL + seqL_n, cx * vy - (cy + 1) * vx) - seqL;
			int qR = lower_bound(seqL, seqL + seqL_n, (cx + 1) * vy - cy * vx) - seqL;
			int cur = seg_query(1, 0, seqL_n, qL, qR);
			res += max(a[cx][cy] - cur, 0);
			seg_cover(1, 0, seqL_n, qL, qR, a[cx][cy]);
		}

	cout << res << endl;

	return 0;
}