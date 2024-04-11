#include <bits/stdc++.h>
using namespace std;

const int Maxk = 405, Maxn = 100005, p = 1e9 + 7;
struct Basis
{
	int val[5];
	Basis(void)
	{
		memset(val, 0, sizeof(val));
	}
	bool insert(int x)
	{
		for (int i = 4; i >= 0; i--)
			if (x & (1 << i))
			{
				if (val[i]) x ^= val[i];
				else
				{
					val[i] = x;
					for (int j = 0; j < i; j++)
						if (val[j] && val[i] & (1 << j))
							val[i] ^= val[j];
					for (int j = i + 1; j <= 4; j++)
						if (val[j] & (1 << i))
							val[j] ^= val[i];
					return true;
				}
			}
		return false;
	}
	int Hash(void)
	{
		return val[0] | val[1] << 1 | val[2] << 3 | val[3] << 6 | val[4] << 10;
	}
	void init(int x)
	{
		val[0] = x & 1;
		val[1] = x >> 1 & 3;
		val[2] = x >> 3 & 7;
		val[3] = x >> 6 & 15;
		val[4] = x >> 10 & 31;
	}
}B[Maxn];



int n, m, cnt, block_ct, edge_cnt, dfn_cnt, dfn[Maxn], root[Maxn], dis[Maxn], cyc[Maxn], bel[Maxn], head[Maxn], trans[Maxk][Maxk], id[Maxn], rk[Maxk];
bool vis_cyc[Maxn], done[Maxn];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++edge_cnt] = (edg){head[x], y, w};
	head[x] = edge_cnt;
}

void Dfs(Basis x)
{
	int now = x.Hash();
	if (!id[now]) id[now] = ++cnt, rk[cnt] = now;
	else return ;
	for (int i = 1; i <= 31; i++)
	{
		Basis tmp = x;
		if (tmp.insert(i)) Dfs(tmp);
	}
}
void get_trans(void)
{
	for (int i = 1; i <= cnt; i++)
	{
		Basis tmp_i;
		tmp_i.init(rk[i]);
		for (int j = 1; j <= cnt; j++)
		{
			Basis tmp_j;
			tmp_j.init(rk[j]);
			bool Done = false;
			for (int k = 0; k <= 4; k++)
				if (tmp_i.val[k])
					Done |= !tmp_j.insert(tmp_i.val[k]);
			if (!Done) trans[i][j] = id[tmp_j.Hash()];
		}
	}
}
void dfs(int u, int fa, int now)
{
	bel[u] = now;
	dfn[u] = ++dfn_cnt;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!bel[to]) dis[to] = dis[u] ^ edge[i].w, dfs(to, u, now);
		else if (to != 1 && to != fa && dfn[to] < dfn[u])
			done[now] |= !B[now].insert(dis[to] ^ dis[u] ^ edge[i].w);
	}
}
long long f[Maxk], g[Maxk], ans;
int main()
{
	scanf("%d%d", &n, &m);
	Dfs(*new(Basis));
	get_trans();
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		add(y, x, w);
	}
	bel[1] = -1;
	for (int i = head[1]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!bel[to]) root[++block_ct] = to, cyc[block_ct] = edge[i].w, dfs(to, 1, block_ct);
		else
		{
			int rt = root[bel[to]];
			for (int j = head[to]; j; j = edge[j].nxt)
				if (edge[j].to == rt)
				{
					cyc[bel[to]] = cyc[bel[to]] ^ edge[i].w ^ edge[j].w;
					vis_cyc[bel[to]] = true;
				}
		}
	}
	f[1] = 1;
	for (int i = 1; i <= block_ct; i++)
	{
		if (done[i]) continue;
		memcpy(g, f, sizeof(long long[cnt + 1]));
		if (!vis_cyc[i])
		{
			int now = id[B[i].Hash()];
			for (int j = 1; j <= cnt; j++)
				if (trans[j][now]) (f[trans[j][now]] += g[j]) %= p;
		}
		else
		{
			int now1 = id[B[i].Hash()];
			Basis tmp = B[i];
			bool Done = tmp.insert(cyc[i]);
			int now2 = id[tmp.Hash()];
			for (int j = 1; j <= cnt; j++)
			{
				if (trans[j][now1]) (f[trans[j][now1]] += 2 * g[j]) %= p;
				if (Done && trans[j][now2]) (f[trans[j][now2]] += g[j]) %= p;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
		(ans += f[i]) %= p;
	printf("%lld", ans);
	return 0;
}