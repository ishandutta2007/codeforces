#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 300005;
int res, cnt, head[Maxn], choose[Maxn], target[Maxn], las[Maxn], ct, n[Maxn], k, val[Maxn], a[20][Maxn], b[Maxn], bel[Maxn], state_cnt;
bool vis1[Maxn], vis2[Maxn], ans[Maxn], done[20], flag;
map <long long, int> Ma;
long long sum[Maxn], tot;
int tmp_state, Solution[Maxn][20], Solution_cnt;
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	if (bel[x] == bel[y]) return ;
	if (done[bel[x]] || done[bel[y]]) return ;
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	vis1[u] = true;
	vis2[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (vis2[to])
		{
			res = to;
			tmp_state = 0;
			state_cnt++;
			tmp_state |= (1 << (bel[to] - 1));
			tmp_state |= (1 << (bel[u] - 1));
			vis2[u] = false;
			Solution[state_cnt][1] = to, Solution[state_cnt][2] = u;
			Solution_cnt = 2;
			return ;
		}
		dfs(to);
		if (flag) return ;
		if (tmp_state & (1 << (bel[u] - 1)))
		{
			if (res == u)
				val[state_cnt] = tmp_state, reverse(Solution[state_cnt] + 1, Solution[state_cnt] + Solution_cnt + 1), Solution[state_cnt][Solution_cnt + 1] = Solution[state_cnt][1], tmp_state = 0;
			else state_cnt--, tmp_state = 0;
			flag = true;
			return ;
		}
		else if (tmp_state)
		{
			tmp_state |= (1 << (bel[u] - 1));
			Solution[state_cnt][++Solution_cnt] = u;
			vis2[u] = false;
			return ;
		}
	}
	vis2[u] = false;
}
void get_ans(int id)
{
	choose[bel[Solution[id][1]]] = b[Solution[id][1]];
	for (int i = 2; Solution[id][i]; i++)
	{
		choose[bel[Solution[id][i]]] = b[Solution[id][i]];
		target[bel[Solution[id][i - 1]]] = bel[Solution[id][i]];
	}
}
int main()
{
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &n[i]);
		for (int j = 1; j <= n[i]; j++)
			scanf("%d", &a[i][j]), b[++ct] = a[i][j], sum[i] += a[i][j], tot += a[i][j];
	}
	if (tot % k)
	{
		printf("NO");
		return 0;
	}
	tot /= k;
	for (int i = 1; i <= k; i++)
		if (tot == sum[i]) done[i] = true;
	sort(b + 1, b + 1 + ct);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n[i]; j++)
			Ma[a[i][j]] = lower_bound(b + 1, b + 1 + ct, a[i][j]) - b, bel[Ma[a[i][j]]] = i;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n[i]; j++)
			if (Ma[tot - sum[i] + a[i][j]])
				add(Ma[tot - sum[i] + a[i][j]], Ma[a[i][j]]);
	for (int i = 1; i <= ct; i++)
		if (!vis1[i]) flag = false, dfs(i);
	for (int i = 1; i <= k; i++)
		if (sum[i] == tot) val[++state_cnt] = 1 << (i - 1);
	int maxi = (1 << k) - 1;
	ans[0] = true;
	for (int i = 0; i <= maxi; i++)
		if (ans[i])
			for (int j = 1; j <= state_cnt; j++)
				if (!(val[j] & i))
					ans[val[j] | i] = true, las[val[j] | i] = j;
	if (ans[maxi])
	{
		printf("YES\n");
		int state_now = maxi;
		while (state_now)
		{
			get_ans(las[state_now]);
			state_now ^= val[las[state_now]];
		}
		for (int i = 1; i <= k; i++)
			if (target[i])
				printf("%d %d\n", choose[i], target[i]);
			else printf("%d %d\n", a[i][1], i);
		return 0;
	}
	printf("NO");
	return 0;
}