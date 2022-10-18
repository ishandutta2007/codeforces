#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int M = 1000000007;

const int MaxN = 100000;
const int MaxD = 5;

struct node
{
	int tag_cov;
	int sum[MaxD + 1];
};

int preSum[MaxD + 1][MaxN + 1];
int comb[MaxD + 1][MaxD + 1];

int a[MaxN + 1];
node tr[MaxN * 4 + 1];

int seg_res[MaxD + 1];

inline void seg_upd(int p, int pL, int pR)
{
	for (int d = 0; d <= MaxD; d++)
		tr[p].sum[d] = (tr[p << 1 | 0].sum[d] + tr[p << 1 | 1].sum[d]) % M;
}
inline void seg_tag_cov(int p, int pL, int pR, int c)
{
	tr[p].tag_cov = c;
	for (int d = 0; d <= MaxD; d++)
		tr[p].sum[d] = (s64)c * (preSum[d][pR] - preSum[d][pL - 1]) % M;
}
inline void seg_tag_down(int p, int pL, int pR)
{
	int pM = (pL + pR) >> 1;

	if (tr[p].tag_cov != -1)
	{
		seg_tag_cov(p << 1 | 0, pL, pM, tr[p].tag_cov);
		seg_tag_cov(p << 1 | 1, pM + 1, pR, tr[p].tag_cov);
		tr[p].tag_cov = -1;
	}
}

inline void seg_build(int p, int pL, int pR)
{
	tr[p].tag_cov = -1;
	if (pL == pR)
		seg_tag_cov(p, pL, pR, a[pL]);
	else
	{
		int pM = (pL + pR) >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_upd(p, pL, pR);
	}
}
inline void seg_cover(int p, int pL, int pR, int qL, int qR, int c)
{
	if (qL <= pL && pR <= qR)
	{
		seg_tag_cov(p, pL, pR, c);
		return;
	}
	seg_tag_down(p, pL, pR);
	int pM = (pL + pR) >> 1;
	if (qL <= pM)
		seg_cover(p << 1 | 0, pL, pM, qL, qR, c);
	if (pM < qR)
		seg_cover(p << 1 | 1, pM + 1, pR, qL, qR, c);
	seg_upd(p, pL, pR);
}
inline void seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && pR <= qR)
	{
		for (int d = 0; d <= MaxD; d++)
			seg_res[d] = (seg_res[d] + tr[p].sum[d]) % M;
		return;
	}
	seg_tag_down(p, pL, pR);
	int pM = (pL + pR) >> 1;
	if (qL <= pM)
		seg_query(p << 1 | 0, pL, pM, qL, qR);
	if (pM < qR)
		seg_query(p << 1 | 1, pM + 1, pR, qL, qR);
}

int main()
{
	int n, nQ;

	cin >> n >> nQ;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	preSum[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int d = 0, v = 1; d <= MaxD; d++, v = (s64)v * i % M)
			preSum[d][i] = (preSum[d][i - 1] + v) % M;

	for (int i = 0; i <= MaxD; i++)
		for (int j = 0; j <= i; j++)
			comb[i][j] = j == 0 ? 1 : (comb[i - 1][j] + comb[i - 1][j - 1]) % M;

	seg_build(1, 1, n);
	while (nQ--)
	{
		char type;
		int l, r, d;
		cin >> type >> l >> r >> d;

		if (type == '=')
			seg_cover(1, 1, n, l, r, d);
		else
		{
			fill(seg_res, seg_res + d + 1, 0);
			seg_query(1, 1, n, l, r);

			int res = 0;
			for (int i = d; i >= 0; i--)
				res = ((s64)res * (M - l + 1) + (s64)comb[d][i] * seg_res[d - i]) % M;
			cout << res << endl;
		}
	}

	return 0;
}