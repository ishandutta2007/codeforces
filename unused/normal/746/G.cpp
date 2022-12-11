#include <bits/stdc++.h>
using namespace std;

int n, t, k;
int dat[200005];
int depth[200005];
vector<int> dvt[200005];
vector<int> child[200005];
int last;

void dfs1(int node, int depth)
{
	if (depth == t) return;

	for (int i = 0; i < dat[depth]; i++)
	{
		dvt[depth + 1].push_back(last);
		child[node].push_back(last++);
	}

	dfs1(child[node].front(), depth + 1);
}

int main()
{
	scanf("%d%d%d", &n, &t, &k);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &dat[i]);
	}

	int minval = 0;
	for (int i = 0; i < t; i++) minval += max(dat[i] - dat[i + 1], 0);
	int maxval = 1;
	for (int i = 0; i < t; i++) maxval += dat[i] - 1;
	if (minval > k || maxval < k)
	{
		printf("-1");
		return 0;
	}

	last = 1;
	dvt[0].push_back(0);
	dfs1(0, 0);

	for (int i = 1; i < t; i++)
	{
		int sub = min(min((int)child[dvt[i][0]].size() - 1, (int)dvt[i].size() - 1), maxval - k);

		for (int j = 0; j < sub; j++)
		{
			int z = child[dvt[i][0]].back();
			child[dvt[i][0]].pop_back();
			child[dvt[i][j + 1]].push_back(z);
		}

		maxval -= sub;
		if (maxval == k) break;
	}

	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j : child[i])
		{
			printf("%d %d\n", i + 1, j + 1);
		}
	}
}