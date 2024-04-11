#include <iostream>
#include <cstdio>
using namespace std;

const int M = 60;

const int MaxN = 100000;

int seg[MaxN * 4 + 1][M];

void seg_upd(int p)
{
	for (int i = 0; i < M; i++)
		seg[p][i] = seg[p << 1 | 0][i] + seg[p << 1 | 1][(i + seg[p << 1 | 0][i]) % M];
}
void seg_modify(int p, int pL, int pR, int q, int v)
{
	if (pL == pR)
	{
		for (int i = 0; i < M; i++)
			seg[p][i] = (i % v == 0) + 1;
		return;
	}

	int pM = (pL + pR) >> 1;
	if (q <= pM)
		seg_modify(p << 1 | 0, pL, pM, q, v);
	else
		seg_modify(p << 1 | 1, pM + 1, pR, q, v);
	seg_upd(p);
}
int seg_query(int p, int pL, int pR, int qL, int qR, int s)
{
	if (qL <= pL && pR <= qR)
		return seg[p][s];

	int pM = (pL + pR) >> 1;
	int res = 0;
	if (qL <= pM)
		res = seg_query(p << 1 | 0, pL, pM, qL, qR, s);
	if (pM < qR)
		res = res + seg_query(p << 1 | 1, pM + 1, pR, qL, qR, (s + res) % M);
	return res;
}

int a[MaxN + 1];
void seg_build(int p, int pL, int pR)
{
	if (pL == pR)
	{
		for (int i = 0; i < M; i++)
			seg[p][i] = (i % a[pL] == 0) + 1;
	}
	else
	{
		int pM = (pL + pR) >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_upd(p);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	seg_build(1, 1, n);

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		char type;
		scanf(" %c", &type);
		if (type == 'A')
		{
			int l, r;
			scanf("%d %d", &l, &r);
			r--;
			printf("%d\n", seg_query(1, 1, n, l, r, 0));
		}
		else
		{
			int p, v;
			scanf("%d %d", &p, &v);
			seg_modify(1, 1, n, p, v);
		}
	}

	return 0;
}