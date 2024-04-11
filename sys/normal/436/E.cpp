#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600005;
int n, m, w, pos, a[Maxn], b[Maxn], ord[Maxn], tmp[Maxn];
map <int, int> Ma;
char ch[Maxn];
long long sum, ans;
struct Tree
{
	int lt, rt, siz;
	long long sum;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, 0};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void insert(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].sum += tmp[tree[root].lt], tree[root].siz++;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) insert(root << 1 | 1, pos);
		else insert(root << 1, pos);
		tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
		tree[root].siz = tree[root << 1].siz + tree[root << 1 | 1].siz;
	}
}
void erase(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].sum -= tmp[tree[root].lt], tree[root].siz--;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) erase(root << 1 | 1, pos);
		else erase(root << 1, pos);
		tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
		tree[root].siz = tree[root << 1].siz + tree[root << 1 | 1].siz;
	}
}
long long ask(int root, int k)
{
	if (tree[root].siz < k) return 0x3f3f3f3f3f3f3f3fLL;
	if (tree[root].lt + 1 == tree[root].rt) return k * tmp[tree[root].lt];
	if (tree[root].siz == k) return tree[root].sum;
	else if (tree[root << 1].siz >= k) return ask(root << 1, k);
	else return tree[root << 1].sum + ask(root << 1 | 1, k - tree[root << 1].siz);
}
int main()
{
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]), ord[i] = i;
	sort(ord + 1, ord + 1 + n, [](int x, int y){return b[x] < b[y];});
	for (int i = 1; i <= n; i++)
		tmp[2 * i - 1] = b[ord[i]] - a[ord[i]], tmp[2 * i] = a[ord[i]];
	sort(tmp + 1, tmp + 1 + 2 * n);
	m = unique(tmp + 1, tmp + 1 + 2 * n) - tmp - 1;
	build(1, 1, m + 1);
	for (int i = 1; i <= n; i++)
		insert(1, lower_bound(tmp + 1, tmp + 1 + m, a[ord[i]]) - tmp);
	ans = ask(1, w);
	for (int i = 1; i <= min(w - 1, n); i++)
	{
		sum += a[ord[i]];
		erase(1, lower_bound(tmp + 1, tmp + 1 + m, a[ord[i]]) - tmp), insert(1, lower_bound(tmp + 1, tmp + 1 + m, b[ord[i]] - a[ord[i]]) - tmp);
		if (ans > sum + ask(1, w - i)) pos = i, ans = sum + ask(1, w - i);
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++)
		Ma[a[ord[i]]]++;
	for (int i = 1; i <= pos; i++)
		Ma[a[ord[i]]]--, Ma[b[ord[i]] - a[ord[i]]]++;
	int Left = w - pos;
	for (map <int, int> :: iterator it = Ma.begin(); it != Ma.end(); it++)
		if (Left <= it -> second)
			it -> second = Left, Left = 0;
		else Left -= it -> second;
	for (int i = 1; i <= n; i++)
		if (i <= pos)
		{
			if (Ma[b[ord[i]] - a[ord[i]]]) Ma[b[ord[i]] - a[ord[i]]]--, ch[ord[i]] = '2';
			else ch[ord[i]] = '1';
		}
		else
		{
			if (Ma[a[ord[i]]]) Ma[a[ord[i]]]--, ch[ord[i]] = '1';
			else ch[ord[i]] = '0';
		}
	printf("%s", ch + 1);
	return 0;
}