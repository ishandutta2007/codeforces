#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int dat[100005];
int flag;
long long total;
array<long long, 2> cnt[100005];

void dfs(int t, int p)
{
	int cur = (dat[t] & (1 << flag)) != 0;
	cnt[t] = { 0, 0 };

	vector<array<long long, 2>> vt;

	for (int nxt : graph[t])
	{
		if (nxt == p) continue;
		dfs(nxt, t);
		vt.push_back(cnt[nxt]);
	}

	for (auto &&e : vt)
	{
		total += e[cur ^ 1] + cnt[t][0] * e[1] + cnt[t][1] * e[0];
		cnt[t][0] += e[cur];
		cnt[t][1] += e[cur ^ 1];
	}

	cnt[t][cur] += 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	long long ans = 0;

	for (int i = 0; i < n; i++) ans += dat[i];

	for (flag = 0; flag < 21; flag++)
	{
		total = 0;
		dfs(0, -1);
		ans += total * (1 << flag);
	}

	printf("%lld\n", ans);
}