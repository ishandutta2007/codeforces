#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
#define maxn 100005
using namespace std;
const int mo = 1e9 + 7;
int n, m;
vector<int> G[maxn];
int d[maxn], q, a, b;
int main()
{
	scanf("%d%d", &n, &m);
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		d[a]++, d[b]++; 
		if(a > b) G[b].push_back(a);
		else G[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) ans += (ll)G[i].size() * (d[i] - G[i].size()); 
	printf("%lld\n", ans);
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &a);
		ans -= G[a].size() * (d[a] - G[a].size());
		while(!G[a].empty())
		{
			int x = G[a].back();
			G[a].pop_back();
			ans -= G[x].size() * (d[x] - G[x].size());
			G[x].push_back(a);
			ans += G[x].size() * (d[x] - G[x].size());
		}
		printf("%lld\n", ans);
	}
	return 0;
}