#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, q, a[Maxn];
vector <int> Ve;
vector <long long> val[35];
multiset <long long> Se[35];
void ask(void)
{
	long long ans = 0;
	for (int i = 0; i < (int) Ve.size(); i++)
		ans = max(ans, *Se[i].rbegin() * Ve[i]);
	printf("%lld\n", ans);
}
int main()
{
/*
n's factor p_1 ~ p_k

only p_i is useful

so O(\sum p_i)

*/
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int tmp = n;
		Ve.clear();
		for (int i = 2; i * i <= n; i++)
			if (tmp % i == 0)
			{
				Ve.push_back(n / i);
				while (tmp % i == 0) tmp /= i;
			}
		if (tmp != 1) Ve.push_back(n / tmp);
		for (int i = 0; i < (int) Ve.size(); i++)
		{
			val[i].clear();
			val[i].resize(Ve[i]);
			Se[i].clear();
			for (int j = 0; j < n; j++)
				val[i][j % Ve[i]] += a[j];
			for (auto u : val[i]) Se[i].insert(u);
		}
		ask();
		while (q--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			for (int i = 0; i < (int) Ve.size(); i++)
			{
				Se[i].erase(Se[i].find(val[i][x % Ve[i]]));
				val[i][x % Ve[i]] -= a[x];
				Se[i].insert(val[i][x % Ve[i]]);
			}
			a[x] = y;
			for (int i = 0; i < (int) Ve.size(); i++)
			{
				Se[i].erase(Se[i].find(val[i][x % Ve[i]]));
				val[i][x % Ve[i]] += a[x];
				Se[i].insert(val[i][x % Ve[i]]);
			}
			ask();
		}
	}
	return 0;
}