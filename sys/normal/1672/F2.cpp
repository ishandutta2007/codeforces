//IS THERE ANY RELATION BETWEEN F1 & F2????????????????????????????????????????????????????????????????????????????????
//FUCK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn], b[Maxn], cnt[Maxn];
bool flag, vis1[Maxn], vis2[Maxn];
vector <int> G[Maxn];
void dfs(int u)
{
	vis1[u] = vis2[u] = true;
	for (auto v : G[u])
		if (vis2[v]) flag = false;
		else if (!vis1[v]) dfs(v);
	vis2[u] = false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		flag = true;
		int pos = 0, maxi = 0;
		scanf("%d", &n);
		memset(cnt, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), cnt[a[i]]++, vis1[i] = vis2[i] = false, G[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
			if (cnt[i] > maxi) maxi = cnt[i], pos = i;
		for (int i = 1; i <= n; i++)
			if (a[i] != pos && b[i] != pos) G[a[i]].push_back(b[i]);
		for (int i = 1; i <= n; i++)
			if (!vis1[i]) dfs(i);
		puts(flag ? "AC" : "WA");
	}
	return 0;
}