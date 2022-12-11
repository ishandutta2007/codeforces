#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = (int)1e5 + 10;
const int pow2 = (1 << 17);
const int ALPH = 26;

struct SegmentTree
{
	int tree[pow2 * 2];
	int d[pow2 * 2];
	void build()
	{
		for (int i = 0; i < pow2 * 2; i++)
		{
			tree[i] = 0;
			d[i] = -1;
		}
	}
	inline void push(int v, int len)
	{	
		if (d[v] != -1)
		{
			d[2 * v] = d[2 * v + 1] = d[v];
			tree[2 * v] = tree[2 * v + 1] = d[v] * len;
			d[v] = -1;
		}
	}
	void setVal(int a, int b, int val, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
		{
			d[v] = val;	
			tree[v] = (r - l + 1) * val;
			return;
		}
		if (l > b || r < a)
			return;
		push(v, (r - l + 1) >> 1);
		int m = ((l + r) >> 1);
		setVal(a, b, val, 2 * v, l, m);
		setVal(a, b, val, 2 * v + 1, m + 1, r);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}
	int getSum(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 0;
		int m = ((l + r) >> 1);
		push(v, (r - l + 1) >> 1);
		return getSum(a, b, 2 * v, l, m) + getSum(a, b, 2 * v + 1, m + 1, r);
	}
} tree[ALPH];


char str[N];
int cnt[ALPH];
int n;

void doQuery(int a, int b)
{
	fill(cnt, cnt + ALPH, 0);
	int cntOdd = 0;
	for (int c = 0; c < ALPH; c++)
	{                     
		cnt[c] = tree[c].getSum(a, b);
		if (cnt[c] & 1)
			cntOdd++;

		if (cntOdd > 1 || (cntOdd == 1 && ((b - a + 1) & 1) == 0))
			return;
	}                        
	int lPos = a, rPos = b;
	int med = (a + (b - a) / 2);
	for (int i = 0; i < ALPH; i++)
	{                             
		if (cnt[i] > 0)
		{
			tree[i].setVal(a, b, 0);
			int t = (cnt[i] >> 1);
			if (t > 0)
			{
				tree[i].setVal(lPos, lPos + t - 1, 1);
				tree[i].setVal(rPos - t + 1, rPos, 1);
			}
			if (cnt[i] & 1)
				tree[i].setVal(med, med, 1);
			lPos += t;
			rPos -= t;
		}
	}
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	for (int i = 0; i < ALPH; i++)
		tree[i].build();
	int m;
	scanf("%d%d\n%s", &n, &m, str);   
	for (int i = 0; i < n; i++)
	{
		int code = str[i] - 'a';
		tree[code].setVal(i, i, 1);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		doQuery(a, b);
	}

	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < ALPH; s++)
			if (tree[s].getSum(i, i) == 1)
			{
				printf("%c", s + 'a');
				break;
			}
	}

	return 0;
}