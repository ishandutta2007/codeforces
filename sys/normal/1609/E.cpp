#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
int n, q;
string str;
struct Tree
{
	int lt, rt, AB, A, B, cnt[3];
} tree[4 * Maxn];
void update(int root)
{
	tree[root].AB = min(min(tree[root << 1].AB + tree[root << 1 | 1].cnt[2], tree[root << 1].cnt[0] + tree[root << 1 | 1].AB), tree[root << 1].A + tree[root << 1 | 1].B);
	tree[root].A = min(tree[root << 1].A + tree[root << 1 | 1].cnt[1], tree[root << 1 | 1].A + tree[root << 1].cnt[0]);
	tree[root].B = min(tree[root << 1].B + tree[root << 1 | 1].cnt[2], tree[root << 1 | 1].B + tree[root << 1].cnt[1]);
	for (int i = 0; i <= 2; i++) tree[root].cnt[i] = tree[root << 1].cnt[i] + tree[root << 1 | 1].cnt[i];
}
void build(int root, int lt, int rt)
{
	tree[root].lt = lt, tree[root].rt = rt;
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid), build(root << 1 | 1, mid, rt);
	}
}
void insert(int root, int pos, int s, int val)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].cnt[s] += val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) insert(root << 1 | 1, pos, s, val);
		else insert(root << 1, pos, s, val);
		update(root);
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	cin >> str;
	build(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
		insert(1, i, str[i - 1] - 'a', 1);
	while (q--)
	{
		int pos;
		scanf("%d", &pos);
		char ch = getchar();
		while (!isalpha(ch)) ch = getchar();
		insert(1, pos, str[pos - 1] - 'a', -1);
		str[pos - 1] = ch;
		insert(1, pos, str[pos - 1] - 'a', 1);
		printf("%d\n", tree[1].AB);
	}
	return 0;
}