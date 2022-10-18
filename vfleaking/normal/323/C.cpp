#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000000;
const int MaxLogN = 20;

struct node
{
	int sum;
	node *lc, *rc;
};
node pool[MaxN * (MaxLogN + 1)], *tail = pool;

inline node *seg_insert(node *p, int pL, int pR, int q)
{
	node *np = tail++;
	if (p != NULL)
		*np = *p;
	if (pL == pR)
	{
		np->sum++;
		return np;
	}

	int pM = (pL + pR) >> 1;
	if (q <= pM)
		np->lc = seg_insert(np->lc, pL, pM, q);
	else
		np->rc = seg_insert(np->rc, pM + 1, pR, q);
	np->sum++;
	return np;
}
inline int seg_query(node *p, int pL, int pR, int qL, int qR)
{
	if (p == NULL)
		return 0;
	if (qL <= pL && pR <= qR)
		return p->sum;
	int pM = (pL + pR) >> 1;
	int res = 0;
	if (qL <= pM)
		res += seg_query(p->lc, pL, pM, qL, qR);
	if (pM < qR)
		res += seg_query(p->rc, pM + 1, pR, qL, qR);
	return res;
}

int main()
{
	int n, m;
	static int a[MaxN + 1], b[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		int rb;
		scanf("%d", &rb);
		b[rb] = i;
	}

	static node *seg[MaxN + 1];
	for (int i = 1; i <= n; i++)
		seg[i] = seg_insert(seg[i - 1], 1, n, b[a[i]]);

	cin >> m;
	int lastAns = 0;
	while (m--)
	{
		int pa, pb, pc, pd;
		scanf("%d %d %d %d", &pa, &pb, &pc, &pd);

		int l1 = min((pa - 1 + lastAns) % n, (pb - 1 + lastAns) % n) + 1;
		int r1 = max((pa - 1 + lastAns) % n, (pb - 1 + lastAns) % n) + 1;
		int l2 = min((pc - 1 + lastAns) % n, (pd - 1 + lastAns) % n) + 1;
		int r2 = max((pc - 1 + lastAns) % n, (pd - 1 + lastAns) % n) + 1;

		printf("%d\n", lastAns = seg_query(seg[r1], 1, n, l2, r2) - seg_query(seg[l1 - 1], 1, n, l2, r2));
		lastAns++;
	}

	return 0;
}