#include<stdio.h>
int map[501][501], c[501];
char ans[510];
int main()
{
	int n, m, a, b;
	int i, j;
	scanf("%d%d", &n, &m);
	for(i=1; i<=m; i++)
	{
		scanf("%d%d", &a, &b);
		map[a][b] = map[b][a] = 1;
		c[a]++; c[b]++;
	}
	for(i=1; i<=n; i++)
	{
		if(c[i] == n-1) ans[i] = 'b';
	}
	for(i=1; i<=n; i++)
	{
		if(c[i]==n-1) continue;
		if(ans[i] == 0) ans[i] = 'a';
		for(j=1; j<=n; j++)
		{
			if(i==j || ans[j] == 'b') continue;
			if(ans[j] == 0) ans[j] = (map[i][j]?ans[i]:('c'-ans[i]+'a'));
			else if(ans[j] != (map[i][j]?ans[i]:('c'-ans[i]+'a')))
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes\n%s", ans+1);
	return 0;
}