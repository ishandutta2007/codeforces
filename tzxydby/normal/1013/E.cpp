#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],f[N][N],g[N][N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	f[1][1]=max(0,a[2]-a[1]+1);
	g[1][0]=0;
	g[1][1]=1e9;
	f[2][1]=max(0,a[1]-a[2]+1)+max(0,a[3]-a[2]+1);
	g[2][0]=0;
	g[2][1]=f[1][1];
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=(i+1)/2;j++)
		{
			if(j==1)
			{
				f[i][j]=max(0,a[i-1]-a[i]+1)+max(0,a[i+1]-a[i]+1);
				g[i][j]=min(g[i-1][j],f[i-1][j]);
			}
			else
			{
				f[i][j]=min(f[i-2][j-1]+max((a[i-1]-max(0,a[i-1]-a[i-2]+1))-a[i]+1,0)+max(a[i+1]-a[i]+1,0),
				g[i-2][j-1]+max(0,a[i-1]-a[i]+1)+max(0,a[i+1]-a[i]+1));
				g[i][j]=min(g[i-1][j],f[i-1][j]);
			}
			//printf("<%d,%d>:%d %d ",i,j,f[i][j],g[i][j]);
		}
		//puts("");
	}
	for(int i=1;i<=(n+1)/2;i++)
	{
		int ans=0x3f3f3f3f;
		for(int j=1;j<=n;j++)
			if(f[j][i]<ans)
				ans=f[j][i];
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}