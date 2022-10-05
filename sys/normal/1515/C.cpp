#include <bits/stdc++.h>
using namespace std;

int T, n, m, val[100005];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > Pr;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		puts("YES");
		scanf("%d%d%*d", &n, &m);
		while (!Pr.empty()) Pr.pop();
		for (int i = 1; i <= m; i++) val[i] = 0, Pr.push(make_pair(0, i));
		for (int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			int u = Pr.top().second;
			Pr.pop();
			val[u] += a;
			Pr.push(make_pair(val[u], u));
			printf("%d ", u);
		}
		puts("");
	}
	return 0;
}