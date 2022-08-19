#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 1 << 19;

struct Node
{
	int l, r;
	ll val;
	int lPos, lNeg, rPos, rNeg, inAns, lAns, rAns;

	Node () : l(-1), r(-1), val(), lPos(), lNeg(), rPos(), rNeg(), inAns(), lAns(), rAns() {}
	Node(int _l, int _r) : l(_l), r(_r), val(0), lPos(0), lNeg(0), rPos(0), rNeg(0), inAns(0), lAns(0), rAns(0) {}

	void update()
	{
		if (val > 0)
		{
			lPos = rPos = 1;
			lNeg = rNeg = 0;
			inAns = lAns = rAns = 1;
		}
		else if (val < 0)
		{
			lPos = rPos = 0;
			lNeg = rNeg = 1;
			inAns = lAns = rAns = 1;
		}
		else
		{
			lPos = rPos = 0;
			lNeg = rNeg = 0;
			inAns = lAns = rAns = 0;
		}
	}
};
Node tree[2 * N + 7];

Node merge(Node L, Node R)
{
	if (L.l == -1) return R;
	if (R.l == -1) return L;
	Node A = Node(L.l, R.r);
	int lenL = L.r - L.l, lenR = R.r - R.l;
	A.lPos = L.lPos + (L.lPos == lenL ? R.lPos : 0);
	A.lNeg = L.lNeg + (L.lNeg == lenL ? R.lNeg : 0);
	A.rPos = R.rPos + (R.rPos == lenR ? L.rPos : 0);
	A.rNeg = R.rNeg + (R.rNeg == lenR ? L.rNeg : 0);
	A.inAns = max(L.inAns, R.inAns);
	A.inAns = max(A.inAns, L.rAns + R.lNeg);
	A.inAns = max(A.inAns, R.lAns + L.rPos);
	A.lAns = L.lAns + (L.lAns == lenL ? R.lNeg : 0);
	if (L.lPos == lenL)
		A.lAns = max(A.lAns, lenL + R.lAns);
	A.rAns = R.rAns + (R.rAns == lenR ? L.rPos : 0);
	if (R.lNeg == lenR)
		A.rAns = max(A.rAns, lenR + L.rAns);
	A.inAns = max(A.inAns, max(A.lAns, A.rAns));
	return A;
}

void buildTree()
{
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
	return;
}

ll a[N];
int n;

void changeTree(int v)
{
	tree[v + N].val = a[v];
	v += N;
	tree[v].update();
	while(v > 1)
	{
		v >>= 1;
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	buildTree();
	scanf("%d", &n);
	n--;
	ll prev;
	scanf("%lld", &prev);
	for (int i = 0; i < n; i++)
	{
		ll x;
		scanf("%lld", &x);
		a[i] = x - prev;
		prev = x;
		changeTree(i);
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int l, r;
		ll x;
		scanf("%d%d%lld", &l, &r, &x);
		l -= 2;
		r--;
		if (l >= 0)
		{
			a[l] += x;
			changeTree(l);
		}
		if (r < n)
		{
			a[r] -= x;
			changeTree(r);
		}
		printf("%d\n", 1 + tree[1].inAns);
	}

	return 0;
}