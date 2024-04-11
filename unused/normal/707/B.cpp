#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> graph[100005];
bool foo[100005];
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	for (int i = 0; i < k; i++)
	{
		int tmp;scanf("%d", &tmp); foo[tmp] = true;
	}

	int ans = 0x7fFFffFF;

	for (int i = 1; i <= n; i++)
	{
		if (!foo[i]) continue;
		for (auto &&e : graph[i])
		{
			if (foo[e.first]) continue;
			ans = min(ans, e.second);
		}
	}
	if (ans == 0x7fFFffFF)printf("-1");
	else printf("%d", ans);
}