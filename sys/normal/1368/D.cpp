#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, a[Maxn], cnt[21][Maxn], tot[21];
long long ans;
queue <int> Qu[21];
struct cmp
{
	bool operator () (const int &x, const int &y) const
	{
		return a[x] < a[y];
	}
};
set <int, cmp> S;
int get(int pos)
{
	while (!cnt[pos][Qu[pos].front()]) Qu[pos].pop();
	return Qu[pos].front();
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		S.insert(i);
		for (int j = 19; j >= 0; j--)
			if (a[i] & (1 << j)) cnt[j][i] = true, tot[j]++, Qu[j].push(i);
	}
	while (!S.empty())
	{
		int u = *S.rbegin();
		S.erase(u);
		for (int i = 19; i >= 0; i--)
			if (tot[i] && !(a[u] & (1 << i)))
			{
				int v = get(i);
				for (int j = 0; j <= 19; j++)
					if (cnt[j][v]) cnt[j][v] = false, tot[j]--;
				int tmp1 = a[u], tmp2 = a[v];
				S.erase(v);
				a[u] = tmp1 | tmp2, a[v] = tmp1 & tmp2;
				S.insert(v);
				for (int j = 0; j <= 19; j++)
					if (a[v] & (1 << j)) cnt[j][v] = true, tot[j]++, Qu[j].push(v);
			}
		for (int i = 0; i <= 19; i++)
			if (cnt[i][u]) cnt[i][u] = false, tot[i]--;
	}
	for (int i = 1; i <= n; i++)
		ans += a[i] * (long long) a[i];
	printf("%lld", ans);
	return 0;
}