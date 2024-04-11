#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 500500;
const int M = 60;
double dp[N][M];
int n, q;
int par[N];

void undo(int v, int h)
{
	if (v == 0 || h >= M) return;
	int u = par[v];
	if (u == 0) return;
	undo(u, h + 1);
	dp[u][h] /= (1 + dp[v][h - 1]) / 2;
	return;
}
void addV(int p)
{
	int v = n++;
	par[v] = p;
	for (int i = 0; i < M; i++)
		dp[v][i] = 1;
	undo(p, 1);
	int h = 0;
	while(v > 0 && h < M)
	{
		int u = par[v];
		if (u == 0) break;
		if (h == 0)
			dp[u][0] /= 2;
		else
			dp[u][h] *= (1 + dp[v][h - 1]) / 2;
		v = u;
		h++;
	}
	return;
}

double query(int v)
{
	double ans = 0;
	for (int i = 1; i < M; i++)
		ans += i * (dp[v][i] - dp[v][i - 1]);
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	n = 1;
	addV(0);
	scanf("%d", &q);
	while(q--)
	{
		int t, v;
		scanf("%d%d", &t, &v);
		if (t == 1)
			addV(v);
		else
			printf("%.10lf\n", query(v));
	}

	return 0;
}