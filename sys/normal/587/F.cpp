#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, ct, cnt, dfn_cnt, val[Maxn], sum[Maxn], dfn[Maxn], head[Maxn], pos[Maxn], siz[Maxn];
long long ans[Maxn];
string str[Maxn];
struct edg
{
	int nxt, to;
} edge[Maxn];
void edge_add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
struct quest
{
	int id, pos, val;
};
vector <quest> Ve[Maxn], Q[Maxn];
struct Node
{
	int trans[26], fail;
} node[Maxn];
int insert(string s)
{
	int now = 1;
	for (int i = 0; i < (int) s.size(); i++)
	{
		if (!node[now].trans[s[i] - 'a']) node[now].trans[s[i] - 'a'] = ++ct;
		now = node[now].trans[s[i] - 'a'];
	}
	return now;
}
queue <int> Qu;
void get_fail(void)
{
	for (int i = 0; i < 26; i++)
		if (node[1].trans[i]) node[node[1].trans[i]].fail = 1, Qu.push(node[1].trans[i]);
		else node[1].trans[i] = 1;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = 0; i < 26; i++)
		{
			if (node[u].trans[i])
			{
				node[node[u].trans[i]].fail = node[node[u].fail].trans[i];
				Qu.push(node[u].trans[i]);
			}
			else node[u].trans[i] = node[node[u].fail].trans[i];
		}
	}
	for (int i = 2; i <= ct; i++)
		edge_add(node[i].fail, i);
}
void init_dfs(int u)
{
	dfn[u] = ++dfn_cnt;
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
		init_dfs(edge[i].to), siz[u] += siz[edge[i].to];
}
void dfs(int u)
{
	for (int i = head[u]; i; i = edge[i].nxt)
		dfs(edge[i].to), val[u] += val[edge[i].to];
}
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int y)
{
	for (int i = x; i <= ct; i += lowbit(i))
		sum[i] += y;
}
int ask(int x)
{
	int result = 0;
	for (int i = x; i; i -= lowbit(i))
		result += sum[i];
	return result;
}
int main()
{
	scanf("%d%d", &n, &m);
	int B = 80;
	ct = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
		pos[i] = insert(str[i]);
	}
	get_fail();
	init_dfs(1);
	for (int i = 1; i <= m; i++)
	{
		int lt, rt, x;
		scanf("%d%d%d", &lt, &rt, &x);
		if ((int) str[x].size() >= B) Q[x].push_back((quest){i, lt - 1, -1}), Q[x].push_back((quest){i, rt, 1});
		else Ve[lt - 1].push_back((quest){i, x, -1}), Ve[rt].push_back((quest){i, x, 1});
	}
	for (int i = 1; i <= n; i++)
	{
		if ((int) str[i].size() >= B)
		{
			sort(Q[i].begin(), Q[i].end(), [](quest a, quest b){return a.pos < b.pos;});
			int now = 1;
			val[now] = 1;
			for (int j = 0; j < (int) str[i].size(); j++)
				now = node[now].trans[str[i][j] - 'a'], val[now] = 1;
			dfs(1);
			long long sum = 0;
			int pnt = 0;
			for (int j = 0; j <= n; j++)
			{
				sum += val[pos[j]];
				while (pnt < (int) Q[i].size() && Q[i][pnt].pos == j)
					ans[Q[i][pnt].id] += Q[i][pnt].val * sum, pnt++;
			}
			memset(val, 0, sizeof(int[ct + 1]));
		}
	}
	for (int i = 1; i <= n; i++)
	{
		add(dfn[pos[i]], 1), add(dfn[pos[i]] + siz[pos[i]], -1);
		for (auto u : Ve[i])
		{
			int now = 1;
			for (int j = 0; j < (int) str[u.pos].size(); j++)
			{
				now = node[now].trans[str[u.pos][j] - 'a'];
				ans[u.id] += u.val * ask(dfn[now]);
			}
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}