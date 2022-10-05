#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, b[Maxn];
vector <int> p, V[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n + 1; i++) V[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]), V[b[i]].push_back(i);
		int lasA = n + 1, lasB = 0, maxi = 0;
		p.clear();
		while (p.size() != n)
		{
			sort(V[lasA].begin(), V[lasA].end(), [](int x, int y){return V[x].size() < V[y].size();});
			for (auto u : V[lasA])
				p.push_back(u), maxi = max(maxi, u);
			lasB = V[lasA].size() ? V[lasA].back() : lasB;
			V[lasA].clear();
			sort(V[lasB].begin(), V[lasB].end(), [](int x, int y){return V[x].size() < V[y].size();});
			for (auto u : V[lasB])
				p.push_back(u);
			lasA = V[lasB].size() ? V[lasB].back() : lasA;
			V[lasB].clear();
		}
		printf("%d\n", maxi);
		for (auto u : p)
			printf("%d ", u);
		puts("");
	}
	return 0;
}