#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, q, know[Maxn], End[Maxn], opt[Maxn], lt[Maxn], rt[Maxn], x[Maxn], maxi[Maxn][21];
set <int> Se;
int ask(int lt, int rt)
{
	if (lt > rt) return 0;
	int Range = log2(rt - lt + 1);
	return End[maxi[lt][Range]] > End[maxi[rt - (1 << Range) + 1][Range]] ? maxi[lt][Range] : maxi[rt - (1 << Range) + 1][Range];
}
void killed(int lt, int rt, int tim)
{
	while (true)
	{
		set <int> :: iterator it = Se.lower_bound(lt);
		if (it != Se.end() && *it <= rt) End[*it] = tim, Se.erase(it);
		else break;
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) Se.insert(i), know[i] = End[i] = 0x3f3f3f3f;
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &opt[i]);
		if (!opt[i]) scanf("%d%d%d", &lt[i], &rt[i], &x[i]);
		else scanf("%d", &x[i]);
	}
	for (int i = 1; i <= q; i++)
		if (!opt[i] && !x[i]) killed(lt[i], rt[i], i);
	for (int i = 1; i <= n; i++) maxi[i][0] = i;
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			maxi[i][j] = End[maxi[i][j - 1]] > End[maxi[i + (1 << (j - 1))][j - 1]] ? maxi[i][j - 1] : maxi[i + (1 << (j - 1))][j - 1];
	for (int i = 1; i <= q; i++)
		if (!opt[i] && x[i])
		{
			int res = ask(lt[i], rt[i]);
			know[res] = min(know[res], max(i, max(End[ask(lt[i], res - 1)], End[ask(res + 1, rt[i])])));
		}
	for (int i = 1; i <= q; i++)
		if (opt[i])
		{
			if (End[x[i]] <= i) puts("NO");
			else if (know[x[i]] <= i) puts("YES");
			else puts("N/A\n");
		}
	return 0;
}