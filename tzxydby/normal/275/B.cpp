#include<bits/stdc++.h>
using namespace std;
const int N=60;
char mp[N][N];
int r[N][N],c[N][N];
bool black(int a,int b,int x,int y)
{
	if(a==x)
		return r[a][b]==r[a][y];
	if(b==y)
		return c[a][b]==c[x][b];
	return (r[a][b]==r[a][y]&&c[x][y]==c[a][y]&&mp[a][y]=='B')||(c[a][b]==c[x][b]&&r[x][y]==r[x][b]&&mp[x][b]=='B');
}
int main()
{
	int n,m,flag=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='W')
				r[i][j]=1;
			r[i][j]+=r[i][j-1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[j][i]=='W')
				c[j][i]=1;
			c[j][i]+=c[j-1][i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=m;l++)
				{
					if(mp[i][j]=='B'&&mp[k][l]=='B')
					{
						if(!black(i,j,k,l))
						{
							puts("NO");
							return 0;
						}
					}
				}
			}
		}
	}
	puts("YES");
	return 0;
}