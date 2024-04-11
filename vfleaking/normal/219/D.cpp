#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

const int MaxN = 200000;

struct halfEdge
{
	int u, l;
	halfEdge *next;
};

int n;
halfEdge pool[MaxN * 2];
halfEdge *tail = pool;
halfEdge* adj[MaxN + 1];

inline void addEdge(const int &v, const int &u, const int &l)
{
	tail->u = u, tail->l = l, tail->next = adj[v];
	adj[v] = tail++;
}

int down[MaxN + 1];
int up[MaxN + 1];

void calcDown(const int &cur, const int &father)
{
	down[cur] = 0;
	for (halfEdge *i = adj[cur]; i; i = i->next)
		if (i->u != father)
		{
			calcDown(i->u, cur);
			down[cur] += down[i->u] + i->l;
		}
}
void calcUp(const int &cur, const int &father, const int &fl)
{
	for (halfEdge *i = adj[cur]; i; i = i->next)
		if (i->u != father)
		{
			up[i->u] = 0;
			if (i->l == 0)
				up[i->u] += 1;
			up[i->u] += down[cur] - (i->l + down[i->u]);
			up[i->u] += up[cur];

			calcUp(i->u, cur, i->l == 0 ? 1 : 0);
		}
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);

		addEdge(v, u, 0);
		addEdge(u, v, 1);
	}

	calcDown(1, 0);

	up[0] = 0;
	up[1] = 0;
	calcUp(1, 0, 0);

	int value = INT_MAX;
	vector<int> res;

	for (int i = 1; i <= n; i++)
	{
		int t = up[i] + down[i];
		if (t == value)
			res.push_back(i);
		else if (t < value)
		{
			value = t;
			res.clear();
			res.push_back(i);
		}
	}

	cout << value << endl;
	for (vector<int>::iterator i = res.begin(); i != res.end(); i++)
		printf("%d ", *i);
	cout << endl;

	return 0;
}