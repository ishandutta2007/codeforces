#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, a[Maxn], b[Maxn];
vector <int> V[2];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0;
		scanf("%d", &n);
		V[0].clear(), V[1].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ans += a[i], V[b[i]].push_back(a[i]);
		sort(V[0].begin(), V[0].end(), greater <int> ());
		sort(V[1].begin(), V[1].end(), greater <int> ());
		if (V[0].size() < V[1].size()) swap(V[0], V[1]);
		for (int i = 0; i < (int) V[1].size(); i++)
			ans += V[0][i] + V[1][i];
		if (V[0].size() == V[1].size()) ans -= min(V[0].back(), V[1].back());
		printf("%lld\n", ans);
	}
	return 0;
}