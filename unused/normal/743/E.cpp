#include <bits/stdc++.h>
using namespace std;

int dat[1000];
int dp[1000][256];
int visit[1000][256];
vector<int> indices[8];
int vtidx[1000];
int n, mv;

int D(int idx, int st)
{
	if (idx == n) return st == 255 ? 0 : -10000;
	if (visit[idx][st] != mv)
	{
		visit[idx][st] = mv;
		dp[idx][st] = D(idx + 1, st);

		if (!(st & (1 << dat[idx])))
		{
			if (vtidx[idx] + mv - 1 < indices[dat[idx]].size())
			{
				dp[idx][st] = max(dp[idx][st], D(indices[dat[idx]][vtidx[idx] + mv - 1] + 1, st | (1 << dat[idx])) + mv);

				if (vtidx[idx] + mv < indices[dat[idx]].size())
					dp[idx][st] = max(dp[idx][st], D(indices[dat[idx]][vtidx[idx] + mv] + 1, st | (1 << dat[idx])) + mv + 1);
			}
		}
	}

	return dp[idx][st];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		dat[i]--;

		vtidx[i] = indices[dat[i]].size();
		indices[dat[i]].push_back(i);
	}

	int ans = 0;
	for (int i = 0; i < 8; i++) if (indices[i].empty() == false) ans++;
	for (int i = 1; i <= 125; i++)
	{
		mv = i;
		ans = max(ans, D(0, 0));
	}
	printf("%d", ans);
}