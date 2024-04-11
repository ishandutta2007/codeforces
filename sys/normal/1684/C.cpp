#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, m, maxi[Maxn], mini[Maxn];
vector <int> a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		pair <int, int> ans = make_pair(0, 0);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			a[i].resize(m + 1);
			int pos1 = 0, pos2 = 0;
			mini[m + 1] = 0x3f3f3f3f;
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]), maxi[j] = max(maxi[j - 1], a[i][j]);
			for (int j = m; j >= 1; j--)
				mini[j] = min(mini[j + 1], a[i][j]);
			for (int j = 1; j <= m; j++)
				if (a[i][j] > mini[j + 1] && !pos1) pos1 = j;
			for (int j = m; j >= 1; j--)
				if (a[i][j] < maxi[j - 1] && !pos2) pos2 = j;
			if (pos1) ans = make_pair(pos1, pos2);
		}
		if (!ans.first) ans = make_pair(1, 1);
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			swap(a[i][ans.first], a[i][ans.second]);
			for (int j = 1; j < m; j++)
				if (a[i][j] > a[i][j + 1]) flag = false;
		}
		if (flag) printf("%d %d\n", ans.first, ans.second);
		else puts("-1");
	}
	return 0;
}