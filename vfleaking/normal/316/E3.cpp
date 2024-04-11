#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long s64;

const int MaxN = 200000;
const int M = 1000000000;

int fib[MaxN + 4];

struct node_info
{
	int size;
	int sum0, sum1;

	node_info(){}
	node_info(int v)
	{
		size = 1;
		sum0 = v * fib[1];
		sum1 = v * fib[2];
	}

	void add(int d)
	{
		sum0 = (sum0 + (s64)(fib[size + 2] + M - 1) * d) % M;
		sum1 = (sum1 + (s64)(fib[size + 3] + M - 1 - fib[1]) * d) % M;
	}

	friend inline node_info operator+(const node_info &lhs, const node_info &rhs)
	{
		node_info res;
		res.size = lhs.size + rhs.size;
		res.sum0 = (lhs.sum0 + (s64)rhs.sum0 * fib[lhs.size - 1] + (s64)rhs.sum1 * fib[lhs.size]) % M;
		res.sum1 = (lhs.sum1 + (s64)rhs.sum0 * fib[lhs.size] + (s64)rhs.sum1 * fib[lhs.size + 1]) % M;
		return res;
	}
};

struct node
{
	node_info info;
	int tag_d;
};
node seg[MaxN * 4 + 1];

void tag_add(int p, int d)
{
	seg[p].tag_d = (seg[p].tag_d + d) % M;
	seg[p].info.add(d);
}
void tag_down(int p)
{
	if (seg[p].tag_d != 0)
	{
		tag_add(p << 1 | 0, seg[p].tag_d);
		tag_add(p << 1 | 1, seg[p].tag_d);
		seg[p].tag_d = 0;
	}
}
void seg_set(int p, int pL, int pR, int q, int v)
{
	if (pL == pR)
	{
		seg[p].info = v;
		return;
	}
	tag_down(p);

	int pM = (pL + pR) >> 1;
	if (q <= pM)
		seg_set(p << 1 | 0, pL, pM, q, v);
	else
		seg_set(p << 1 | 1, pM + 1, pR, q, v);
	seg[p].info = seg[p << 1 | 0].info + seg[p << 1 | 1].info;
}
void seg_add(int p, int pL, int pR, int qL, int qR, int d)
{
	if (qL <= pL && pR <= qR)
	{
		tag_add(p, d);
		return;
	}
	tag_down(p);

	int pM = (pL + pR) >> 1;
	if (qL <= pM)
		seg_add(p << 1 | 0, pL, pM, qL, qR, d);
	if (pM < qR)
		seg_add(p << 1 | 1, pM + 1, pR, qL, qR, d);
	seg[p].info = seg[p << 1 | 0].info + seg[p << 1 | 1].info;
}
node_info seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && pR <= qR)
		return seg[p].info;
	tag_down(p);

	int pM = (pL + pR) >> 1;
	if (qR <= pM)
		return seg_query(p << 1 | 0, pL, pM, qL, qR);
	if (pM < qL)
		return seg_query(p << 1 | 1, pM + 1, pR, qL, qR);
	return seg_query(p << 1 | 0, pL, pM, qL, qR) + seg_query(p << 1 | 1, pM + 1, pR, qL, qR);
}

int main()
{
	int n, m;
	cin >> n >> m;

	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n + 3; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % M;
	
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		seg_set(1, 1, n, i, a);
	}

	while (m--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x, v;
			scanf("%d %d", &x, &v);
			seg_set(1, 1, n, x, v);
		}
		else if (t == 2)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", seg_query(1, 1, n, l, r).sum0);
		}
		else
		{
			int l, r, d;
			scanf("%d %d %d", &l, &r, &d);
			seg_add(1, 1, n, l, r, d);
		}
	}

	return 0;
}