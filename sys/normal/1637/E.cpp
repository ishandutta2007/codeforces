#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, m, X, Y;
set <pair <int, int> > Se;
map <int, int> Ma;
vector <int> V, Ve[Maxn];
struct cmp
{
	bool operator () (const pair <int, int> x, const pair <int, int> y)
	{
		return make_pair(Ve[X][x.first] + Ve[Y][x.second], x) < make_pair(Ve[X][y.first] + Ve[Y][y.second], y);
	}
};
set <pair <int, int>, cmp> S;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		for (auto u : V) Ve[u].clear();
		V.clear();
		long long ans = 0;
		scanf("%d%d", &n, &m);
		Se.clear(), Ma.clear();
		for (int i = 1, x; i <= n; i++)
			scanf("%d", &x), Ma[x]++;
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			Se.insert(make_pair(x, y)), Se.insert(make_pair(y, x));
		}
		for (auto u : Ma)
		{
			Ve[u.second].push_back(u.first);
			V.push_back(u.second);
		}
		sort(V.begin(), V.end());
		V.resize(unique(V.begin(), V.end()) - V.begin());
		for (auto u : V) sort(Ve[u].begin(), Ve[u].end());
		for (auto x : V) for (auto y : V)
		{
			S.clear();
			X = x, Y = y;
			S.insert(make_pair(Ve[x].size() - 1, Ve[y].size() - 1));
			while (!S.empty())
			{
				pair <int, int> now = *S.rbegin();
				S.erase(*S.rbegin());
				if (Se.find(make_pair(Ve[x][now.first], Ve[y][now.second])) == Se.end() && !(x == y && now.first == now.second))
				{
					ans = max(ans, 1LL * (x + y) * (Ve[x][now.first] + Ve[y][now.second]));
					break;
				}
				else
				{
					if (now.first) S.insert(make_pair(now.first - 1, now.second));
					if (now.second) S.insert(make_pair(now.first, now.second - 1));
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}