#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int NLetter = 26;
const int MaxN = 10;
const int MaxL = 50000;
const int MaxNNode = MaxL * (MaxN + 1) * 2 + 1;

struct node
{
	node *fa;
	map<int, node*> next;
	unsigned short cnt[MaxN + 1];
	int deg;
	int lMax;
};
node pool[MaxNNode], *tail = pool;

node *root;
node *lastP;

void sa_init()
{
	root = tail++;
}
void sa_extend(int c)
{
	node *p = lastP;
	node *np = tail++;
	np->lMax = p->lMax + 1;
	while (p && !p->next[c])
		p->next[c] = np, p = p->fa;
	if (!p)
		np->fa = root;
	else
	{
		node *q = p->next[c];
		if (q->lMax == p->lMax + 1)
			np->fa = q;
		else
		{
			node *nq = tail++;
			nq->next = q->next;
			nq->lMax = p->lMax + 1;
			nq->fa = q->fa;
			q->fa = np->fa = nq;
			while (p && p->next[c] == q)
				p->next[c] = nq, p = p->fa;
		}
	}
	lastP = np;
}

int main()
{
	int n;
	static char s[MaxL + 1];

	sa_init();

	scanf("%s", s);
	lastP = root;
	for (char *ps = s; *ps; ps++)
		sa_extend(*ps - 'a'), lastP->cnt[0]++;

	cin >> n;

	static int oL[MaxN + 1], oR[MaxN + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%s %d %d", s, &oL[i], &oR[i]);
		lastP = root;
		for (char *ps = s; *ps; ps++)
			sa_extend(*ps - 'a'), lastP->cnt[i]++;
	}

	int q_n = 0;
	static node *q[MaxNNode];
	for (node *p = pool; p != tail; p++)
		if (p->fa)
			p->fa->deg++;
	for (node *p = pool; p != tail; p++)
		if (p->deg == 0)
			q[q_n++] = p;

	int res = 0;
	for (int i = 0; i < q_n; i++)
	{
		node *p = q[i];

		if (p->fa)
		{
			if (p->cnt[0] > 0)
			{
				bool ok = true;
				for (int k = 1; k <= n; k++)
					if (!(oL[k] <= p->cnt[k] && p->cnt[k] <= oR[k]))
					{
						ok = false;
						break;
					}
				if (ok)
					res += p->lMax - p->fa->lMax;
			}

			for (int k = 0; k <= n; k++)
				p->fa->cnt[k] += p->cnt[k];
			if (--p->fa->deg == 0)
				q[q_n++] = p->fa;
		}
	}
	cout << res << endl;

	return 0;
}