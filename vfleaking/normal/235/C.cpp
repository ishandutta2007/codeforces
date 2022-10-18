#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int NLet = 26;
const int MaxN = 1000000;
const int MaxL = 1000000;

struct sa_node
{
	sa_node *fa;
	sa_node *next[NLet];
	int lMax;
	int size;
};
sa_node sa_pool[MaxN * 2], *sa_tail;
sa_node *sa_root, *sa_last;

inline void sa_init()
{
	sa_tail = sa_pool;
	sa_last = sa_root = sa_tail++;
}
inline void sa_extend(int c)
{
	sa_node *p = sa_last;
	sa_node *np = sa_tail++;
	np->lMax = p->lMax + 1;
	np->size = 1;
	while (p && !p->next[c])
		p->next[c] = np, p = p->fa;
	if (!p)
		np->fa = sa_root;
	else
	{
		sa_node *q = p->next[c];
		if (q->lMax == p->lMax + 1)
			np->fa = q;
		else
		{
			sa_node *nq = sa_tail++;
			copy(q->next, q->next + NLet, nq->next);
			nq->lMax = p->lMax + 1;
			nq->fa = q->fa;
			np->fa = q->fa = nq;
			while (p && p->next[c] == q)
				p->next[c] = nq, p = p->fa;
		}
	}
	sa_last = np;
}

int main()
{
	sa_init();
	for (int c = getchar(); 'a' <= c && c <= 'z'; c = getchar())
		sa_extend(c - 'a');

	int que_n = 0;
	static int deg[MaxN * 2];
	static int que[MaxN * 2];

	for (int i = 0; i < (sa_tail - sa_pool); i++)
		if ((sa_pool + i)->fa)
			deg[(sa_pool + i)->fa - sa_pool]++;
	for (int i = 0; i < (sa_tail - sa_pool); i++)
		if (deg[i] == 0)
			que[que_n++] = i;
	for (int i = 0; i < que_n; i++)
		if ((sa_pool + que[i])->fa && --deg[(sa_pool + que[i])->fa - sa_pool] == 0)
			que[que_n++] = (sa_pool + que[i])->fa - sa_pool;
	for (int i = 0; i < que_n; i++)
		if ((sa_pool + que[i])->fa)
			(sa_pool + que[i])->fa->size += (sa_pool + que[i])->size;

	int nQ;
	cin >> nQ;
	for (int tq = 1; tq <= nQ; tq++)
	{
		static char q[MaxL + 1];
		static int qnext[MaxL + 1];
		scanf("%s", q);
		
		int q_n = strlen(q);

		qnext[0] = -1;
		for (int i = 1, j = -1; i < q_n; i++)
		{
			while (j >= 0 && q[j + 1] != q[i])
				j = qnext[j];
			if (q[j + 1] == q[i])
				j++;
			qnext[i] = j;
		}

		int per = qnext[q_n - 1] + 1;
		while (q_n % (q_n - per) != 0)
			per = qnext[per - 1] + 1;
		per = q_n - per;

		long long res = 0;
		int l = 0;
		sa_node *p = sa_root;
		for (int i = 0; i < q_n + per - 1; i++)
		{
			int c = q[i % q_n] - 'a';
			while (p != sa_root && !p->next[c])
				p = p->fa, l = p->lMax;
			if (p->next[c])
				p = p->next[c], l++;
			else
				l = 0;

			if (l > q_n)
			{
				l--;
				if (l == p->fa->lMax)
					p = p->fa;
			}

			if (l == q_n)
				res += p->size;
		}

		cout << res << endl;
	}

	return 0;
}