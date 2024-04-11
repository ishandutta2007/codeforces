#include <bits/stdc++.h>
using namespace std;

// example : https://www.acmicpc.net/problem/13159
struct node {
	node *l = nullptr, *r = nullptr, *p = nullptr;
	int key = 0, cnt = 0, val = 0, lazy = 0;
} *tree;

void Update(node *x) {
	x->cnt = 1;
	if (x->l) x->cnt += x->l->cnt;
	if (x->r) x->cnt += x->r->cnt;
}

void Lazy(node *x) {
	if (x->l) {
		x->l->lazy += x->lazy;
		x->l->key += x->lazy;
		x->l->val += x->lazy;
	}
	if (x->r) {
		x->r->lazy += x->lazy;
		x->r->key += x->lazy;
		x->r->val += x->lazy;
	}
	x->lazy = 0;
}

void Rotate(node *x) {
	node *p = x->p;
	node *b;
	if (x == p->l) {
		p->l = b = x->r;
		x->r = p;
	}
	else {
		p->r = b = x->l;
		x->l = p;
	}
	x->p = p->p;
	p->p = x;
	if (b) b->p = p;
	(x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
	Update(p);
	Update(x);
}

void Splay(node *x) {
	while (x->p) {
		node *p = x->p;
		node *g = p->p;
		if (g) Rotate((x == p->l) == (p == g->l) ? p : x);
		Rotate(x);
	}
}

void Insert(int key, int val) {
	node *p = tree, **pp;
	if (!p) {
		node *x = new node;
		tree = x;
		x->l = x->r = x->p = NULL;
		x->key = key;
		x->val = val;
		x->cnt = 1;
		return;
	}
	while (1) {
		Lazy(p);
		if (key == p->key) return;
		if (key < p->key) {
			if (!p->l) {
				pp = &p->l;
				break;
			}
			p = p->l;
		}
		else {
			if (!p->r) {
				pp = &p->r;
				break;
			}
			p = p->r;
		}
	}
	node *x = new node;
	*pp = x;
	x->l = x->r = NULL;
	x->p = p;
	x->key = key;
	x->val = val;
	Splay(x);
}

void Lower(int key) {
	node *p = tree;
	Lazy(p);
	node *hubo = nullptr;
	while (p) {
		if (key <= p->key) {
			if (!p->l) break;
			p = p->l;
			Lazy(p);
		}
		else {
			hubo = p;
			if (!p->r) break;
			p = p->r;
			Lazy(p);
		}
	}
	Splay(hubo);
}

void Upper(int key) {
	node *p = tree;
	Lazy(p);
	node *hubo = nullptr;
	while (p) {
		if (key < p->key) {
			hubo = p;
			if (!p->l) break;
			p = p->l;
			Lazy(p);
		}
		else {
			if (!p->r) break;
			p = p->r;
			Lazy(p);
		}
	}
	Splay(hubo);
}

void Find_Kth(int k) {
	node *x = tree;
	Lazy(x);
	while (1) {
		while (x->l && x->l->cnt > k) {
			x = x->l;
			Lazy(x);
		}
		if (x->l) k -= x->l->cnt;
		if (!k--) break;
		x = x->r;
		Lazy(x);
	}
	Splay(x);
}

void Interval(int l, int r) {
	Find_Kth(l - 1);
	node *x = tree;
	tree = x->r;
	tree->p = NULL;
	Find_Kth(r - l + 1);
	x->r = tree;
	tree->p = x;
	tree = x;
}

void Add(int l, int r) {
	Interval(l, r);
	node *x = tree->r->l;
	x->lazy++;
	x->key++;
	x->val++;
}

void Delete() {
	node *p = tree;
	if (p->l) {
		if (p->r) {
			tree = p->l;
			tree->p = NULL;
			node *x = tree;
			while (x->r) x = x->r;
			x->r = p->r;
			p->r->p = x;
			Splay(x);
			delete p;
			return;
		}
		tree = p->l;
		tree->p = NULL;
		delete p;
		return;
	}
	if (p->r) {
		tree = p->r;
		tree->p = NULL;
		delete p;
		return;
	}
	tree = NULL;
}

int ans;

void dfs(node *t)
{
	if (t->val < (int)2e9) ans = max(ans, t->val);
	if (t->l) dfs(t->l);
	if (t->r) dfs(t->r);
}

int main()
{
	int n;
	scanf("%d", &n);

	Insert(0, 0);
	Insert(2e9, 2e9);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (i == 0)
		{
			Insert(a, 1);
			continue;
		}

		Upper(b - 1);
		if (tree->val >= 1 && tree->val < (int)2e9) Delete();

		Lower(a);
		int akey = tree->val + 1;

		Upper(a - 1);
		int L = (tree->l ? tree->l->cnt : 0);
		Lower(b);
		int R = (tree->l ? tree->l->cnt : 0);
		if (L <= R) Add(L, R);
		Insert(a, akey);
	}

	dfs(tree);

	printf("%d\n", ans);
}