#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,_a[1000005],*a[1000005],val[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i]=_a+(i-1)*m;
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	}
	int ans=0;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)val[i]=i-1+n;
		for(int i=1;i<=n;i++)
		{
			if((a[i][j]-1)%m+1==j&&a[i][j]<=n*m)
			  val[(i+n-(a[i][j]-1)/m-1)%n+1]--;
		}
		int x=2147483647;
		for(int i=1;i<=n;i++)x=min(x,val[i]);
		ans+=x;
	}
	printf("%d\n",ans);
	return 0;
}