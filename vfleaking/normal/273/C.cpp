#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MaxN = 300000;

int main()
{
	int n, m;
	static vector<int> adj[MaxN + 1];

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	static int res[MaxN + 1];
	static bool book[MaxN + 1];
	static queue<int> q;
	for (int i = 1; i <= n; i++)
		book[i] = true, q.push(i);

	while (!q.empty())
	{
		int v = q.front();
		book[v] = false, q.pop();

		int cnt;

		cnt = 0;
		for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
			if (res[*i] == res[v])
				cnt++;
		if (cnt < 2)
			continue;

		res[v] = res[v] ^ 1;
		for (vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
			if (res[*i] == res[v])
			{
				cnt = 0;
				for (vector<int>::iterator j = adj[*i].begin(); j != adj[*i].end(); j++)
					if (res[*i] == res[*j])
						cnt++;
				if (cnt >= 2 && !book[*i])
					book[*i] = true, q.push(*i);
			}
	}

	for (int i = 1; i <= n; i++)
		printf("%d", res[i]);
	cout << endl;

	return 0;
}