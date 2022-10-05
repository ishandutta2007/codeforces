#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, ct, a[Maxn], b[Maxn], start[Maxn];
vector <int> Ve[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(b, -1, sizeof(int[n + 1]));
		memset(start, 0, sizeof(int[n + 1]));
		for (int i = 0; i <= n; i++) Ve[i].clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			Ve[a[i]].push_back(i);
		}
		int u = 1;
		ct = 1;
		while (true)
		{
			int pos1;
			A:pos1 = lower_bound(Ve[b[ct] + 1].begin(), Ve[b[ct] + 1].end(), start[ct]) - Ve[b[ct] + 1].begin();
			if (pos1 != (int) Ve[b[ct] + 1].size() && Ve[b[ct] + 1][pos1] < u)
			{
				b[ct]++;
				goto A;
			}
			if (u > n) break;
			int pos = lower_bound(Ve[b[ct] + 1].begin(), Ve[b[ct] + 1].end(), u) - Ve[b[ct] + 1].begin();
			if (pos == (int) Ve[b[ct] + 1].size())
			{
				if (b[ct] == -1) break;
				start[++ct] = u;
			}
			else b[ct]++, u = Ve[b[ct]][pos] + 1;
		}
		while (ct && b[ct] == -1) ct--;
		printf("%d\n", ct + (n + 1 - u));
		for (int i = 1; i <= ct + (n + 1 - u); i++)
			printf("%d ", b[i] + 1);
		puts("");
	}
	return 0;
}