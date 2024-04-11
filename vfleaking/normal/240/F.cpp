#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;
const int NLet = 26;

inline bool isOdd(const int &t)
{
	return t & 1;
}

struct seg_node
{
	int cnt[NLet];
	int cov;
};

seg_node seg[MaxN * 4 + 1];

void seg_init()
{
	fill(seg[1].cnt, seg[1].cnt + NLet, 0);
	seg[1].cov = 0;
}
void seg_upd(int p)
{
	for (int c = 0; c < NLet; c++)
		seg[p].cnt[c] = seg[p << 1 | 0].cnt[c] + seg[p << 1 | 1].cnt[c];
}
void seg_tag_cov(int p, int pL, int pR, int c)
{
	seg[p].cov = c;
	fill(seg[p].cnt, seg[p].cnt + NLet, 0);
	seg[p].cnt[c] = pR - pL + 1;
}
void seg_tag_down(int p, int pL, int pR)
{
	int pM = (pL + pR) >> 1;
	if (seg[p].cov != -1)
	{
		seg_tag_cov(p << 1 | 0, pL, pM, seg[p].cov);
		seg_tag_cov(p << 1 | 1, pM + 1, pR, seg[p].cov);
		seg[p].cov = -1;
	}
}
void seg_cover(int p, int pL, int pR, int qL, int qR, int c)
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
	seg_upd(p);
}
void seg_query(int p, int pL, int pR, int qL, int qR, int *cnt)
{
	if (qL <= pL && pR <= qR)
	{
		for (int c = 0; c < NLet; c++)
			cnt[c] += seg[p].cnt[c];
		return;
	}
	seg_tag_down(p, pL, pR);
	int pM = (pL + pR) >> 1;
	if (qL <= pM)
		seg_query(p << 1 | 0, pL, pM, qL, qR, cnt);
	if (pM < qR)
		seg_query(p << 1 | 1, pM + 1, pR, qL, qR, cnt);
}
void seg_print(int p, int pL, int pR)
{
	if (pL == pR)
	{
		int c = find(seg[p].cnt, seg[p].cnt + NLet, 1) - seg[p].cnt;
		putchar(c + 'a');
		return;
	}
	seg_tag_down(p, pL, pR);
	int pM = (pL + pR) >> 1;
	seg_print(p << 1 | 0, pL, pM);
	seg_print(p << 1 | 1, pM + 1, pR);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	static char s[1 + MaxN + 1];
	cin >> n >> m;
	cin >> (s + 1);
	
	seg_init();
	for (int i = 1; i <= n; i++)
		seg_cover(1, 1, n, i, i, s[i] - 'a');
	
	while (m--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		
		static int nEach[NLet];
		fill(nEach, nEach + NLet, 0);
		seg_query(1, 1, n, l, r, nEach);
		
		int nOdd = count_if(nEach, nEach + NLet, isOdd);
		if (nOdd != (r - l + 1) % 2)
			continue;
		if (isOdd(r - l + 1))
		{
			int v;
			for (int i = 0; i < NLet; i++)
				if (isOdd(nEach[i]))
					v = i;
			int mid = (l + r) >> 1;
			seg_cover(1, 1, n, mid, mid, v);
		}
		for (int i = 0, pos = 0; i < NLet; i++)
		{
			nEach[i] >>= 1;
			if (nEach[i] > 0)
			{
				seg_cover(1, 1, n, l + pos, l + pos + nEach[i] - 1, i);
				seg_cover(1, 1, n, r - pos - nEach[i] + 1, r - pos, i);
				pos += nEach[i];
			}
		}
	}

	seg_print(1, 1, n);
	putchar('\n');
	
	return 0;
}