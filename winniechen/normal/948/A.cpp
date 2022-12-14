#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N 505
int map[N][N],n,m;
char s[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='.')
			{
				map[i][j]=0;
			}else if(s[j]=='S')
			{
				map[i][j]=1;
			}else if(s[j]=='W')
			{
				map[i][j]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]==-1)
			{
				if(map[i-1][j]==1||map[i][j-1]==1||map[i+1][j]==1||map[i][j+1]==1)
				{
					printf("No\n");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]==1)printf("S");
			else if(map[i][j]==-1)printf("W");
			else printf("D");
		}
		puts("");
	}
	return 0;
}