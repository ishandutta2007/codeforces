#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;
const int MaxC = 100000;
const int L = 317;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}

struct halfEdge
{
	int u;
	halfEdge *next;
};
halfEdge adj_pool[(MaxN - 1) * 2], *adj_tail = adj_pool;

int n, m;
int col[MaxN + 1];
halfEdge *adj[MaxN + 1];

vector<pair<int, int> > qOnV[MaxM + 1];
int qRes[MaxM + 1];

inline void addEdge(const int &v, const int &u)
{
	adj_tail->u = u, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int *preAns[MaxN + 1];
vector<int> *big[MaxN + 1];
map<int, int> *corCN[MaxN + 1];
void dfs(const int &v, const int &fa)
{
	corCN[v] = new map<int, int>();
	(*corCN[v])[col[v]]++;

	preAns[v] = new int[L + 1];
	fill(preAns[v], preAns[v] + L + 1, 0);
	preAns[v][1]++;

	big[v] = new vector<int>();

	for (halfEdge *e = adj[v]; e; e = e->next)
		if (e->u != fa)
		{
			dfs(e->u, v);

			if (corCN[v]->size() < corCN[e->u]->size())
			{
				swap(corCN[v], corCN[e->u]);
				swap(preAns[v], preAns[e->u]);
				swap(big[v], big[e->u]);
			}
			for (map<int, int>::iterator it = corCN[e->u]->begin(); it != corCN[e->u]->end(); it++)
			{
				int &cur = (*corCN[v])[it->first];
				int after = cur + it->second;
				if (cur == 0)
				{
					if (after <= L)
						preAns[v][after]++;
					else
						big[v]->push_back(it->first);
				}
				else
				{
					if (cur <= L)
					{
						preAns[v][cur]--;
						if (after <= L)
							preAns[v][after]++;
						else
							big[v]->push_back(it->first);
					}
				}
				cur = after;
			}
		}

	preAns[v][L] += (int)big[v]->size();
	for (int i = L - 1; i >= 0; i--)
		preAns[v][i] += preAns[v][i + 1];
	vector<int> bigCN;
	for (vector<int>::iterator it = big[v]->begin(); it != big[v]->end(); it++)
		bigCN.push_back((*corCN[v])[*it]);

	for (vector<pair<int, int> >::iterator iq = qOnV[v].begin(); iq != qOnV[v].end(); iq++)
	{
		if (iq->first <= L)
			qRes[iq->second] = preAns[v][iq->first];
		else
		{
			qRes[iq->second] = 0;
			for (vector<int>::iterator it = bigCN.begin(); it != bigCN.end(); it++)
				if (*it >= iq->first)
					qRes[iq->second]++;
		}
	}

	for (int i = 0; i <= L - 1; i++)
		preAns[v][i] -= preAns[v][i + 1];
	preAns[v][L] -= (int)big[v]->size();
}

int main()
{
	cin >> n >> m;
	for (int v = 1; v <= n; v++)
		scanf("%d", &col[v]);
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}
	for (int i = 1; i <= m; i++)
	{
		int v, k;
		scanf("%d %d", &v, &k);
		qOnV[v].push_back(make_pair(k, i));
	}

	dfs(1, 0);

	for (int i = 1; i <= m; i++)
		printf("%d\n", qRes[i]);

	return 0;
}