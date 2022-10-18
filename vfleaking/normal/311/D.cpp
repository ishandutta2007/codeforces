#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

int mod = 95542721;

struct node
{
	int rot;

	int sum[48];
};

int n;
int a[MaxN + 1];

node tr[MaxN * 4 + 1];

inline void tag_rot(const int &p, const int &r)
{
	rotate(tr[p].sum, tr[p].sum + r, tr[p].sum + 48), tr[p].rot = (tr[p].rot + r) % 48;
}

inline void tag_down(const int &p)
{
	if (tr[p].rot != 0)
	{
		tag_rot(p << 1, tr[p].rot);
		tag_rot(p << 1 | 1, tr[p].rot);
		tr[p].rot = 0;
	}
}

inline void update(const int &p)
{
	for (int i = 0; i < 48; i++)
		tr[p].sum[i] = (tr[p << 1].sum[i] + tr[p << 1 | 1].sum[i]) % mod;
}

void build(const int &p, const int &pL, const int &pR)
{
	if (pL == pR)
	{
		tr[p].sum[0] = a[pL] % mod;
		for (int i = 1; i < 48; i++)
		{
			s64 t = tr[p].sum[i - 1];
			tr[p].sum[i] = t * t % mod * t % mod;
		}
		return;
	}
	else
	{
		int pMid = pL + pR >> 1;
		build(p << 1, pL, pMid);
		build(p << 1 | 1, pMid + 1, pR);
		update(p);
	}
}

int query(const int &p, const int &pL, const int &pR, const int &qL, const int &qR)
{
	if (qL <= pL && pR <= qR)
		return tr[p].sum[0];

	tag_down(p);
	
	int pMid = pL + pR >> 1;
	int res = 0;
	if (qL <= pMid)
		res += query(p << 1, pL, pMid, qL, qR);
	if (pMid < qR)
		res += query(p << 1 | 1, pMid + 1, pR, qL, qR);
	return res % mod;
}

void modify(const int &p, const int &pL, const int &pR, const int &qL, const int &qR)
{
	if (qL <= pL && pR <= qR)
	{
		tag_rot(p, 1);
		return;
	}

	tag_down(p);

	int pMid = pL + pR >> 1;
	int res = 0;
	if (qL <= pMid)
		modify(p << 1, pL, pMid, qL, qR);
	if (pMid < qR)
		modify(p << 1 | 1, pMid + 1, pR, qL, qR);
	update(p);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	build(1, 1, n);

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int type, qL, qR;
		scanf("%d %d %d", &type, &qL, &qR);

		if (type == 1)
			printf("%d\n", query(1, 1, n, qL, qR));
		else if (type == 2)
			modify(1, 1, n, qL, qR);
	}

	return 0;
}