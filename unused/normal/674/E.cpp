#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_H = 60;

double dp[500005][MAX_H + 1];
int parent[500005];

void add(int p, int t)
{
	parent[t] = p;
	double old = 0.0;
	int h = 0;
	dp[t][0] = 1;

	// dp[t][k] :
	// 1 - PI(1 - dp[x][k - 1] * 1/2)

	for (;;)
	{
		h++;
		if (p == 0 || h >= MAX_H) break;

		double old2 = dp[p][h];
		double pi = 1 - dp[p][h];
		pi = pi / (1 - old / 2) * (1 - dp[t][h - 1] / 2);
		dp[p][h] = 1 - pi;
		old = old2;
		t = p;
		p = parent[p];
	}
}

double calc(int t)
{
	double ret = 0;
	for (int i = 1; i < MAX_H; i++)
	{
		ret += (dp[t][i] - dp[t][i + 1]) * i;
	}
	return ret;
}

int main()
{
	int q;
	scanf("%d",&q);
	int last_idx = 1;
	dp[1][0] = 1;

	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		if (a == 1)
		{
			add(b, ++last_idx);
		}
		else
		{
			printf("%.9f\n", calc(b));
		}
	}
}