#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000005];
int dat[1000005];
int sum[1000005];
bool s[1000005];
int dt;
int total;
int root;

bool dfs2(int t)
{
	if (sum[t] == total / 3)
	{
		printf("%d ", t);
		return true;
	}

	for (int nxt : graph[t])
	{
		if (dfs2(nxt)) return true;
	}
	return false;
}

void dfs1(int t)
{
	sum[t] = dat[t];
	vector<int> sub;
	for (int nxt : graph[t])
	{
		dfs1(nxt);
		sum[t] += sum[nxt];
		if (s[nxt]) sub.push_back(nxt);
	}

	s[t] = (sub.empty() == false || sum[t] == total / 3);

	if (sub.size() >= 2)
	{
		dfs2(sub[0]);
		dfs2(sub[1]);
		exit(0);
	}

	if (t != root && sum[t] == total / 3 * 2 && sub.empty() == false)
	{
		printf("%d ", t);
		dfs2(sub[0]);
		exit(0);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		dat[i] = b;
		if (a == 0) root = i;
		else graph[a].push_back(i);
		total += dat[i];
	}

	if (total % 3)
	{
		printf("-1\n");
		return 0;
	}

	dt = 1;

	dfs1(root);

	printf("-1\n");
}