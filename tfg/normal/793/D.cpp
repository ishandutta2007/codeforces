#include <iostream>
#include <cstring>

const int ms = 88;
const int INF = 0x3f3f3f3f;

int n, k, m;

bool got[ms][ms];
int cost[ms][ms];

int memo[ms][ms][ms][2];
int dp(int l, int r, int missing, int dir)
{
	if(!missing)
		return 0;
	int &ans = memo[l][r][missing][dir];
	if(ans != -1)
		return ans;
	ans = INF;
	if(dir == 0)
	{
		for(int i = l + 1; i < r; i++)
		{
			if(got[l][i])
				ans = std::min(ans,
					cost[l][i] + std::min(
						dp(i, r, missing - 1, 0),
						dp(l, i, missing - 1, 1))
					);
		}
	}
	else
	{
		for(int i = l + 1; i < r; i++)
		{
			if(got[r][i])
				ans = std::min(ans,
					cost[r][i] + std::min(
						dp(i, r, missing - 1, 0),
						dp(l, i, missing - 1, 1))
					);
		}
	}
	return ans;
}

int main()
{
	std::cin >> n >> k >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, c;
		std::cin >> u >> v >> c;
		if(!got[u][v])
		{
			got[u][v] = true;
			cost[u][v] = 1000;
		}
		cost[u][v] = std::min(cost[u][v], c);
	}
	int ans = INF;
	memset(memo, -1, sizeof memo);
	for(int i = 1; i <= n; i++)
		ans = std::min(ans, dp(i, n + 1, k - 1, 0));
	for(int i = 1; i <= n; i++)
		ans = std::min(ans, dp(0, i, k - 1, 1));
	if(ans == INF)
		ans = -1;
	std::cout << ans << '\n';
}