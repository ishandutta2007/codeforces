#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;

// getint
inline int getint()
{
    char c;
    while (c = getchar(), ('0' > c || c > '9') && c != '-');
    
    if (c != '-')
    {
        int res = c - '0';
        while (c = getchar(), '0' <= c && c <= '9')
            res = res * 10 + c - '0';
        return res;
    }
    else
    {
        int res = 0;
        while (c = getchar(), '0' <= c && c <= '9')
            res = res * 10 + c - '0';
        return -res;
    }
}

struct node
{
	int tag;
};

node tr[MaxN * 4 + 1];

int a[MaxN + 1];
int b[MaxN + 1];

void build(const int &p, const int &pL, const int &pR)
{
	tr[p].tag = -1;
	if (pL == pR)
		return;
	else
	{
		int pMid = pL + pR >> 1;
		build(p << 1, pL, pMid);
		build(p << 1 | 1, pMid + 1, pR);
	}
}
void cover(
		const int &p, const int &pL, const int &pR,
		const int &qL, const int &qR, const int &k)
{
	if (qL <= pL && pR <= qR)
	{
		tr[p].tag = pL - qL + k;
		return;
	}

	int pMid = pL + pR >> 1;
	if (tr[p].tag != -1)
	{
		tr[p << 1].tag = tr[p].tag;
		tr[p << 1 | 1].tag = tr[p].tag + pMid + 1 - pL;
		tr[p].tag = -1;
	}

	if (qL <= pMid)
		cover(p << 1, pL, pMid, qL, qR, k);
	if (pMid < qR)
		cover(p << 1 | 1, pMid + 1, pR, qL, qR, k);
}

inline int query(
		const int &p, const int &pL, const int &pR,
		const int &x)
{
	if (tr[p].tag != -1)
		return a[x - pL + tr[p].tag];
	if (pL == pR)
		return b[x];

	int pMid = pL + pR >> 1;
	if (x <= pMid)
		return query(p << 1, pL, pMid, x);
	else
		return query(p << 1 | 1, pMid + 1, pR, x);
}

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		a[i] = getint();
	for (int i = 1; i <= n; i++)
		b[i] = getint();

	build(1, 1, n);

	while (m--)
	{
		int type = getint();

		if (type == 1)
		{
			int x = getint(), y = getint(), k = getint();
			cover(1, 1, n, y, y + k - 1, x);
		}
		else
		{
			int x = getint();
			printf("%d\n", query(1, 1, n, x));
		}
	}

	return 0;
}