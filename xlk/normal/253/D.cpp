#include <bits/stdc++.h>
using namespace std;
int n, m, d;
long long z;
int s[420][420];
char a[420][420];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
		for (int j = 0; j < m; j++)
		{
			s[i + 1][j] = s[i][j] + (a[i][j] == 'a');
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int c = 0, v[256] = {};
			for (int l = 0, k = -1; k < m; ++k, c += s[j+1][k] - s[i][k])
			{
				for (; c > d; c -= s[j+1][l] - s[i][l], l++)
				{
					if (a[j][l] == a[i][l])
					{
						v[a[i][l]]--;
					}
				}
				if (l <= k && a[i][k] == a[j][k])
				{
					z += v[a[i][k]]++;
				}
			}
		}
	}
	printf("%lld\n", z);
	return 0;
}