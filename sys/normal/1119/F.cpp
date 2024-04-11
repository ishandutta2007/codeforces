#include <bits/stdc++.h>
 
using namespace std;
 
const int Maxn = 500005;
int n, cnt, ct, tmp_ct, dfn_cnt, deg[Maxn], tmp_node[Maxn], dep[Maxn], ord[Maxn], dfn[Maxn], head[Maxn], used[Maxn], node[Maxn], anc[Maxn][20];
long long sum[Maxn], f[Maxn][2];
pair <long long, int> pnt[Maxn];
set <pair <long long, int> > Se[Maxn];
vector <pair <int, int> > G[Maxn];
map <pair <int, int>, int> Ma;
bool vis[Maxn];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void init_dfs(int u, int fa)
{
	dfn[u] = ++dfn_cnt;
	anc[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			init_dfs(to, u);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
void insert(int u, pair <long long, int> val)
{
	Se[u].insert(val);
	if (val <= pnt[u]) sum[u] += val.first, used[u]++;
}
void erase(int u, pair <long long, int> val)
{
	if (val <= pnt[u])
	{
		sum[u] -= val.first, used[u]--;
		if (val == pnt[u]) pnt[u] = *(--Se[u].lower_bound(val));
	}
	Se[u].erase(val);
}
long long get_sum(int u, int lim)
{
	lim = max(lim, 0);
	while (used[u] > lim && pnt[u].first > 0)
	{
		sum[u] -= pnt[u].first, used[u]--;
		pnt[u] = *(--Se[u].lower_bound(pnt[u]));
	}
	while (used[u] < lim)
	{
		set <pair <long long, int> > :: iterator it = ++Se[u].lower_bound(pnt[u]);
		if (it == Se[u].end()) break;
		used[u]++, sum[u] += it -> first;
		pnt[u] = *it;
	}
	while (true)
	{
		set <pair <long long, int> > :: iterator it = ++Se[u].lower_bound(pnt[u]);
		if (it == Se[u].end() || it -> first >= 0) break;
		used[u]++, sum[u] += it -> first;
		pnt[u] = *it;
	}
	return sum[u];
}
void build(void)
{
	memcpy(node, tmp_node, sizeof(int[tmp_ct + 1]));
	ct = tmp_ct;
	sort(node + 1, node + 1 + ct, [](int x, int y){return dfn[x] < dfn[y];});
	for (int i = ct - 1; i >= 1; i--)
		node[++ct] = lca(node[i], node[i + 1]);
	sort(node + 1, node + 1 + ct, [](int x, int y){return dfn[x] < dfn[y];});
	ct = unique(node + 1, node + 1 + ct) - node - 1;
	for (int i = 1; i <= ct; i++)
		if (!vis[node[i]])
		{
			vis[node[i]] = true;
			for (int j = head[node[i]]; j; j = edge[j].nxt)
				erase(edge[j].to, make_pair(edge[j].w, node[i]));
		}
	for (int i = 1; i <= ct; i++)
		G[node[i]].clear();
	for (int i = 2; i <= ct; i++)
	{
		int l = lca(node[i - 1], node[i]);
		G[l].push_back(make_pair(node[i], Ma[make_pair(l, node[i])]));
	}
}
void dfs(int u, int lim, int w)
{
	int need = deg[u] - lim;
	long long tot = 0;
	vector <pair <long long, int> > tmp;
	for (auto to : G[u])
	{
		dfs(to.first, lim, to.second);
		tot += f[to.first][0];
		if (to.second) tmp.push_back(make_pair(f[to.first][1] - f[to.first][0], to.first));
	}
	sort(tmp.begin(), tmp.end());
	for (auto now : tmp)
		insert(u, now);
	f[u][0] = get_sum(u, need) + tot;
	f[u][1] = get_sum(u, need - 1) + w + tot;
	for (auto now : tmp)
		erase(u, now);
}
vector <long long> minimum_closure_costs(int N, vector <int> U, vector <int> V, vector <int> W)
{
	n = N;
	vector <long long> ans;
	ans.resize(n);
	for (int i = 1; i <= n; i++)
		Se[i].insert(pnt[i] = make_pair(-0x3f3f3f3f3f3f3f3fLL, 0));
	for (int i = 0; i < n - 1; i++)
	{
		Ma[make_pair(U[i], V[i])] = Ma[make_pair(V[i], U[i])] = W[i];
		insert(U[i], make_pair(W[i], V[i])), insert(V[i], make_pair(W[i], U[i]));
		add(U[i], V[i], W[i]), add(V[i], U[i], W[i]), deg[U[i]]++, deg[V[i]]++;
	}
	init_dfs(1, 0);
	init();
	for (int i = 1; i <= n; i++) ord[i] = i;
	sort(ord + 1, ord + 1 + n, [](int x, int y){if (x == 1) return false; if (y == 1) return true; return deg[x] < deg[y];});
	int pt = n;
	for (int i = n - 1; i >= 0; i--)
	{
		while (pt && (pt == n || deg[ord[pt]] == i))
		{
			tmp_node[++tmp_ct] = ord[pt];
			if (!vis[ord[pt]])
			{
				vis[ord[pt]] = true;
				for (int j = head[ord[pt]]; j; j = edge[j].nxt)
					erase(edge[j].to, make_pair(edge[j].w, ord[pt]));
			}
			pt--;
		}
		build();
		dfs(1, i, 0);
		ans[i] = f[1][0];
	}
	return ans;
}
int main()
{
	int N;
	assert(1 == scanf("%d", &N));
	std::vector<int> U(N - 1), V(N - 1), W(N - 1);
	for (int i = 0; i < N - 1; ++i)
		assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
	std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
	for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i)
	{
		if (i > 0) printf(" ");
		printf("%lld",closure_costs[i]);
	}
	printf("\n");
	return 0;
}