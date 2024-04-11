#include <bits/stdc++.h>

using namespace std;

namespace program
{
	const int MAXN = 100000;
	int n, m, tot, Deg[MAXN + 10], E[MAXN + 10];
	vector<int> R[MAXN + 10];
	queue<int> Q0, Q1;

	void work()
	{
		tot = 0;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%d", &E[i]);
		memset(Deg, 0, sizeof(int) * n);
		while(m--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			R[v].push_back(u);
			Deg[u]++;
		}
		for(int i = 0; i < n; i++)
			if(!Deg[i])
			{
				if(!E[i])
					Q0.push(i);
				else
					Q1.push(i);
			}
		while(!Q0.empty() || !Q1.empty())
		{
			int f = 0;
			while(!Q0.empty())
			{
				int u = Q0.front();
				Q0.pop();
				for(vector<int>::iterator p = R[u].begin(); p != R[u].end(); p++)
				{
					int v = *p;
					if(!--Deg[v])
					{
						if(!E[v])
							Q0.push(v);
						else
							Q1.push(v);
					}
				}
			}
			while(!Q1.empty())
			{
				f = 1;
				int u = Q1.front();
				Q1.pop();
				for(vector<int>::iterator p = R[u].begin(); p != R[u].end(); p++)
				{
					int v = *p;
					if(!--Deg[v])
					{
						if(!E[v])
							Q0.push(v);
						else
							Q1.push(v);
					}
				}
			}
			tot += f;
		}
		printf("%d\n", tot);
	}
}

int main()
{
	program::work();
	return 0;
}