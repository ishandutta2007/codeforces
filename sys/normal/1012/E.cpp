#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 200005;
int n, s, ct, tmp_n, ans_ct, a[Maxn], b[Maxn], fa[Maxn], pos[Maxn], ord[Maxn], bel[Maxn], Pos[Maxn];
vector <int> spec, Ve[Maxn];
bool vis[Maxn];
void dfs(int u)
{
	if (vis[u]) return ;
	bel[u] = ct, vis[u] = true, dfs(ord[u]);
}
void dfs2(int u)
{
	if (vis[u]) return ;
	Ve[ans_ct].push_back(u), vis[u] = true, dfs2(pos[u]);
}
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i]) a[++tmp_n] = a[i], Pos[tmp_n] = i;
	n = tmp_n;
	if (s < n)
	{
		puts("-1");
		return 0;
	}
	s -= n;
	for (int i = 1; i <= n; i++) ord[i] = i;
	sort(ord + 1, ord + 1 + n, [](int x, int y){return a[x] < a[y];});
	for (int i = 1; i <= n; i++)
		pos[ord[i]] = i;
	a[n + 1] = -1;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) ct++, fa[ct] = ct, dfs(i);
	int las = 1;
	for (int i = 2; i <= n + 1; i++)
		if (a[ord[i]] != a[ord[i - 1]])
		{
			for (int j = las; j < i; j++)
				if (get_fa(bel[ord[las]]) != get_fa(bel[ord[j]]))
					fa[get_fa(bel[ord[j]])] = get_fa(bel[ord[las]]), swap(ord[j], ord[las]);
			las = i;
		}
	memset(vis, 0, sizeof(bool[n + 1]));
	ct = 0;
	for (int i = 1; i <= n; i++)
		pos[ord[i]] = i;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			ct++;
			if (ct == 1 || ct > s) ++ans_ct;
			if (ct <= s) spec.push_back(i);
			dfs2(i);
		}
	printf("%d\n", ans_ct + (spec.size() > 1));
	if (ans_ct)
	{
		printf("%d\n", (int) Ve[1].size());
		for (vector <int> :: iterator it = Ve[1].begin(); it != Ve[1].end(); it++)
			printf("%d ", Pos[*it]);
		puts("");
	}
	if (spec.size() > 1)
	{
		printf("%d\n", (int) spec.size());
		for (vector <int> :: reverse_iterator it = spec.rbegin(); it != spec.rend(); it++)
			printf("%d ", Pos[*it]);
		puts("");
	}
	for (int i = 2; i <= ans_ct; i++)
	{
		printf("%d\n", (int) Ve[i].size());
		for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
			printf("%d ", Pos[*it]);
		puts("");
	}
	return 0;
}