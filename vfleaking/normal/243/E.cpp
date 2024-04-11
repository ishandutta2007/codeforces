#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 500;

const int PQ_P = -1;
const int PQ_Q = -2;

struct node
{
	int v;
	node *son, *bro;

	bool has, full;
};
node pool[MaxN * 4], *tail = pool;
node *unused = NULL;

int n;
node *root;

inline node *pq_new()
{
	if (unused)
	{
		node *p = unused;
		unused = unused->bro;
		return p;
	}
	else
		return tail++;
}
inline void pq_delete(node *p)
{
	p->bro = unused;
	unused = p;
}

inline node *pq_new_subtree(node *p, int type)
{
	if (p->bro)
	{
		node *np = pq_new();
		np->v = type;
		np->son = p;
		np->bro = NULL;
		return np;
	}
	else
		return p;
}

inline node **pq_tail(node *p)
{
	node **last = &p;
	while (p)
	{
		last = &p->bro;
		p = p->bro;
	}
	return last;
}
inline void pq_cat(node *p, node *q)
{
	*pq_tail(p) = q;
}

inline node *pq_reverse_bro(node *p)
{
	node *prev = NULL, *next;
	for (node *i = p; i; i = next)
	{
		next = i->bro;
		i->bro = prev;
		prev = i;
	}
	return prev;
}
inline void pq_reverse(node *p)
{
	p->son = pq_reverse_bro(p->son);
}

inline bool pq_check_right(node *p)
{
	int st = 0;
	int cnt[3] = {0, 0, 0};
	for (node *s = p->son; s; s = s->bro)
	{
		int cur = 0;
		if (s->has)
		{
			cur++;
			if (s->full)
				cur++;
		}
		if (cur < st)
			return false;
		cnt[cur]++;
		st = cur;
	}

	return cnt[1] <= 1;
}
inline bool pq_align_right(node *p)
{
	if (p->v == PQ_P)
	{
		node *h = NULL;
		node **slast = &p->son;
		node **hlast = &h;
		for (node *s = p->son; s; s = s->bro)
		{
			if (s->has && !s->full)
				*hlast = s, hlast = &s->bro;
			else
				*slast = s, slast = &s->bro;
		}
		*slast = NULL;

		slast = &p->son;
		for (node *s = p->son; s; s = s->bro)
		{
			if (s->full)
				*hlast = s, hlast = &s->bro;
			else
				*slast = s, slast = &s->bro;
		}
		*slast = h;
		*hlast = NULL;
		return pq_check_right(p);
	}
	else
	{
		if (pq_check_right(p))
			return true;
		pq_reverse(p);
		return pq_check_right(p);
	}
}
inline node *pq_split_at_has(node *p)
{
	for (node *s = p->son, **prev = &p->son; s; prev = &s->bro, s = s->bro)
		if (s->has)
		{
			*prev = NULL;
			return s;
		}
	return NULL;
}
inline int pq_nsides(node *p)
{
	int cnt = 0;
	while (p && (p->has && !p->full))
		cnt++, p = p->bro;
	return cnt;
}

void pq_init()
{
	root = tail++;
	root->v = PQ_P, root->son = NULL, root->bro = NULL;

	node **last = &root->son;
	for (int v = 0; v < n; v++)
	{
		node *p = tail++;
		p->v = v, p->son = NULL, p->bro = NULL, *last = p;
		last = &p->bro;
	}
}

void pq_export_dfs(node *p, int *&out)
{
	for (node *s = p->son; s; s = s->bro)
	{
		if (s->v >= 0)
			*out++ = s->v;
		else
			pq_export_dfs(s, out);
	}
}
void pq_export(int *out)
{
	pq_export_dfs(root, out);
}

void pq_print(node *p, int dep)
{
	for (int i = 0; i < dep - 1; i++)
		cerr << "    ";
	if (dep > 0)
		cerr << "---|";
	if (p->v >= 0)
		cerr << p->v;
	else if (p->v == PQ_P)
		cerr << "P";
	else if (p->v == PQ_Q)
		cerr << "Q";
	cerr << endl;
	for (node *s = p->son; s; s = s->bro)
		pq_print(s, dep + 1);
}

char *pq_commit_cond;
bool pq_commit_succeeded;

void pq_commit_pre_dfs(node *p)
{
	if (p->v >= 0)
		p->has = p->full = pq_commit_cond[p->v] == '1';
	else
	{
		p->has = false;
		p->full = true;
		for (node *s = p->son; s; s = s->bro)
		{
			pq_commit_pre_dfs(s);
			if (s->has)
				p->has = true;
			if (!s->full)
				p->full = false;
		}
	}
}

void pq_commit_dfs(node *p)
{
	if (p->v >= 0)
		return;

	if (p->v == PQ_P)
	{
		pq_align_right(p);
		node *h = pq_split_at_has(p);
		if (!p->son)
		{
			p->son = h;
			int nsides = pq_nsides(h);
			if (nsides == 0)
				return;
			else if (nsides == 1)
			{
				node *np = h;
				node *nq = pq_new_subtree(h->bro, PQ_P);
				nq->has = nq->full = true;
				p->v = PQ_Q;
				p->son = np, np->bro = nq, nq->bro = NULL;
			}
			else if (nsides == 2)
			{
				node *npl = h, *npr = h->bro;
				p->v = PQ_Q;

				if (h->bro->bro)
				{
					node *nq = pq_new_subtree(h->bro->bro, PQ_P);
					nq->has = nq->full = true;
					p->son = npl, npl->bro = nq, nq->bro = npr, npr->bro = NULL;
				}
				else
					p->son = npl, npl->bro = npr, npr->bro = NULL;
			}
			else
			{
				pq_commit_succeeded = false;
				return;
			}
		}
		else
		{
			node *np = pq_new_subtree(h, PQ_P);
			np->bro = p->son, p->son = np;
			pq_commit_dfs(np);
			return;
		}
	}

	node *fs = NULL, *ls = NULL;
	for (node *s = p->son; s; s = s->bro)
		if (s->has)
		{
			if (!fs)
				fs = s;
			ls = s;
		}
	if (fs == ls)
	{
		pq_commit_dfs(fs);
		return;
	}
	for (node *s = fs->bro; s != ls; s = s->bro)
		if (!s->full)
		{
			pq_commit_succeeded = false;
			return;
		}

	for (int ti = 0; ti <= 1; ti++)
	{
		if (ti == 1)
		{
			pq_reverse(p);
			swap(fs, ls);
		}
		while (!fs->full)
		{
			if (!pq_align_right(fs))
			{
				pq_commit_succeeded = false;
				return;
			}
			node *h = pq_split_at_has(fs);
			if (fs->v == PQ_P)
			{
				int nsides = pq_nsides(h);
				if (nsides == 0)
				{
					h = pq_new_subtree(h, PQ_P);
					h->has = h->full = true;
				}
				else
					h->bro = h->bro ? pq_new_subtree(h->bro, PQ_P) : NULL;
			}
			else
			{
				if (fs->son)
				{
					node *nfs = fs->son;
					while (nfs->bro)
						nfs = nfs->bro;
					nfs->bro = fs->bro;
					fs->bro = fs->son;
					fs->son = NULL;
					fs = nfs;
				}
			}
			pq_cat(h, fs->bro);
			fs->bro = h;
			fs = fs->bro;
		}
		if (ti == 1)
		{
			pq_reverse(p);
			swap(fs, ls);
		}
	}
	for (node *s = p->son, **prev = &p->son; s; s = *prev)
	{
		if (s->v < 0)
		{
			if (!s->son)
			{
				*prev = s->bro;
				pq_delete(s);
			}
			else if (!s->son->bro)
			{
				*prev = s->son, s->son->bro = s->bro;
				pq_delete(s);
			}
			else
				prev = &s->bro;
		}
		else
			prev = &s->bro;
	}
}

bool pq_commit(char *cond)
{
	pq_commit_cond = cond;
	pq_commit_pre_dfs(root);
	if (!root->has)
		return true;
	pq_commit_succeeded = true;
	pq_commit_dfs(root);

	/*
	cerr << endl;
	cerr << "commit:";
	for (int v = 0; v < n; v++)
		if (cond[v] == '1')
			cerr << " " << v;
	cerr << endl;
	pq_print(root, 0);
	*/
	return pq_commit_succeeded;
}

int main()
{
	static char mat[MaxN][MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];

	pq_init();

	for (int i = 0; i < n; i++)
		if (!pq_commit(mat[i]))
		{
			cout << "NO" << endl;
			return 0;
		}

	static int res[MaxN];
	pq_export(res);

	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << mat[i][res[j]];
		cout << endl;
	}
	return 0;
}