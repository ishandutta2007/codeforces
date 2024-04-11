#include <bits/stdc++.h>
using namespace std;

int k;
double dp[10005][1005];
bool v[10005][1005];
int ans[1005];
vector<int> queries[1005];

double D(int i, int j)
{
	if (j == 0) return i == 0 ? 1 : 0;
	if (j > i) return 0;
	if (v[i][j] == false)
	{
		v[i][j] = true;
		dp[i][j] = D(i - 1, j) * j / k + D(i - 1, j - 1) * (k - j + 1) / k;
	}
	return dp[i][j];
}

int main()
{
	int q;
	scanf("%d%d", &k, &q);
	int mex = 0;
	for (int i = 0; i < q; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		queries[tmp].push_back(i);
		mex = max(mex, tmp);
	}

	int last = 1;
	for (int i = k; last <= mex; i++)
	{
		double prop = D(i, k);
		while (last <= mex && prop >= (last - 1e-7) / 2000)
		{
			for (int t : queries[last]) ans[t] = i;
			++last;
		}
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}