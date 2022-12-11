#include <bits/stdc++.h>
using namespace std;

int d[10000][2];

int dp[7001][2];
int k[2];
int n;

int degree[7001][2];

string words[] =
{
	"Lose", "Loop", "Win"
};

int main()
{
	scanf("%d", &n);
	scanf("%d", &k[0]);
	for (int i = 0; i < k[0]; i++) scanf("%d", &d[i][0]);
	scanf("%d", &k[1]);
	for (int i = 0; i < k[1]; i++) scanf("%d", &d[i][1]);

	fill(&dp[0][0], &dp[7001][0], 1);

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < k[0]; j++)
		{
			degree[i][0]++;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < k[1]; j++)
		{
			degree[i][1]++;
		}
	}

	queue<short> que;
	que.push(2);
	que.push(3);
	dp[1][0] = dp[1][1] = 0;

	while (que.empty() == false)
	{
		int a, b;
		a = que.front() / 2;
		b = que.front() % 2;
		que.pop();

		if (dp[a][b] == 0)
		{
			for (int i = 0; i < k[!b]; i++)
			{
				int x = (a + n - d[i][!b] - 1) % n + 1;
				if (dp[x][!b] != 1) continue;
				dp[x][!b] = 2;
				que.emplace(x * 2 + !b);
			}
		}
		else
		{
			for (int i = 0; i < k[!b]; i++)
			{
				int x = (a + n - d[i][!b] - 1) % n + 1;
				if (dp[x][!b] != 1) continue;
				if (--degree[x][!b] == 0)
				{
					dp[x][!b] = 0;
					que.emplace(x * 2 + !b);
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) printf("%s ", words[dp[i][0]].c_str());
	printf("\n");
	for (int i = 2; i <= n; i++) printf("%s ", words[dp[i][1]].c_str());
	printf("\n");
}