#include <bits/stdc++.h>
using namespace std;

int T, n, k, ct;
string str;
pair <int, int> P[200005];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		int ans = 0, las = -1;
		scanf("%d%d", &n, &k);
		cin >> str;
		for (int i = 0; i < n; i++)
			if (str[i] == 'W')
				P[++ct] = make_pair(las + 1, i - las - 1), las = i;
		if (n - las - 1 > 0)
			P[++ct] = make_pair(las + 1, n - las - 1);
		sort(P + 1, P + 1 + ct, [](pair <int, int> x, pair <int, int> y){if (x.first + x.second == n) return false;if (y.first + y.second == n) return true;if (x.first == 0) return false;if (y.first == 0) return true;return x.second < y.second;});
		for (int i = 1; i <= ct; i++)
			if (P[i].first)
			{
				for (int j = P[i].first; j <= P[i].first + P[i].second - 1; j++)
					if (k) str[j] = 'W', k--;
			}
			else
			{
				for (int j = P[i].first + P[i].second - 1; j >= P[i].first; j--)
					if (k) str[j] = 'W', k--;
			}
		for (int i = 0; i < n; i++)
			if (str[i] == 'W')
			{
				ans++;
				if (i && str[i - 1] == 'W') ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}