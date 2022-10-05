#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn], p[Maxn], b[Maxn], invp[Maxn], fa[Maxn];
vector <int> Ve[Maxn];
void Swap(int x, int y)
{
	swap(p[x], p[y]);
	invp[p[x]] = x, invp[p[y]] = y;
 }
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	fa[get_fa(x)] = get_fa(y);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) Ve[i].clear(), fa[i] = i;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), Ve[a[i]].push_back(i);
		int f = 0, ct = 0;
		for (int i = 1; i <= n; i++)
		{
			f += Ve[i].size() & 1;
			if (Ve[i].size() & 1)
			{
				if (Ve[i].back() == (n + 1) / 2 && Ve[i].size() == 1)
				{
					puts("NO");
					goto END;
				}
				if (Ve[i].back() == (n + 1) / 2) swap(Ve[i][0], Ve[i].back());
				p[Ve[i].back()] = (n + 1) / 2;
			}
			for (int j = 0; j < (int) Ve[i].size() - 1; j += 2)
				p[Ve[i][j]] = ++ct, p[Ve[i][j + 1]] = n + 1 - ct; 
		}
		if (f > 1)
		{
			puts("NO");
			continue;
		}
		for (int i = 1; i <= n; i++) merge(i, p[i]), invp[p[i]] = i;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < (int) Ve[i].size(); j++)
				if (get_fa(Ve[i][j]) != get_fa(Ve[i][0]))
					Swap(Ve[i][j], Ve[i][0]), merge(Ve[i][j], Ve[i][0]);
		for (int i = 2; i <= n; i++)
			if (get_fa(1) != get_fa(i))
				Swap(invp[1], invp[i]), Swap(invp[n], invp[n + 1 - i]), Swap(invp[1], invp[n]), merge(1, i);
		puts("YES");
		for (int i = 1; i <= n; i++)
			printf("%d ", invp[i]);
		puts("");
		END:;
	}
	return 0;
}