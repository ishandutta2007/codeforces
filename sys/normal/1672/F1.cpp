#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, c, a[Maxn], b[Maxn];
vector <int> Ve[Maxn], C[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		c = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) Ve[i].clear(), C[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), Ve[a[i]].push_back(i);
		for (int i = 1; i <= n; i++) c = max(c, (int) Ve[i].size());
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= (int) Ve[i].size(); j++)
				C[j].push_back(Ve[i][j - 1]);
		for (int i = 1; i <= c; i++)
			for (int j = 0; j < (int) C[i].size(); j++)
				b[C[i][j]] = a[C[i][(j + 1) % (int) C[i].size()]];
		for (int i = 1; i <= n; i++)
			printf("%d ", b[i]);
	}
	return 0;
}