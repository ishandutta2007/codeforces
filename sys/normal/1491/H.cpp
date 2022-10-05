#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005;
int n, m, per, a[Maxn], nxt[Maxn], bel[Maxn], shift[Maxn], tot[Maxn];
void rebuild(int x)
{
	for (int i = (x - 1) * per + 1; i <= x * per; i++)
		if (a[i] < (x - 1) * per + 1) nxt[i] = a[i];
		else nxt[i] = nxt[a[i]];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
		scanf("%d", &a[i]);
	int bloc = sqrt(n);
	per = (n + bloc - 1) / bloc;
	for (int i = 1; i <= n; i++) bel[i] = (i - 1) / per + 1;
	for (int i = 1; i <= bloc; i++) rebuild(i);
	while (m--)
	{
		int opt, lt, rt, v;
		scanf("%d%d%d", &opt, &lt, &rt);
		if (opt == 1)
		{
			scanf("%d", &v);
			for (int i = bel[lt] + 1; i < bel[rt]; i++)
			{
				tot[i] = min(0x3f3f3f3f, tot[i] + v);
				if (tot[i] <= per)
				{
					for (int j = (i - 1) * per + 1; j <= i * per; j++) a[j] = max(a[j] - v, 1);
					rebuild(i);
				}
				else shift[i] = min(0x3f3f3f3f, shift[i] + v);
			}
			if (bel[lt] != bel[rt])
			{
				for (int i = lt; i <= bel[lt] * per; i++) a[i] = max(a[i] - v, 1);
				for (int i = (bel[rt] - 1) * per + 1; i <= rt; i++) a[i] = max(a[i] - v, 1);
			}
			else for (int i = lt; i <= rt; i++) a[i] = max(a[i] - v, 1);
			if (!shift[bel[lt]]) rebuild(bel[lt]);
			if (!shift[bel[rt]]) rebuild(bel[rt]);
		}
		else
		{
			while (lt != rt)
			{
				if (lt < rt) swap(lt, rt);
				if (!shift[bel[lt]] && !shift[bel[rt]] && nxt[lt] != nxt[rt]) lt = nxt[lt];
				else if (!shift[bel[lt]] && nxt[lt] >= rt) lt = nxt[lt];
				else
					lt = max(a[lt] - shift[bel[lt]], 1);
			}
			printf("%d\n", lt);
		}
	}
	return 0;
}