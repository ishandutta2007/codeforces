#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 77777;
const int Num = 3;

bool isGood[Num + 1][Num + 1];

const int Mod = 777777777;

struct node
{
	s64 f[Num + 1][Num + 1];
};

node tree[MaxN * 4 + 1];

inline void update(const int &p)
{
	int lp = p << 1;
	int rp = p << 1 | 1;
	for (int i = 1; i <= Num; i++)
		for (int j = 1; j <= Num; j++)
		{
			tree[p].f[i][j] = 0ll;
			for (int i1 = 1; i1 <= Num; i1++)
				for (int i2 = 1; i2 <= Num; i2++)
					if (isGood[i1][i2])
						tree[p].f[i][j] += tree[lp].f[i][i1] * tree[rp].f[i2][j];
			tree[p].f[i][j] %= Mod;
		}
}

void seg_build(const int &p, const int &l, const int &r)
{
	node *pp = &tree[p];
	if (l == r)
	{
		for (int i = 1; i <= Num; i++)
			for (int j = 1; j <= Num; j++)
				pp->f[i][j] = 0ll;
		for (int i = 1; i <= Num; i++)
			pp->f[i][i] = 1ll;
	}
	else
	{
		int mid = l + r >> 1;
		seg_build(p << 1, l, mid);
		seg_build(p << 1 | 1, mid + 1, r);

		update(p);
	}
}

void seg_modify(
		const int &p, const int &l, const int &r,
		const int &pos, const int &val)
{
	node *pp = &tree[p];
	if (l == r)
	{
		for (int i = 1; i <= Num; i++)
			for (int j = 1; j <= Num; j++)
				pp->f[i][j] = 0ll;
		if (val != 0)
			pp->f[val][val] = 1ll;
		else
		{
			for (int i = 1; i <= Num; i++)
				pp->f[i][i] = 1ll;
		}
	}
	else
	{
		int mid = l + r >> 1;
		if (pos <= mid)
			seg_modify(p << 1, l, mid, pos, val);
		else
			seg_modify(p << 1 | 1, mid + 1, r, pos, val);
		update(p);
	}
}

inline int seg_answer()
{
	s64 res = 0ll;
	for (int i = 1; i <= Num; i++)
		for (int j = 1; j <= Num; j++)
			res += tree[1].f[i][j];
	res %= Mod;
	return (int)res;
}

int main()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= Num; i++)
		for (int j = 1; j <= Num; j++)
		{
			int t;
			cin >> t;
			isGood[i][j] = t == 1;
		}

	seg_build(1, 1, n);

	while (q--)
	{
		int v, t;
		scanf("%d %d", &v, &t);

		seg_modify(1, 1, n, v, t);

		printf("%d\n", seg_answer());
	}

	return 0;
}