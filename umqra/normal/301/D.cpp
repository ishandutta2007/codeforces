#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
                                    
const int N = (int)3e5;
const int SZ = (int)3e6;
const int pow2 = (1 << 18);
const int INF = (int)1e9;

struct E
{
	int l, r;
	int t;
	E () {}
	E (int _l, int _r, int _t)
	{
		t = _t;
		l = min(_l, _r);
		r = max(_l, _r);
	}
} event[SZ];

int ind;

struct item
{
	int tree[pow2 * 2];
	void build()	
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = 0;
	}
	void addVal(int pos, int val, int v = 1, int l = 0, int r = pow2 - 1)
	{                             
		int t = pow2 + pos;
		tree[t] += val;
		while (t > 1)
		{
			t /= 2;
			tree[t] = tree[2 * t] + tree[2 * t + 1];
		}
	}
	int getSum(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 0;	
		int m = ((l + r) >> 1);
		return getSum(a, b, 2 * v, l, m) + getSum(a, b, 2 * v + 1, m + 1, r);
	}
} tree;

bool cmp(const E &a, const E &b)
{
	if (a.l != b.l)
		return a.l < b.l;
	else
		return a.t < b.t;
}

int a[N];
int pos[N];
int ans[N];
                                           
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}                 

	for (int i = 1; i <= n; i++)
	{
		for (int s = 1; s * s <= i; s++)
		{
			if (i % s == 0)
			{
				int k1 = s;
				int k2 = i / s;
				if (k1 != k2)
				{
					event[ind++] = E(pos[i], pos[k1], INF);
					event[ind++] = E(pos[i], pos[k2], INF);
					tree.addVal(max(pos[i], pos[k1]), 1);
					tree.addVal(max(pos[i], pos[k2]), 1);
				}
				else
				{
					event[ind++] = E(pos[i], pos[k1], INF);
					tree.addVal(max(pos[i], pos[k1]), 1);
				}
			}
		}
	}
                                       

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		event[ind++] = E(a, b, i);
	}

	sort(event, event + ind, cmp);

	for (int i = 0; i < ind; i++)
	{
//		cout << event[i].t << ":" << event[i].l << ' ' << event[i].r << endl;
		if (event[i].t != INF)
			ans[event[i].t] = tree.getSum(event[i].l, event[i].r);
		else
			tree.addVal(event[i].r, -1);
	}
                                  
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);


	return 0;
}