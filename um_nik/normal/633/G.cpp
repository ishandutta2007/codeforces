#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ull;

const int N = 1 << 17;
const int M = 1010;
const int B = 64;
const int S = (M / B) + 2;
const int YY = 22;
const int Y = (1 << YY);
vector<int> g[N];
int n, m;
int pc[Y + 30];
int sv[N];
bool used[N];
int tin[N], tout[N];
int T;

int ppc(ull x)
{
	return pc[x & (ull)(Y - 1)] + pc[(x >> YY) & (ull)(Y - 1)] + pc[x >> (2 * YY)];
}

struct Bitset
{
	ull x[S];

	Bitset() : x() {}

	int popcount()
	{
		int res = 0;
		for (int i = 0; i < S; i++)
			res += ppc(x[i]);
		return res;
	}

	void setBit(int z)
	{
		x[z / B] |= (ull)1 << (z % B);
	}

	Bitset operator | (const Bitset &A) const
	{
		Bitset R = Bitset();
		for (int i = 0; i < S; i++)
			R.x[i] = x[i] | A.x[i];
		return R;
	}

	Bitset operator & (const Bitset &A) const
	{
		Bitset R = Bitset();
		for (int i = 0; i < S; i++)
			R.x[i] = x[i] & A.x[i];
		return R;
	}

	Bitset shl(int k)
	{
		int z = k / B;
		Bitset R = Bitset();
		for (int i = 0; i + z < S; i++)
			R.x[i] = x[i + z];
		k %= B;
		if (k == 0) return R;
		R.x[0] >>= k;
		for (int i = 1; i < S; i++)
		{
			R.x[i - 1] |= (R.x[i] & (((ull)1 << k) - 1)) << (B - k);
			R.x[i] >>= k;
		}
		return R;
	}

	Bitset shr(int k)
	{
		int z = k / B;
		Bitset R = Bitset();
		for (int i = 0; i + z < S; i++)
			R.x[i + z] = x[i];
		k %= B;
		if (k == 0) return R;
		R.x[S - 1] <<= k;
		for (int i = S - 2; i >= 0; i--)
		{
			R.x[i + 1] |= R.x[i] >> (B - k);
			R.x[i] <<= k;
		}
		return R;
	}

	Bitset rotate(int k, int m)
	{
		if (k == 0) return *this;
		k = m - k;
		int p = (k + B - 1) / B;
		Bitset X = Bitset();
		for (int i = 0; i < p; i++)
			X.x[i] = x[i];
		if (k % B != 0)
			X.x[p - 1] &= ((ull)1 << (k % B)) - (ull)1;
		return shl(k) | X.shr(m - k);
	}
};

struct Node
{
	int l, r;
	Bitset val;
	int sh;

	Node() : l(), r(), val(), sh() {}
	Node(int _l, int _r) : l(_l), r(_r), val(), sh(0) {}
};
Node tree[2 * N];

bool isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
Bitset P;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 2; i < m; i++)
		if (isPrime(i))
			P.setBit(i);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sv[i]);
		sv[i] %= m;
	}
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	return;
}

void dfs(int v)
{
	used[v] = 1;
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
		tree[N + tin[i]].val.setBit(sv[i]);
	for (int i = N - 1; i > 0; i--)
	{
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
		tree[i].val = tree[2 * i].val | tree[2 * i + 1].val;
	}
	return;
}

void solve()
{
	dfs(0);
	buildTree();
}

void push(int v)
{
	if (v >= N) throw;
	if (tree[v].sh == 0) return;
	int d = tree[v].sh;
	for (int i = 0; i < 2; i++)
	{
		int u = 2 * v + i;
		tree[u].sh = (tree[u].sh + d) % m;
		tree[u].val = tree[u].val.rotate(d, m);
	}
	tree[v].sh = 0;
	return;
}
void update(int v)
{
	if (v >= N) throw;
	tree[v].sh = 0;
	tree[v].val = tree[2 * v].val | tree[2 * v + 1].val;
	return;
}

void rotateOnSegm(int v, int l, int r, int d)
{
	if (l <= tree[v].l && tree[v].r <= r)
	{
		tree[v].sh = (tree[v].sh + d) % m;
		tree[v].val = tree[v].val.rotate(d, m);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	rotateOnSegm(2 * v, l, r, d);
	rotateOnSegm(2 * v + 1, l, r, d);
	update(v);
	return;
}

Bitset getVal(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return Bitset();
	push(v);
	return getVal(2 * v, l, r) | getVal(2 * v + 1, l, r);
}

void query()
{
	int t;
	scanf("%d", &t);
	if (t == 1)
	{
		int v, d;
		scanf("%d%d", &v, &d);
		v--;
		d %= m;
		if (d == 0) return;
		rotateOnSegm(1, tin[v], tout[v], d);
	}
	else
	{
		int v;
		scanf("%d", &v);
		v--;
		Bitset res = getVal(1, tin[v], tout[v]);
		printf("%d\n", (res & P).popcount());
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < Y; i++)
		pc[i] = pc[i >> 1] + (i & 1);
	read();
	solve();
//	for (int i = 0; i < n; i++)
//		printf("%d %d\n", tin[i], tout[i]);
	int q;
	scanf("%d", &q);
	while(q--)
		query();

	return 0;
}