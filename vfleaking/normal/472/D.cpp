#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxN = 2000;

int n;
int dist[MaxN + 1][MaxN + 1];

bool dfs(int v, vector<int> li)
{
	while (!li.empty())
	{
		int s = -1;
		for (int i = 0; i < (int)li.size(); i++)
			if (s == -1 || dist[v][li[i]] < dist[v][s])
				s = li[i];

		int li_n = 0;
		vector<int> nextLi;
		for (int i = 0; i < (int)li.size(); i++)
		{
			int u = li[i];
			if (dist[v][u] == dist[v][s] + dist[s][u])
				nextLi.push_back(u);
			else
				li[li_n++] = u;
		}
		li.resize(li_n);

		for (int i = 0; i < (int)li.size(); i++)
			for (int j = 0; j < (int)nextLi.size(); j++)
				if (dist[v][li[i]] + dist[v][nextLi[j]] != dist[li[i]][nextLi[j]])
					return false;

		for (int i = 0; i < (int)nextLi.size(); i++)
			if (nextLi[i] == s)
				swap(nextLi[i], nextLi.back());
		nextLi.pop_back();
		if (!dfs(s, nextLi))
			return false;
	}
	return true;
}

int main()
{
	cin >> n;
	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			scanf("%d", &dist[v][u]);

	for (int v = 1; v <= n; v++)
		for (int u = 1; u < v; u++)
			if (dist[v][u] != dist[u][v] || dist[v][u] == 0)
			{
				puts("NO");
				return 0;
			}
	for (int v = 1; v <= n; v++)
		if (dist[v][v] != 0)
		{
			puts("NO");
			return 0;
		}


	vector<int> li;
	for (int v = 2; v <= n; v++)
		li.push_back(v);
	puts(dfs(1, li) ? "YES" : "NO");

	return 0;
}