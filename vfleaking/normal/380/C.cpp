#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 1000000;
const int MaxM = 100000;

struct interval
{
	int l, r, i;
	friend inline bool operator<(const interval &lhs, const interval &rhs)
	{
		return lhs.l < rhs.l;
	}
};

int n;
char str[MaxN + 2];

int bit[MaxN + 1];

void bit_add(int x, int val)
{
	for (int i = x; i <= n; i += i & -i)
		bit[i] += val;
}
int bit_query(int x)
{
	int res = 0;
	for (int i = x; i >= 1; i -= i & -i)
		res += bit[i];
	return res;
}

int main()
{
	scanf("%s", str + 1);

	n = strlen(str + 1);

	int sta_n = 0;
	static int sta[MaxN];
	static int mat[MaxN + 1];

	for (int i = 1; i <= n; i++)
	{
		if (str[i] == '(')
			sta[sta_n++] = i;
		else
		{
			if (sta_n > 0)
				mat[sta[sta_n - 1]] = i, sta_n--;
		}
	}

	int m;
	static interval in[MaxM];
	static int res[MaxM];
	cin >> m;
	for (int i = 0; i < m; i++)
		scanf("%d %d", &in[i].l, &in[i].r), in[i].i = i;

	sort(in, in + m);

	for (int i = m - 1; i >= 0; i--)
	{
		int st = i == m - 1 ? n + 1 : in[i + 1].l;
		for (int k = st - 1; k >= in[i].l; k--)
			if (mat[k])
				bit_add(mat[k], 1);
		res[in[i].i] = bit_query(in[i].r);
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", res[i] * 2);

	return 0;
}