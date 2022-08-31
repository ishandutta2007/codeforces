#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Node
{
	int l, r;
	ll val, col;

	Node() : l(), r(), val(), col(-1) {}
	Node(int _l, int _r) : l(_l), r(_r), val(0), col(-1) {}
};

const int N = 1 << 19;
Node tree[2 * N];

void push(int v)
{
	if (tree[v].col == -1) return;
	for (int i = 0; i < 2; i++)
	{
		int u = 2 * v + i;
		tree[u].val = tree[u].col = tree[v].col;
	}
	tree[v].col = -1;
	return;
}
void update(int v)
{
	tree[v].val = tree[2 * v].val | tree[2 * v + 1].val;
	return;
}

vector<int> g[N];
int T;
int tin[N], tout[N];
int n, q;
int c[N];
bool used[N];

void dfs(int v)
{
	used[v] = true;
	tin[v] = T++;
	for (int u : g[v])
	{
		if (used[u]) continue;
		dfs(u);
	}
	tout[v] = T;
	return;
}

void buildTree()
{
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = 0; i < n; i++)
		tree[N + tin[i]].val = 1LL << c[i];
	for (int i = N - 1; i > 0; i--)
	{
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
		update(i);
	}
	return;
}

void read()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		c[i]--;
	}
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	buildTree();
	return;
}

void setOnSegm(int v, int l, int r, ll mask)
{
	if (l <= tree[v].l && tree[v].r <= r)
	{
		tree[v].val = tree[v].col = mask;
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r)
		return;
	push(v);
	for (int i = 0; i < 2; i++)
		setOnSegm(2 * v + i, l, r, mask);
	update(v);
	return;
}

ll getMask(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0LL;
	push(v);
	return getMask(2 * v, l, r) | getMask(2 * v + 1, l, r);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	while(q--)
	{
		int t, v;
		scanf("%d%d", &t, &v);
		v--;
		if (t == 1)
		{
			int cc;
			scanf("%d", &cc);
			cc--;
			setOnSegm(1, tin[v], tout[v], 1LL << cc);
		}
		else
		{
			ll mask = getMask(1, tin[v], tout[v]);
			int cnt = 0;
			for (int i = 0; i < 61; i++)
				if (mask & (1LL << i))
					cnt++;
			printf("%d\n", cnt);
		}
	}

	return 0;
}