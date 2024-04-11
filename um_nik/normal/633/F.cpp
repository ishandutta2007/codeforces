#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair
#define X first
#define Y second

const int N = 100100;
int n;
vector<int> g[N];
ll a[N];
ll dp[N][3];
ll ans = 0;
bool used[N];

void dfs(int v)
{
	used[v] = 1;
	pli b[4], c[4], d[4];
	for (int i = 0; i < 4; i++)
		b[i] = c[i] = d[i] = make_pair((ll)0, -1);
	for (int u : g[v])
	{
		if (used[u]) continue;
		dfs(u);
		pli tmp = make_pair(dp[u][0], u);
		for (int i = 0; i < 4; i++)
			if (tmp > b[i])
				swap(b[i], tmp);
		tmp = make_pair(dp[u][1], u);
		for (int i = 0; i < 4; i++)
			if (tmp > c[i])
				swap(c[i], tmp);
		tmp = make_pair(dp[u][2], u);
		for (int i = 0; i < 4; i++)
			if (tmp > d[i])
				swap(d[i], tmp);
	}
	if (b[0].second == -1)
	{
		dp[v][0] = dp[v][1] = dp[v][2] = a[v];
		ans = max(ans, a[v]);
		return;
	}
	dp[v][0] = a[v] + b[0].first;
	dp[v][2] = max(dp[v][0], a[v] + d[0].first);
	dp[v][1] = max(c[0].first, a[v] + b[0].first + b[1].first);
	ans = max(ans, dp[v][0]);
	ans = max(ans, dp[v][1]);
	ans = max(ans, dp[v][2]);
	ans = max(ans, c[0].first + c[1].first);
	for (int i = 0; i < 4; i++)
	{
		if (c[i].second == -1) break;
		int cnt = 0;
		ll x = a[v] + c[i].first;
		for (int j = 0; j < 4 && cnt < 2; j++)
		{
			if (b[j].second == -1) break;
			if (b[j].second == c[i].second) continue;
			cnt++;
			x += b[j].first;
			if (cnt == 1)
				dp[v][2] = max(dp[v][2], x);
		}
		ans = max(ans, x);
	}
	for (int i = 0; i < 4; i++)
	{
		if (d[i].second == -1) break;
		ll x = a[v] + d[i].first;
		for (int j = 0; j < 4; j++)
		{
			if (b[j].second == -1) break;
			if (b[j].second == d[i].second) continue;
			ans = max(ans, x + b[j].first);
			break;
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
//	for (int i = 0; i < n; i++)
//		printf("%lld %lld\n", dp[i][0], dp[i][1]);
	printf("%lld\n", ans);

	return 0;
}