#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 2000005
using namespace std;
int n, m;
char s[maxn];
vector<int> a[maxn]; 
vector<int> cf[maxn], cf2[maxn];
int check(int ans)
{
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			cf[i][j] = cf2[i][j] = 0;
		}
	}
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			if(a[i][j] == 1) continue;
			cf[max(1, i - ans)][max(1, j - ans)]++;
			cf[max(1, i - ans)][min(m, j + ans) + 1]--;
			cf[min(n, i + ans) + 1][max(1, j - ans)]--;
			cf[min(n, i + ans) + 1][min(m, j + ans) + 1]++;
//			printf("%d %d %d %d\n", max(1, i - ans), min(n, i + ans) + 1, max(1, j - ans), min(m, j + ans) + 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cf[i][j] = cf[i - 1][j] + cf[i][j - 1] + cf[i][j] - cf[i - 1][j - 1];
			if(cf[i][j] == 0)
			{
				cf2[max(1, i - ans)][max(1, j - ans)]++;
				cf2[max(1, i - ans)][min(m, j + ans) + 1]--;
				cf2[min(n, i + ans) + 1][max(1, j - ans)]--;
				cf2[min(n, i + ans) + 1][min(m, j + ans) + 1]++;
//				if(ans == 1) printf("%d %d\n", i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cf2[i][j] = cf2[i - 1][j] + cf2[i][j - 1] + cf2[i][j] - cf2[i - 1][j - 1];
			if(cf2[i][j] == 0 && a[i][j]) return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m + 2; i++)
	{
		cf[0].push_back(0);
		a[0].push_back(0);
		cf2[0].push_back(0);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		a[i].push_back(0);
		cf[i].push_back(0);
		cf2[i].push_back(0);
		for (int j = 1; j <= m; j++)
		{
			if(s[j] == 'X') a[i].push_back(1);
			else a[i].push_back(0);
			cf[i].push_back(0); 
		cf2[i].push_back(0);
		}
		a[i].push_back(0);
		cf[i].push_back(0);
		cf2[i].push_back(0);
	}
	for (int i = 1; i <= m + 2; i++)
	{
		cf[n + 1].push_back(0);
		cf2[n + 1].push_back(0);
		a[n + 1].push_back(0);
	}
	int l = 0, r = min(n - 1, m - 1) / 2, mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	check(l);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(cf[i][j] == 0) printf("X");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}