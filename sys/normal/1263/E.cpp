#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, path[Maxn], pos = 1;
char now[Maxn];
string str;
set <int> L, R;
struct Tree
{
	int lt, rt, val, maxi, mini;
}tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void insert(int root, int pos, int val)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].val = tree[root].maxi = tree[root].mini = val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) insert(root << 1 | 1, pos, val);
		else insert(root << 1, pos, val);
		tree[root].val = tree[root << 1].val + tree[root << 1 | 1].val;
		tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi + tree[root << 1].val);
		tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini + tree[root << 1].val);
	}
}
int main()
{
	path[0] = 0x3f3f3f3f;
	scanf("%d", &n);
	cin >> str;
	build(1, 1, n + 1);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'L') pos = max(pos - 1, 1);
		else if (str[i] == 'R') pos++;
		else
		{
			if (now[pos] == '(' || now[pos] == ')')
				insert(1, pos, 0);
			if (str[i] == '(')
				insert(1, pos, 1);
			else if (str[i] == ')')
				insert(1, pos, -1);
			now[pos] = str[i];
		}
		if (tree[1].mini < 0 || tree[1].val) printf("-1 ");
		else printf("%d ", tree[1].maxi);
	}
	return 0;
}