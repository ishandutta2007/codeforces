#include <cstdio>
#include <utility>
#include <random>
#include <chrono>

const int md = 998244353;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int mul(int a, int b) 
{
	return (long long)a * b % md;
}
int po(int a, int b) 
{
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) 
{
	return po(a, md - 2);
}
inline int di(int a, int b) 
{
	return mul(a, inv(b));
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct tree {
	tree *l, *r;
	int size;
	bool val, clear;
	tree(bool val_) {
		val = val_;
		clear = false;
		size = 1;
		l = r = 0;
	}
};

inline int size_f(tree *a)
{
	if (a) return a->size;
	return 0;
}

void push(tree *a) 
{
	if (a && a->clear) {
		a->val = 0;
		if (a->l) a->l->clear = true;
		if (a->r) a->r->clear = true;
		a->clear = false;
	}
}

bool test(int x, int y) 
{
    return (long long)rng() * (x + y) <= (((long long)1 << 32) - 1) * x;
}

tree *merge(tree *a, tree *b)
{
	if (!a) return b;
	if (!b) return a;
	push(a);
	push(b);
	if (test(a->size, b->size)) {
		a->size += b->size;
		a->r = merge(a->r, b);
		return a;
	}
	b->size += a->size;
	b->l = merge(a, b->l);
	return b;
}

std::pair<tree *, tree *> split(tree *a, int x)
{
	if (!a) return std::pair<tree *, tree *>();
	push(a);
	std::pair<tree *, tree *> p;
	if (x <= size_f(a->l)) {
		p = split(a->l, x);
		a->size -= x;
		a->l = p.second;
		p.second = a;
	}
	else {
		p = split(a->r, x - size_f(a->l) - 1);
		a->size = x;
		a->r = p.first;
		p.first = a;
	}
	return p;
}

tree *lmost(tree *a) 
{
	push(a);
	if (a->l) return lmost(a->l);
	return a;
}

const int N = 500005;
int t, n, m, fact[N];

inline int ncr(int n, int r) 
{
	return di(fact[n], mul(fact[n - r], fact[r]));
}

int main() 
{
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	tree *root = 0;
	for (int i = 0; i < 200100; ++i) root = merge(root, new tree(0));
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int z = 2 * n - 1;
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			std::pair<tree *, tree *> p = split(root, y - 1);
			tree *k = lmost(p.second);
			if (!k->val) {
				--z;
				k->val = true;
			}
			root = merge(p.first, merge(new tree(0), p.second));
		}
		printf("%d\n", ncr(z, n));
		root->clear = 1;
	}
	return 0;
}