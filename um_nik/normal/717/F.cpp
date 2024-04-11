#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e17;
const int N = 1 << 18;

struct Node
{
	int l, r;
	ll sum;
	ll minOdd, minEven;
	ll add;

	Node () : l(-1), r(-1), sum(), minOdd(INF), minEven(INF), add(0) {}
	Node (int _l, int _r, ll x) : l(_l), r(_r), sum(x), minOdd(x), minEven(0), add(0) {}

	void makeAdd(ll x)
	{
		add += x;
		minOdd += x;
		if ((r - l) & 1)
			sum += x;
	}
};

Node merge(Node L, Node R)
{
	if (L.l == -1) return R;
	if (R.r == -1) return L;
	Node A = Node();
	A.l = L.l;
	A.r = R.r;
	int lenL = L.r - L.l, lenR = R.r - R.l;
	A.sum = R.sum + L.sum * (lenR % 2 == 1 ? -1 : 1);
	A.minOdd = L.minOdd;
	A.minEven = L.minEven;
	if (lenL % 2 == 1)
	{
		A.minOdd = min(A.minOdd, R.minEven + L.sum);
		A.minEven = min(A.minEven, R.minOdd - L.sum);
	}
	else
	{
		A.minOdd = min(A.minOdd, R.minOdd - L.sum);
		A.minEven = min(A.minEven, R.minEven + L.sum);
	}
	A.add = 0;
	return A;
}

Node tree[2 * N];
ll a[N];
void buildTree()
{
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1, a[i]);
	for (int i = N - 1; i > 0; i--)
		tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
	return;
}

void push(int v)
{
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++)
		tree[u].makeAdd(tree[v].add);
	tree[v].add = 0;
	return;
}
void update(int v)
{
	if (v >= N) throw;
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	return;
}

void addSegm(int v, int l, int r, ll x)
{
	if (l <= tree[v].l && tree[v].r <= r)
	{
		tree[v].makeAdd(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		addSegm(u, l, r, x);
	update(v);
	return;
}

Node getVal(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v];
	if (l >= tree[v].r || tree[v].l >= r)
		return Node();
	push(v);
	return merge(getVal(2 * v, l, r), getVal(2 * v + 1, l, r));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = n; i < N; i++)
		a[i] = 1;
	buildTree();
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int t;
		int l, r;
		scanf("%d%d%d", &t, &l, &r);
		r++;
		if (t == 1)
		{
			ll x;
			scanf("%lld", &x);
			addSegm(1, l, r, x);
		}
		else
		{
			Node A = getVal(1, l, r);
			if (A.minEven >= 0 && A.minOdd >= 1 && A.sum == ((r - l) & 1))
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}