#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

// persistent segment tree impl: sum tree
namespace pstree {
	typedef int val_t;
	const int DEPTH = 20;
	const int TSIZE = 1 << 20;

	const int MAX_QUERY = 100005;
	struct node {
		val_t v;
		bool fliped;
		node *l, *r;
	} npoll[TSIZE * 2 + MAX_QUERY * (DEPTH + 1)];
	int pptr, last_q;
	node *head[MAX_QUERY + 1];
	void init() {
		// zero-initialize, can be changed freely
		for (int i = TSIZE - 2; i >= 0; i--) {
			npoll[i].v = 0;
			npoll[i].l = &npoll[i * 2 + 1];
			npoll[i].r = &npoll[i * 2 + 2];
		}
		head[0] = &npoll[0];
		last_q = 0;
		pptr = 2 * TSIZE - 1;
	}

	bool flipped(int t, int idx)
	{
		node *now = head[t];

		int flag = 1 << 10;

		for (;;)
		{
			flag >>= 1;
			if (flag == 0) break;

			if (flag & idx) {
				now = now->r;
			}
			else {
				now = now->l;
			}
		}

		return now->fliped;
	}

	int flip(int idx, int prev)
	{
		head[++last_q] = &npoll[pptr++];
		node *old = head[prev], *now = head[last_q];

		vector<node *> nodes;
		int flag = 1 << 10;

		for (;;)
		{
			nodes.push_back(now);
			flag >>= 1;
			if (flag == 0)
			{
				now->l = old->l;
				now->r = old->r;
				now->fliped = old->fliped;
				break;
			}

			if (flag & idx) {
				now->l = old->l;
				now->r = &npoll[pptr++];
				now = now->r, old = old->r;
			}
			else {
				now->r = old->r;
				now->l = &npoll[pptr++];
				now = now->l, old = old->l;
			}
		}

		nodes.back()->fliped = !nodes.back()->fliped;
		for (int i = nodes.size() - 1; i >= 0; i--)
		{
			nodes[i]->v = nodes[i]->l->v + nodes[i]->r->v;
			if (nodes[i]->fliped) nodes[i]->v = m - nodes[i]->v;
		}

		return last_q;
	}

	int update(int pos, int val, int prev) {
		head[++last_q] = &npoll[pptr++];
		node *old = head[prev], *now = head[last_q];

		vector<node *> nodes;
		int flag = 1 << DEPTH;

		for (;;) {
			nodes.push_back(now);
			flag >>= 1;
			if (flag == 0) break;
			now->fliped = old->fliped;
			if (flag & pos) {
				now->l = old->l;
				now->r = &npoll[pptr++];
				now = now->r, old = old->r;
			}
			else {
				now->r = old->r;
				now->l = &npoll[pptr++];
				now = now->l, old = old->l;
			}
		}

		nodes.back()->v = val;

		for (int i = nodes.size() - 2; i >= 0; i--)
		{
			nodes[i]->v = nodes[i]->l->v + nodes[i]->r->v;
			if (nodes[i]->fliped) nodes[i]->v = m - nodes[i]->v;
		}

		return last_q;
	}

	val_t query(int s, int e, int l, int r, node *n) {
		if (s == l && e == r) return n->v;
		int m = (l + r) / 2;
		if (m >= e) return query(s, e, l, m, n->l);
		else if (m < s) return query(s, e, m + 1, r, n->r);
		else return query(s, m, l, m, n->l) + query(m + 1, e, m + 1, r, n->r);
	}

	// query summation of [s, e] at time t
	val_t query(int s, int e, int t) {
		s = max(0, s); e = min(TSIZE - 1, e);
		if (s > e) return 0;
		return query(max(0, s), min(TSIZE - 1, e), 0, TSIZE - 1, head[t]);
	}
}

int tim[100005];

int main()
{
	pstree::init();

	int q;
	scanf("%d%d%d", &n, &m, &q);

	tim[0] = 0;
	for (int i = 1; i <= q; i++)
	{
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
		case 2:
		{
			a &= 1;
			int b, c;
			scanf("%d%d", &b, &c);
			b--; c--;
			a ^= pstree::flipped(tim[i - 1], b);
			tim[i] = pstree::update(b * 1024 + c, a, tim[i - 1]);
		}
		break;
		case 3:
		{
			int b;
			scanf("%d", &b);
			tim[i] = pstree::flip(--b, tim[i - 1]);
		}
		break;
		case 4:
		{
			int b;
			scanf("%d", &b);
			tim[i] = tim[b];
		}
		break;
		}

		printf("%d\n", pstree::query(0, 1024 * 1024 - 1, tim[i]));
	}
}