#include "bits/stdc++.h"
using namespace std;

constexpr int TSIZE = 200005;
long long atree[TSIZE + 1];
long long btree[TSIZE + 1];

long long query(int p, long long *tree)
{
	long long ret = 0;
	for (; p > 0; p -= p & -p)
	{
		ret += tree[p];
	}
	return ret;
}

void add(int p, long long val, long long *tree)
{
	for (; p <= TSIZE; p += p & -p)
	{
		tree[p] += val;
	}
}

long long orders[200005];

int main()
{
	int n, k, a, b, q;
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);

	for (int i = 0; i < q; i++)
	{
		int type;
		scanf("%d",&type);
		if (type == 1)
		{
			int c, d;
			scanf("%d%d",&c,&d);
			long long before = orders[c];
			orders[c] += d;
			if (before < a)
			{
				long long inc = min<long long>(orders[c], a) - before;
				add(c, inc, atree);
				//printf("inca of %d %lld\n", c, inc);
			}

			if (before < b)
			{
				long long inc = min<long long>(orders[c], b) - before;
				add(c, inc, btree);
				//printf("incb of %d %lld\n", c, inc);
			}
		}
		else
		{
			int c;
			scanf("%d",&c);
			printf("%lld\n", query(c - 1, btree) + query(n, atree) -
					query(c + k - 1, atree));
		}
	}
}