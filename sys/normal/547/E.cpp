#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, m, cnt, node_ct, ct, l[Maxn], r[Maxn], k[Maxn], ans[Maxn], head[Maxn], endpos[Maxn], dfn[Maxn], End[Maxn];
bool vis[Maxn];
string str;
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
struct Node
{
	int son[26], fail, fa;
}node[Maxn];
void init(string str, int id)
{
	int now = 1, siz = str.size();
	for (int i = 0; i < siz; i++)
	{
		if (!node[now].son[str[i] - 'a']) node[now].son[str[i] - 'a'] = ++node_ct;
		node[node[now].son[str[i] - 'a']].fa = now;
		now = node[now].son[str[i] - 'a'];
	}
	endpos[id] = now;
}
queue <int> Qu;
void get_fail(void)
{
	for (int i = 0; i < 26; i++)
		if (node[1].son[i]) node[node[1].son[i]].fail = 1, add(1, node[1].son[i]), Qu.push(node[1].son[i]);
		else node[1].son[i] = 1;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = 0; i < 26; i++)
		{
			if (node[u].son[i])
			{
				node[node[u].son[i]].fail = node[node[u].fail].son[i];
				add(node[node[u].son[i]].fail, node[u].son[i]);
				Qu.push(node[u].son[i]);
			}
			else node[u].son[i] = node[node[u].fail].son[i];
		}
	}
}
void dfs(int u)
{
	dfn[u] = ++ct;
	for (int i = head[u]; i; i = edge[i].nxt)
		dfs(edge[i].to);
	End[u] = ct;
}
int sum[Maxn];
int lowbit(int x)
{
	return x & -x;
}
void add(int x)
{
	for (int i = x; i <= ct; i += lowbit(i))
		sum[i]++;
}
int ask(int x)
{
	int tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		tmp += sum[i];
	return tmp;
}
vector <pair <int, int> > Ve[Maxn];
int main()
{
	node_ct = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		init(str, i);
	}
	get_fail();
	dfs(1);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &l[i], &r[i], &k[i]);
		Ve[l[i] - 1].push_back(make_pair(k[i], i));
		Ve[r[i]].push_back(make_pair(k[i], i));
	}
	for (vector <pair <int, int> > :: iterator it = Ve[0].begin(); it != Ve[0].end(); it++)
		vis[it -> second] = true;
	for (int i = 1; i <= n; i++)
	{
		int tmp = endpos[i];
		while (tmp != 1)
			add(dfn[tmp]), tmp = node[tmp].fa;
		for (vector <pair <int, int> > :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
		{
			int type;
			pair <int, int> now = *it;
			if (!vis[now.second]) vis[now.second] = true, type = -1;
			else type = 1;
			ans[now.second] += type * (ask(End[endpos[now.first]]) - ask(dfn[endpos[now.first]] - 1));
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}