#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;

struct node
{
	node *fa, *lc, *rc;
	int val;
	node *cor;

	int size;

	void update()
	{
		size = 1;
		if (lc)
			size += lc->size;
		if (rc)
			size += rc->size;
	}
};

inline void rotate(node *x)
{
	node *y = x->fa, *z = y->fa;
	node *b = x == y->lc ? x->rc : x->lc;
	x->fa = z, y->fa = x;
	if (b)
		b->fa = y;
	if (z)
		(z->lc == y ? z->lc : z->rc) = x;
	if (x == y->lc)
		x->rc = y, y->lc = b;
	else
		x->lc = y, y->rc = b;
	y->update();
}
inline void splay(node *&root, node *x, node *target = NULL)
{
	while (x->fa != target)
	{
		if (x->fa->fa != target)
		{
			if ((x->fa->lc == x) == (x->fa->fa->lc == x->fa))
				rotate(x->fa);
			else
				rotate(x);
		}
		rotate(x);
	}
	x->update();
	if (target == NULL)
		root = x;
}
inline void erase(node *&root, node *x)
{
	splay(root, x);
	if (!x->lc)
	{
		if (x->rc)
			x->rc->fa = NULL;
		root = x->rc;
	}
	else
	{
		node *prev = x->lc;
		while (prev->rc)
			prev = prev->rc;
		splay(root, prev, x);
		prev->rc = x->rc;
		if (x->rc)
			x->rc->fa = prev;
		prev->update();
		prev->fa = NULL, root = prev;
	}
}

inline int getRank(node *&root, node *x)
{
	splay(root, x);
	return (x->lc ? x->lc->size : 0) + 1;
}

node pool[MaxN * 2], *tail = pool;

node *seq;
node *bt[MaxN + 1];

node *seq_find(int r)
{
	node *p = seq;
	while (true)
	{
		int lsize = p->lc ? p->lc->size : 0;
		if (r < lsize + 1)
			p = p->lc;
		else if (r > lsize + 1)
			r -= lsize + 1, p = p->rc;
		else
			return p;
	}
}
void orz_insert(node *&root, node *x)
{
	node **p = &root, *q = NULL;
	while (*p)
	{
		q = *p;
		if (getRank(seq, x->cor) < getRank(seq, (*p)->cor))
			p = &(*p)->lc;
		else
			p = &(*p)->rc;
	}
	*p = x;
	x->fa = q;
	x->lc = x->rc = NULL;
	splay(root, x);
}
void seq_rotate(int l, int r)
{
	if (l == r)
		return;
	node *x = seq_find(l);
	node *y = seq_find(r);
	erase(seq, y), y->lc = y->rc = NULL, y->update();
	splay(seq, x);
	if (!x->lc)
		x->lc = y, y->fa = x, x->update();
	else
	{
		node *prev = x->lc;
		while (prev->rc)
			prev = prev->rc;
		splay(seq, prev, x);
		prev->rc = y, y->fa = prev;
		prev->update(), x->update();
	}

	erase(bt[y->val], y->cor);
	orz_insert(bt[y->val], y->cor);
}
int orz_cnt(node *&root, int r)
{
	node *p = root, *q = NULL;
	int cnt = 0;
	while (p)
	{
		q = p;
		if (r < getRank(seq, p->cor))
			p = p->lc;
		else
			cnt += (p->lc ? p->lc->size : 0) + 1, p = p->rc;
	}
	if (q)
		splay(root, q);
	return cnt;
}

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)
	{
		node *p = tail++, *q = tail++;

		p->lc = seq;
		if (seq)
			seq->fa = p;
		p->val = a[i];
		p->update();
		seq = p;

		q->cor = p, p->cor = q;
		orz_insert(bt[a[i]], q);
	}

	int lastans = 0;
	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			l = (l + lastans - 1) % n + 1;
			r = (r + lastans - 1) % n + 1;
			if (l > r)
				swap(l, r);
			seq_rotate(l, r);
		}
		else
		{
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			l = (l + lastans - 1) % n + 1;
			r = (r + lastans - 1) % n + 1;
			k = (k + lastans - 1) % n + 1;
			if (l > r)
				swap(l, r);
			printf("%d\n", lastans = orz_cnt(bt[k], r) - orz_cnt(bt[k], l - 1));
		}
	}

	return 0;
}