#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[505][505];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=2;i<n;i++)
	for(int j=2;j<m;j++)
	{
		if(s[i][j]=='*'&&s[i-1][j]=='*'&&s[i+1][j]=='*'&&s[i][j-1]=='*'&&s[i][j+1]=='*')
		{
			s[i][j]='.';
			int x=j-1;
			while(s[i][x]=='*')
			{
				s[i][x]='.';
				x--;
			}
			x=j+1;
			while(s[i][x]=='*')
			{
				s[i][x]='.';
				x++;
			}
			x=i-1;
			while(s[x][j]=='*')
			{
				s[x][j]='.';
				x--;
			}
			x=i+1;
			while(s[x][j]=='*')
			{
				s[x][j]='.';
				x++;
			}
			for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
			{
				if(s[x][y]=='*')
				{
					printf("NO\n");
					return 0;
				}
			}
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}