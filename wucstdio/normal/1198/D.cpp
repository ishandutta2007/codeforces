#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,f[55][55][55][55],sum[55][55];
char s[55][55];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='#');
	for(int l1=1;l1<=n;l1++)
	for(int l2=1;l2<=n;l2++)
	{
		for(int i=1;i+l1-1<=n;i++)
		for(int j=1;j+l2-1<=n;j++)
		{
			f[i][i+l1-1][j][j+l2-1]=max(l1,l2);
			for(int x=i;x<=i+l1-1;x++)
			{
				if(sum[x][j+l2-1]-sum[x][j-1]-sum[x-1][j+l2-1]+sum[x-1][j-1]==0)
				{
					f[i][i+l1-1][j][j+l2-1]=min(f[i][i+l1-1][j][j+l2-1],f[i][x-1][j][j+l2-1]+f[x+1][i+l1-1][j][j+l2-1]);
				}
				  
			}
			for(int y=j;y<=j+l2-1;y++)
			{
				if(sum[i+l1-1][y]-sum[i-1][y]-sum[i+l1-1][y-1]+sum[i-1][y-1]==0)
				{
					f[i][i+l1-1][j][j+l2-1]=min(f[i][i+l1-1][j][j+l2-1],f[i][i+l1-1][j][y-1]+f[i][i+l1-1][y+1][j+l2-1]);
				}
				  
			}
		}
	}
	printf("%d\n",f[1][n][1][n]);
	return 0;
}