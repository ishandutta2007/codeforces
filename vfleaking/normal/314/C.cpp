#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int Mod = 1000000007;

const int MaxN = 100000;
const int MaxA = 1000000;

const int MaxLogA = 20;

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
	int sum;
	node *lc, *rc;
};
node pool[MaxN * (MaxLogA + 1)], *tail = pool;

inline node *seg_add(node *p, const int &pL, const int &pR, const int &key, const int &val)
{
	node *np = tail++;
	if (p)
		*np = *p;
	else
		np->sum = 0, np->lc = np->rc = NULL;
	if (pL == pR)
	{
		np->sum += val;
		np->sum %= Mod;
		return np;
	}

	int pMid = pL + pR >> 1;
	if (key <= pMid)
		np->lc = seg_add(np->lc, pL, pMid, key, val);
	else
		np->rc = seg_add(np->rc, pMid + 1, pR, key, val);
	np->sum += val;
	np->sum %= Mod;
	return np;
}
inline int seg_query(node *p, const int &pL, const int &pR, const int &qL, const int &qR)
{
	if (!p)
		return 0;
	if (qL <= pL && pR <= qR)
		return p->sum;

	int pMid = pL + pR >> 1;

	int res = 0;
	if (qL <= pMid)
		res += seg_query(p->lc, pL, pMid, qL, qR);
	if (pMid < qR)
		res += seg_query(p->rc, pMid + 1, pR, qL, qR);
	res %= Mod;
	return res;
}

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		a[i] = getint();

	static s64 f[MaxN + 1];
	static int last[MaxA + 1];
	static node *tr[MaxN + 1];

	f[0] = 1, tr[0] = seg_add(NULL, 0, MaxA, a[0], f[0]);
	for (int i = 1; i <= n; i++)
	{
		f[i] = seg_query(tr[i - 1], 0, MaxA, 0, a[i]);
		if (last[a[i]] > 0)
			f[i] += Mod - seg_query(tr[last[a[i]] - 1], 0, MaxA, 0, a[i]);
		f[i] *= a[i];
		f[i] %= Mod;

		last[a[i]] = i;

		tr[i] = seg_add(tr[i - 1], 0, MaxA, a[i], f[i]);
	}

	s64 res = 0ll;
	for (int i = 1; i <= n; i++)
		res += f[i];
	res %= Mod;

	cout << res << endl;

	return 0;
}