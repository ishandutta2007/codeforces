#include <bits/stdc++.h>
using namespace std;

const int Maxn = 6000005;
int n, q, a[Maxn], ans[Maxn], f[Maxn], pos[Maxn][15], las[35];
vector <pair <int, int> > Ve[Maxn], fac[Maxn];
vector <int> tmp;
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		tmp.clear();
		int x;
		scanf("%d", &x);
		int maxi = sqrt(x);
		for (int j = 2; j <= maxi; j++)
			if (x % j == 0)
			{
				bool ct = 0;
				while (x % j == 0) x /= j, ct ^= 1;
				if (ct) tmp.push_back(j); 
			}
		if (x != 1) tmp.push_back(x);
		for (int s = 0; s < (1 << (int) tmp.size()); s++)
		{
			long long v = 1;
			for (int j = 0; j < (int) tmp.size(); j++)
				if (s & (1 << j)) v *= tmp[j];
			fac[i].push_back(make_pair(v, __builtin_popcount(s)));
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Ve[y].push_back(make_pair(x, i));
	}
	for (int i = 1; i <= n; i++)
	{
		int val = fac[i].back().second;
		for (auto now : fac[i])
		{
			for (int j = 0; j <= 7; j++)
				las[val + j - 2 * now.second] = max(las[val + j - 2 * now.second], pos[now.first][j]);
			pos[now.first][val] = i;
		}
		for (auto now : Ve[i])
			for (int j = 14; j >= 0; j--)
				if (las[j] >= now.first) ans[now.second] = j;
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}