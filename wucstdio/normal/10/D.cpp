#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[505],b[505],f[505][505],from[505][505],res[505],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	int x=0,y=0;
	a[0]=-1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		f[i][j]=f[i][j-1];
		from[i][j]=i;
		if(a[i]==b[j])
		{
			for(int k=0;k<i;k++)
			  if(a[k]<a[i]&&f[k][j]+1>f[i][j])
			    f[i][j]=f[k][j]+1,from[i][j]=k;
		}
		if(f[i][j]>f[x][y])x=i,y=j;
	}
	printf("%d\n",ans=f[x][y]);
	while(x)
	{
		res[f[x][y]]=a[x];
		while(from[x][y]==x)y--;
		x=from[x][y];
	}
	for(int i=1;i<=ans;i++)printf("%d ",res[i]);
	printf("\n");
	return 0;
}