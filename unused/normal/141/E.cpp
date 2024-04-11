#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int s, e, c;
};

edge dat[100005];
vector<pair<int, int>> graph[1005];
set<pair<int,int>> tree[1005];
bool visit[1005];
bool used[100005];
int sum;
vector<int> now;

int parent[1005];
int getparent(int t)
{
	return t == parent[t] ? t : parent[t] = getparent(parent[t]);
}

void merge(int a, int b)
{
	parent[getparent(a)] = getparent(b);
}

void dfs(int t)
{
	visit[t] = true;

	for (auto &&e : graph[t])
	{
		if (visit[e.first]) continue;

		tree[t].insert(e);
		tree[e.first].insert({ t, e.second });
		sum += dat[e.second].c;
		used[e.second] = true;

		dfs(e.first);
	}
}

bool dfs2(int t, int p, int target)
{
	if (t == target) return true;
	for (auto &&e : tree[t])
	{
		int nxt = e.first;
		if (nxt == p) continue;
		now.push_back(e.second);
		if (dfs2(nxt, t, target)) return true;
		now.pop_back();
	}
	return false;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (n % 2 == 0)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		char ch;
		scanf("%d%d %c", &dat[i].s, &dat[i].e, &ch);
		dat[i].c = (ch == 'S');
		if (dat[i].s == dat[i].e) continue;
		graph[dat[i].s].emplace_back(dat[i].e, i);
		graph[dat[i].e].emplace_back(dat[i].s, i);
	}

	int cnt = n / 2;

	dfs(1);

	int diff = abs(sum - cnt);
	int target = sum < cnt;

	for (int i = 0; i < m; i++) if (used[i] && dat[i].c == target) merge(dat[i].s, dat[i].e);

	for (int i = 0; i < m && diff; i++)
	{
		if (dat[i].c != target) continue;
		if (getparent(dat[i].s) == getparent(dat[i].e)) continue;
		now.clear();
		if (dfs2(dat[i].s, -1, dat[i].e) == false) continue;
		for (int j : now)
		{
			if (dat[j].c == target) continue;

			tree[dat[j].s].erase({ dat[j].e, j });
			tree[dat[j].e].erase({ dat[j].s, j });
			used[j] = false;
			tree[dat[i].s].insert({ dat[i].e, i });
			tree[dat[i].e].insert({ dat[i].s, i });
			used[i] = true;
			--diff;
			merge(dat[i].s, dat[i].e);
			break;
		}
	}

	if (diff)
	{
		printf("-1\n");
		return 0;
	}

	printf("%d\n", cnt * 2);
	for (int i = 0; i < m; i++) if (used[i]) printf("%d ", i + 1);
	printf("\n");
}