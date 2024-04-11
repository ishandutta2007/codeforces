#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<pair<int, int> > > g(N);
	while (M--)
	{
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		u--, v--;
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}
	vector<long long> dist(N, (long long)1e16);
	dist[0] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int> >,
	greater<pair<long long, int> > > q;
	q.push(make_pair(0, 0));
	vector<int> parent(N, -1);
	while (!q.empty())
	{
		long long d = q.top().first;
		int v = q.top().second;
		q.pop();
		if (v == N - 1)
			break;
		if (dist[v] != d)
			continue;
		for (int i = 0; i < (int) g[v].size(); i++)
		{
			int t = g[v][i].first;
			long long total = g[v][i].second + d;
			if (total < dist[t])
			{
				dist[t] = total;
				q.push(make_pair(total, t));
				parent[t] = v;
			}
		}
	}
	if (parent[N - 1] == -1)
	{
		printf("-1\n");
	}
	else
	{
		vector<int> ans;
		ans.push_back(N - 1);
		int v = N - 1;
		while (v)
		{
			v = parent[v];
			ans.push_back(v);
		}
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("%d ", ans[i] + 1);
		}
	}
 return 0;
}