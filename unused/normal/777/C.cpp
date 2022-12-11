#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dat;
int yescnt[100005];

constexpr int TSIZE = 131072;
int tree[TSIZE * 2 + 1];

void update(int l, int r, int val)
{
	l += TSIZE; r += TSIZE;
	while (l <= r)
	{
		if (l & 1) tree[l] = max(tree[l], val), l++;
		if (!(r & 1)) tree[r] = max(tree[r], val), r--;
		l >>= 1; r >>= 1;
	}
}

int query(int pos)
{
	int ret = 0;
	for (pos += TSIZE; pos; pos >>= 1) ret = max(ret, tree[pos]);
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	dat.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &dat[i][j]);

	for (int i = 0; i < m; i++)
	{
		for (int l = 0, r; l < n; l = r)
		{
			for (r = l + 1; r < n && dat[r][i] >= dat[r - 1][i]; r++);
			update(l, r - 1, r - 1);
		}
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		if (query(a) >= b) printf("Yes\n");
		else printf("No\n");
	}
}