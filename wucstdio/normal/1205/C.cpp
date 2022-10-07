#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool ans[105][105],f[55][55][55][55],g[55][55][55][55];
void DP()
{
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    f[i][j][i][j]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i!=n&&ans[i][j]==ans[i+1][j])f[i][j][i+1][j]=1;
		if(j!=n&&ans[i][j]==ans[i][j+1])f[i][j][i][j+1]=1;
	}
	for(int len=0;len<=2*n;len++)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(n+n-i-j<len)break;
			for(int dx=0;dx<=len;dx++)
			{
				int dy=len-dx;
				if(i+dx>n||j+dy>n)continue;
				int x=i+dx,y=j+dy;
				if(f[i][j][x][y]==0)continue;
				if(ans[i-1][j]==ans[x+1][y])f[i-1][j][x+1][y]=1;
				if(ans[i-1][j]==ans[x][y+1])f[i-1][j][x][y+1]=1;
				if(ans[i][j-1]==ans[x+1][y])f[i][j-1][x+1][y]=1;
				if(ans[i][j-1]==ans[x][y+1])f[i][j-1][x][y+1]=1;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	ans[1][1]=1;
	ans[n][n]=0;
	printf("? 1 1 2 2\n");
	fflush(stdout);
	int s;
	scanf("%d",&s);
	ans[2][2]=s;
	for(int i=1;i<=n;i++)
	for(int j=((i&1)?1:2);j<n;j+=2)
	{
		if((j==1||j==2)&&i+2<=n)
		{
			printf("? %d %d %d %d\n",i,j,i+2,j);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			ans[i+2][j]=ans[i][j]^x^1;
		}
		if(j+2>n)break;
		printf("? %d %d %d %d\n",i,j,i,j+2);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		ans[i][j+2]=ans[i][j]^x^1;
	}
	for(int i=1;i<=n;i++)
	for(int j=((i&1)?2:1);j<n;j+=2)
	{
		if((j==1||j==2)&&i+2<=n)
		{
			printf("? %d %d %d %d\n",i,j,i+2,j);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			ans[i+2][j]=ans[i][j]^x^1;
		}
		if(j+2>n)break;
		printf("? %d %d %d %d\n",i,j,i,j+2);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		ans[i][j+2]=ans[i][j]^x^1;
	}
	printf("? 1 2 2 3\n");
	fflush(stdout);
	scanf("%d",&s);
	if((s==0&&ans[1][2]==ans[2][3])||(s==1&&ans[1][2]!=ans[2][3]))
	{
		for(int i=2;i<n;i+=2)
		  for(int j=1;j<=n;j+=2)
		    ans[i][j]^=1;
	}
	DP();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=i;k<=n;k++)
	for(int l=j;l<=n;l++)
	  g[i][j][k][l]=f[i][j][k][l];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	  for(int j=((i&1)?2:1);j<=n;j+=2)
		ans[i][j]^=1;
	DP();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=i;k<=n;k++)
	for(int l=j;l<=n;l++)
	{
		if(k+l-i-j<=2)continue;
		if(f[i][j][k][l]!=g[i][j][k][l])
		{
			printf("? %d %d %d %d\n",i,j,k,l);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x==g[i][j][k][l])
			{
				for(int xx=1;xx<=n;xx++)
				  for(int yy=((xx&1)?2:1);yy<=n;yy+=2)
					ans[xx][yy]^=1;
			}
			printf("!\n");
			for(int xx=1;xx<=n;xx++)
			{
				for(int yy=1;yy<=n;yy++)
				  printf("%d",ans[xx][yy]);
				printf("\n");
			}
			return 0;
		}
	}
	return 0;
}