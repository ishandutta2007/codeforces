#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> child[100005];
int parent[100005];
int cnum[100005];
int dp[100005];

int C(int t)
{
	if (cnum[t] == 0)
	{
		cnum[t] = 1;
		for (int next : child[t])
			cnum[t] += C(next);
	}
	return cnum[t];
}

void dfs(int i)
{
	int total = 0;
	for (int next : child[i]) total += C(next);
	for (int next : child[i])
	{
		dp[next] = dp[i] + 2 + total - C(next);
		dfs(next);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &parent[i]);
		child[parent[i]].push_back(i);
	}

	dp[1] = 2;
	dfs(1);

	for (int i = 1; i <= n; i++) printf("%d.%d ", dp[i]>>1, (dp[i]&1)*5);
}