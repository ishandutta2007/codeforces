#include <Bits/stdc++.h>
using namespace std;

char str[155];
int cost[155];
int dp1[155][155], dp2[155][155];
int dp3[155][155][155];
bool v1[155][155], v2[155][155], v3[155][155][155];

int D(int, int); int E(int, int); int F(int, int, int);

int D(int l, int r)
{
	if (v1[l][r] == false)
	{
		v1[l][r] = true;
		dp1[l][r] = max(0, E(l, r));
		for (int i = l; i < r; i++)
		{
			dp1[l][r] = max(dp1[l][r], D(l, i) + D(i + 1, r));
		}
	}
	return dp1[l][r];
}

int E(int l, int r)
{
	if (l > r) return 0;

	if (v2[l][r] == false)
	{
		v2[l][r] = true;
		dp2[l][r] = -1e8;

		for (int i = 1; i <= r - l + 1; i++)
		{
			if (cost[i] == -1) continue;
			dp2[l][r] = max(dp2[l][r], cost[i] + F(l, r, i));
		}
	}

	return dp2[l][r];
}

int F(int l, int r, int len)
{
	if (len == 0) return E(l, r);
	if (len > r - l + 1) return -1e8;

	if (v3[l][r][len] == false)
	{
		v3[l][r][len] = true;

		dp3[l][r][len] = -1e8;

		if (len == 1)
		{
			for (int i = l; i <= r; i++)
			{
				dp3[l][r][len] = max(dp3[l][r][len], E(l, i - 1) + E(i + 1, r));
			}
		}
		else
		{
			if (str[l] == str[r]) dp3[l][r][len] = F(l + 1, r - 1, len - 2);

			for (int i = l; i <= r; i++)
			{
				dp3[l][r][len] = max(dp3[l][r][len], E(l, i) + F(i + 1, r, len));
				dp3[l][r][len] = max(dp3[l][r][len], F(l, i, len) + E(i + 1, r));
			}
		}
	}

	return dp3[l][r][len];
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&cost[i]);
	}
	scanf("%s",str);
	printf("%d\n", D(0, n - 1));
}