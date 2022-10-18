#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxN = 100000;
const int MaxLogN = 17;

inline int getint()
{
	char c;
	while (c = getchar(), '0' > c || c > '9');

	int res = c - '0';
	while (c = getchar(), '0' <= c && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int n;
int father[MaxN + 1][MaxLogN + 1];
vector<int> adj[MaxN + 1];

int number[MaxN + 1];
int exitTime[MaxN + 1];
int depth[MaxN + 1];
vector<int> level[MaxN + 1];

int nVis = 0;
void dfs(const int &cur)
{
	number[cur] = nVis++;
	level[depth[cur]].push_back(number[cur]);

	for (int i = 1, j = father[cur][0]; j != 0; i++)
		j = father[cur][i] = father[j][i - 1];
	for (vector<int>::iterator i = adj[cur].begin();
		 i != adj[cur].end();
		 i++)
	{
		depth[*i] = depth[cur] + 1;
		dfs(*i);
	}
	exitTime[cur] = nVis;
}

inline int getFather(const int &v, const int &p)
{
	int res = v;
	for (int i = 0; (1 << i) <= p; i++)
		if (p & 1 << i)
			res = father[res][i];
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		father[i][0] = getint();
		adj[father[i][0]].push_back(i);
	}

	depth[0] = 0;
	dfs(0);

	int q;
	cin >> q;

	while (q--)
	{
		int v = getint(), p = getint();
		int d = depth[v];
		int f = getFather(v, p);

		if (f == 0)
			printf("0 ");
		else
		{
			int nPSon =
				  lower_bound(level[d].begin(), level[d].end(),
						      exitTime[f])
				- lower_bound(level[d].begin(), level[d].end(),
						      number[f]);
			printf("%d ", nPSon - 1);
		}
	}

	return 0;
}