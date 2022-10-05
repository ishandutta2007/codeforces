#include <bits/stdc++.h>
using namespace std;

int T, k, n, m;
vector <int> Ve1, Ve2;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Ve1.clear(), Ve2.clear();
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= k; i++)
		{
			int x;
			scanf("%d", &x);
			Ve1.push_back(x / n);
			Ve2.push_back(x / m);
		}
		sort(Ve1.begin(), Ve1.end(), greater <int> ());
		sort(Ve2.begin(), Ve2.end(), greater <int> ());
		int maxi = 0, mini = 0;
		for (auto u : Ve1)
		{
			if (u < 2) break;
			if (u >= 2)
			{
				maxi += u, mini += 2;
				if (maxi >= m && mini <= m)
				{
					puts("YES");
					goto END;
				}
			}
		}
		maxi = 0, mini = 0;
		for (auto u : Ve2)
		{
			if (u < 2) break;
			if (u >= 2)
			{
				maxi += u, mini += 2;
				if (maxi >= n && mini <= n)
				{
					puts("YES");
					goto END;
				}
			}
		}
		puts("NO");
		END:;
	}
	return 0;
}