#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MaxNum = 314000000;

const int MaxN = 100000;
const int MaxM = 100000;

int m, n;
int deg[MaxN + 1];
vector<int> spTo[MaxN + 1];
vector<int> spFrom[MaxN + 1];

int rules_d[MaxM];
int rules_fL[MaxM];
int rules_c[MaxM];
int rules_v[MaxM];
vector<int> rules[MaxM];

int visited[MaxN + 1];
int fL[MaxN + 1], fR[MaxN + 1];

template <class T>
inline int size(const T &t)
{
	return (int)t.size();
}

void dfs(int v)
{
	if (visited[v] == 1)
	{
		fR[v] = -2;
		return;
	}
	if (visited[v] == 2)
		return;
	if (fL[v] == -1)
	{
		fR[v] = -1;
		return;
	}

	visited[v] = 1;
	fR[v] = fL[v];
	for (int i = 0; i < size(spTo[v]); i++)
	{
		int t = spTo[v][i];
		int cur = 0;
		for (int j = 0; j < size(rules[t]); j++)
		{
			int u = rules[t][j];
			if (fL[u] == -1)
			{
				cur = -1;
				break;
			}
		}
		if (cur == -1)
			continue;
		cur += rules_d[t];
		for (int j = 0; j < size(rules[t]); j++)
		{
			int u = rules[t][j];
			dfs(u);
			if (fR[u] == -2)
			{
				fR[v] = -2;
				visited[v] = 2;
				return;
			}
			cur = min(cur + fR[u], MaxNum);
		}
		if (cur > fR[v])
			fR[v] = cur;
	}
	visited[v] = 2;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		int v, l;
		scanf("%d %d", &v, &l);
		rules_v[i] = v;
		for (int k = 0; k < l; k++)
		{
			int u;
			scanf("%d", &u);
			if (u == -1)
				rules_d[i]++;
			else
			{
				rules[i].push_back(u);
				spFrom[u].push_back(i);
			}
		}
		rules_fL[i] = rules_d[i];
		rules_c[i] = size(rules[i]);
		spTo[v].push_back(i);
	}

	priority_queue< pair<int, int> > q;
	for (int v = 1; v <= n; v++)
	{
		fL[v] = -1;
		for (int i = 0; i < size(spTo[v]); i++)
		{
			int t = spTo[v][i];
			if (size(rules[t]) == 0 && (fL[v] == -1 || rules_d[t] < fL[v]))
				fL[v] = rules_d[t];
		}
		if (fL[v] != -1)
			q.push(make_pair(-fL[v], v));
	}
	while (!q.empty())
	{
		pair<int, int> cur = q.top();
		q.pop();

		if (-cur.first != fL[cur.second])
			continue;

		int v = cur.second;
		for (int i = 0; i < size(spFrom[v]); i++)
		{
			int t = spFrom[v][i];
			int u = rules_v[t];
			rules_fL[t] = min(rules_fL[t] + fL[v], MaxNum);
			if (--rules_c[t] == 0 && (fL[u] == -1 || rules_fL[t] < fL[u]))
			{
				fL[u] = rules_fL[t];
				q.push(make_pair(-fL[u], u));
			}
		}
	}

	for (int v = 1; v <= n; v++)
		dfs(v);

	for (int v = 1; v <= n; v++)
		printf("%d %d\n", fL[v], fR[v]);

	return 0;
}