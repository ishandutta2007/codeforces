#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int a[300005], b[300005];
int bt[300005];
int actual[300005];
bool visit[300005];
bool visit2[300005];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

	queue<int> que;

	visit[n] = true;
	visit2[n] = true;
	que.push(n);
	while (!que.empty())
	{
		int pos = que.front(); que.pop();

		if (pos == 0)
		{
			vector<int> ans = { 0 };
			while (ans.back() < n)
			{
				ans.push_back(bt[ans.back()]);
			}

			ans.pop_back();

			reverse(ans.begin(), ans.end());
			printf("%zd\n", ans.size());
			for (int t : ans) printf("%d ", actual[t]);
			printf("\n");
			return 0;
		}

		for (int L = pos - a[pos]; !visit[L]; L++)
		{
			visit[L] = true;
			int nxt = L + b[L];
			if (visit2[nxt]) continue;
			actual[nxt] = L;
			bt[nxt] = pos;
			visit2[nxt] = true;
			que.push(nxt);
		}
	}

	printf("-1\n");
}