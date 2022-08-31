#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e17;

int myRand()
{
	return rand() ^ (rand() << 14);
}

vector<ll> BAD_VALS;

ll getToNext(ll x)
{
	if (x > BAD_VALS.back()) return INF;
	return *lower_bound(BAD_VALS.begin(), BAD_VALS.end(), x) - x;
}

struct Node
{
	ll val, toNext, toAdd, minVal;
	int y;
	int len;
	int sz;
	int l, r;

	Node() : val(0), toNext(1), toAdd(0), minVal(1), y(myRand()), len(0), sz(0), l(-1), r(-1) {}
	Node(ll _val, int _len) : val(_val), toNext(getToNext(_val)), toAdd(0), minVal(getToNext(_val)), len(_len), sz(_len), l(-1), r(-1) {}
};

const int N = 100100;
const int SZ = N * 6;
vector<int> freee;
Node tree[SZ];
int root = -1;

int getNewVertex()
{
	if (freee.empty()) throw;
	int x = freee.back();
	freee.pop_back();
	tree[x] = Node();
	return x;
}

int getSize(int v)
{
	if (v == -1) return 0;
	return tree[v].sz;
}
ll getMinVal(int v)
{
	if (v == -1) return INF;
	return tree[v].minVal;
}

void addToVertex(int v, ll toAdd)
{
	if (v == -1) return;
	tree[v].toAdd += toAdd;
	tree[v].val += toAdd;
	tree[v].minVal -= toAdd;
	tree[v].toNext -= toAdd;
	return;
}
void push(int v)
{
	if (v == -1) throw;
	ll toAdd = tree[v].toAdd;
	tree[v].toAdd = 0;
	addToVertex(tree[v].l, toAdd);
	addToVertex(tree[v].r, toAdd);
	return;
}

int update(int v)
{
	if (v == -1) throw;
	tree[v].sz = tree[v].len + getSize(tree[v].l) + getSize(tree[v].r);
	tree[v].minVal = min(tree[v].toNext, min(getMinVal(tree[v].l), getMinVal(tree[v].r)));
	return v;
}

int merge(int L, int R)
{
//	cerr << "MERGE" << endl;
	if (L == -1) return R;
	if (R == -1) return L;
	if (tree[L].y > tree[R].y)
	{
		push(L);
		tree[L].r = merge(tree[L].r, R);
		return update(L);
	}
	else
	{
		push(R);
		tree[R].l = merge(L, tree[R].l);
		return update(R);
	}
}
void split(int v, int k, int &L, int &R)
{
//	cerr << "SPLIT" << endl;
	if (v == -1)
	{
		L = R = -1;
		return;
	}
	push(v);
	if (getSize(tree[v].l) >= k)
	{
		split(tree[v].l, k, L, tree[v].l);
		R = update(v);
		return;
	}
	k -= getSize(tree[v].l);
	if (k < tree[v].len)
	{
		int u1 = getNewVertex(), u2 = getNewVertex();
		tree[u1] = Node(tree[v].val, k);
		tree[u2] = Node(tree[v].val, tree[v].len - k);
		L = merge(tree[v].l, u1);
		R = merge(u2, tree[v].r);
		freee.push_back(v);
		return;
	}
	k -= tree[v].len;
	split(tree[v].r, k, tree[v].r, R);
	L = update(v);
	return;
}

ll queryGetVal(int k)
{
	int v = root;
	while(v != -1)
	{
		push(v);
		int sz = getSize(tree[v].l);
		if (k < sz)
		{
			v = tree[v].l;
			continue;
		}
		k -= sz;
		if (k < tree[v].len)
			return tree[v].val;
		k -= tree[v].len;
		v = tree[v].r;
	}
	throw;
}

void freeAllTree(int v)
{
	if (v == -1) return;
	freeAllTree(tree[v].l);
	freeAllTree(tree[v].r);
	freee.push_back(v);
}

void querySetValOnSegm(int l, int r, ll newVal)
{
	int L, M, R;
	split(root, l, L, M);
	split(M, r - l, M, R);
	int newLen = getSize(M);
	freeAllTree(M);
	M = getNewVertex();
	tree[M] = Node(newVal, newLen);
	root = merge(L, merge(M, R));
}

void fixMin(int v)
{
	if (v == -1) throw;
	push(v);
	if (tree[v].toNext == tree[v].minVal)
	{
		tree[v].toNext = getToNext(tree[v].val);
		v = update(v);
		return;
	}
	if (getMinVal(tree[v].l) == tree[v].minVal)
		fixMin(tree[v].l);
	else
		fixMin(tree[v].r);
	v = update(v);
	return;
}

void simplyAddOnTree(int v, ll toAdd)
{
	tree[v].val += toAdd;
	tree[v].toAdd += toAdd;
	tree[v].toNext -= toAdd;
	tree[v].minVal -= toAdd;
}

void queryAddOnTree(int v, ll toAdd)
{
	simplyAddOnTree(v, toAdd);
	while(true)
	{
//		cerr << "IN OUTER" << endl;
		while(tree[v].minVal < 0)
		{
//			cerr << "FIXING MIN" << endl;
			fixMin(v);
		}
		if (tree[v].minVal > 0) break;
		simplyAddOnTree(v, toAdd);
	}
}

void queryAddOnSegm(int l, int r, ll toAdd)
{
	int L, M, R;
	split(root, l, L, M);
	split(M, r - l, M, R);
	queryAddOnTree(M, toAdd);
	root = merge(L, merge(M, R));
}

void init()
{
	ll x = 1;
	while(x < INF)
	{
		BAD_VALS.push_back(x);
		x *= 42;
	}
	for (int i = 0; i < SZ; i++)
		freee.push_back(i);
	return;
}


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	init();

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		ll x;
		scanf("%lld", &x);
		int v = getNewVertex();
		tree[v] = Node(x, 1);
		root = merge(root, v);
	}
	while(q--)
	{
//		cerr << "NEW QUERY" << endl;
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int k;
			scanf("%d", &k);
			k--;
			printf("%lld\n", queryGetVal(k));
		}
		else if (type == 2)
		{
			int l, r;
			ll x;
			scanf("%d%d%lld", &l, &r, &x);
			l--;
			querySetValOnSegm(l, r, x);
		}
		else
		{
			int l, r;
			ll x;
			scanf("%d%d%lld", &l, &r, &x);
			l--;
			queryAddOnSegm(l, r, x);
		}
	}

	return 0;
}