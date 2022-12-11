#include <bits/stdc++.h>
using namespace std;

int z[100005];

vector<int> ttt[100005];

const int MAXN = 200005;
vector<int> graph[MAXN];
int up[MAXN], visit[MAXN], vtime;
vector<int> stk;
int scc_idx[MAXN], scc_cnt;
int tsat;
void dfs(int nod) {
	up[nod] = visit[nod] = ++vtime;
	stk.push_back(nod);
	for (int next : graph[nod]) {
		if (visit[next] == 0) {
			dfs(next);
			up[nod] = min(up[nod], up[next]);
		}
		else if (scc_idx[next] == 0)
			up[nod] = min(up[nod], visit[next]);
	}
	if (up[nod] == visit[nod]) {
		++scc_cnt;
		int t;
		do {
			t = stk.back();
			stk.pop_back();
			scc_idx[t] = scc_cnt;
		} while (!stk.empty() && t != nod);
	}
}
// find SCCs in given directed graph
// O(V+E)
void get_scc() {
	vtime = 0;
	memset(visit, 0, sizeof(visit));
	scc_cnt = 0;
	memset(scc_idx, 0, sizeof(scc_idx));
	for (int i = 0; i < tsat; ++i)
		if (visit[i] == 0) dfs(i);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &z[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int na;
		scanf("%d", &na);
		while (na--)
		{
			int tmp;
			scanf("%d", &tmp);
			ttt[tmp - 1].push_back(i);
		}
	}

	tsat = m * 2;

	for (int i = 0; i < n; i++)
	{
		int a = ttt[i][0], b = ttt[i][1];
		if (z[i])
		{
			graph[a].push_back(b);
			graph[a+m].push_back(b+m);
			graph[b].push_back(a);
			graph[b+m].push_back(a+m);
		}
		else
		{
			graph[a].push_back(b+m);
			graph[a + m].push_back(b);
			graph[b].push_back(a+m);
			graph[b + m].push_back(a);
		}
	}

	get_scc();

	for (int i = 0; i < m; i++)
	{
		if (scc_idx[i] == scc_idx[i + m])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}