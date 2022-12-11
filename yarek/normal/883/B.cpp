#include <bits/stdc++.h>
using namespace std;

const int N = 200001, inf = 1e9;
int mn[N], mx[N];
vector<int> g[N];
vector<int> rg[N];
vector<int> vec;
int col[N];
vector<pair<int, int>> pr[N];
int n, m, k;

void dfs(int v)
{
	if(col[v] == 2) return;
	if(col[v] == 1)
	{
		puts("-1");
		exit(0);
	}
	col[v] = 1;
	for(auto u: g[v])
		dfs(u);
	col[v] = 2;
	vec.push_back(v);
}

void update()
{
	for(int v: vec)
		for(int u: g[v])
			mn[v] = max(mn[v], mn[u] + 1);
	reverse(vec.begin(), vec.end());
	for(int v: vec)
		for(int u: rg[v])
			mx[v] = min(mx[v], mx[u] - 1);
	reverse(vec.begin(), vec.end());
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
	{
		int r;
		scanf("%d", &r);
		if(r == 0)
		{
			mn[i] = 1;
			mx[i] = k;
		}
		else mn[i] = mx[i] = r;
	}
	while(m--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		rg[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
		dfs(i);
	update();
	if(*min_element(mx + 1, mx + n + 1) < 1 || *max_element(mn + 1, mn + n + 1) > k)
	{
		puts("-1");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		pr[mn[i]].emplace_back(mx[i], i);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 1; i <= k; i++)
	{
		for(auto p: pr[i]) pq.push(p);
		while(!pq.empty() && pq.top().first < i) pq.pop();
		if(pq.empty())
		{
			puts("-1");
			return 0;
		}
		auto p = pq.top();
		pq.pop();
		mn[p.second] = mx[p.second] = i;
	}
	update();
	for(int i = 1; i <= n; i++)
		if(mn[i] > mx[i])
		{
			puts("-1");
			return 0;
		}
	for(int i = 1; i <= n; i++)
		printf("%d ", mn[i]);
	puts("");
}