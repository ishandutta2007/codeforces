#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105, p = 998244353;
map <int, long long> val;
vector <int> Ve;
int n, t, tree_ct, x[Maxn], y[Maxn];
long long ans;
struct line
{
	int x, lt, rt, type;
	bool operator < (const line &tmp) const
	{
		return x < tmp.x;
	}
};
vector <line> V;
struct Tree
{
	int lson, rson, mini, cnt, tag;
} tree[120 * Maxn];
void pushdown(int root)
{
	if (tree[root].tag)
	{
		tree[tree[root].lson].mini += tree[root].tag;
		tree[tree[root].lson].tag += tree[root].tag;
		tree[tree[root].rson].mini += tree[root].tag;
		tree[tree[root].rson].tag += tree[root].tag;
		tree[root].tag = 0;
	}
}
void insert(int root, int L, int R, int lt, int rt, int val)
{
	if (lt == L && rt == R)
		tree[root].mini += val, tree[root].tag += val;
	else
	{
		int mid = (L + R) >> 1;
		if (!tree[root].lson) tree[root].lson = ++tree_ct, tree[tree[root].lson] = (Tree){0, 0, 0, mid - L, 0};
		if (!tree[root].rson) tree[root].rson = ++tree_ct, tree[tree[root].rson] = (Tree){0, 0, 0, R - mid, 0};
		pushdown(root);
		if (lt >= mid) insert(tree[root].rson, mid, R, lt, rt, val);
		else if (rt <= mid) insert(tree[root].lson, L, mid, lt, rt, val);
		else insert(tree[root].lson, L, mid, lt, mid, val), insert(tree[root].rson, mid, R, mid, rt, val);
		tree[root].mini = min(tree[tree[root].lson].mini, tree[tree[root].rson].mini);
		tree[root].cnt = 0;
		if (tree[root].mini == tree[tree[root].lson].mini) tree[root].cnt += tree[tree[root].lson].cnt;
		if (tree[root].mini == tree[tree[root].rson].mini) tree[root].cnt += tree[tree[root].rson].cnt;
	}
}
void cal(int g)
{
	if (g < 0 || val[g]) return ;
	V.clear();
	for (int i = 1; i <= n; i++)
	{
		V.push_back((line){x[i] - g, y[i] - g, y[i] + g, 1});
		V.push_back((line){x[i] + g + 1, y[i] - g, y[i] + g, -1});
	}
	sort(V.begin(), V.end());
	int las = 0;
	tree_ct = 1, tree[1] = (Tree){0, 0, 0, 400000001, 0};
	long long result = 0;
	for (auto now : V)
	{
		(result += (now.x - las) * (400000001LL - !tree[1].mini * tree[1].cnt)) %= p, las = now.x;
		insert(1, -2e8, 2e8 + 1, now.lt, now.rt + 1, now.type);
	}
	val[g] = result;
}
int main()
{
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	Ve.push_back(t);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			Ve.push_back((max(abs(x[i] - x[j]), abs(y[i] - y[j])) - 1) / 2);
	sort(Ve.begin(), Ve.end());
	Ve.resize(unique(Ve.begin(), Ve.end()) - Ve.begin());
	while (Ve.back() > t) Ve.pop_back();
	int las = 0;
	for (auto now : Ve)
	{
		cal(now), cal(now - 1), cal(now - 2);
		long long las1 = val[now - 2], las2 = val[now - 1], delta = (2 * val[now - 1] - val[now] - val[now - 2] + 2 * p) % p;
		for (int i = now; i >= las; i--)
		{
			if (i <= now - 3)
			{
				long long tmp = (2 * las1 - las2 - delta + 2 * p) % p;
				(ans += p - tmp) %= p, las2 = las1, las1 = tmp;
			}
			else if (i != t) (ans += p - val[i]) %= p;
		}
		las = now + 1;
	}
	printf("%lld", (ans + t * val[t]) % p);
	return 0;
}