#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,m,a[15][200005],ans,b[200005],maxl[200005];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%I64d",&a[i][j]);
	if(m==1)
	{
		printf("%I64d\n",n*(n+1)/2);
		return 0;
	}
	for(int i=1;i<=n;i++)
	  b[a[m][i]]=i;
	m--;
	memset(maxl,0x3f,sizeof(maxl));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		  a[i][j]=b[a[i][j]];
		maxl[a[i][1]]=1;
		for(int j=2;j<=n;j++)
		{
			if(a[i][j]==a[i][j-1]+1)
			  maxl[a[i][j]]=min(maxl[a[i][j]],maxl[a[i][j-1]]+1);
			else maxl[a[i][j]]=1;
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		  printf("%I64d ",a[i][j]);
//		printf("\n");
//	}
	for(int i=1;i<=n;i++)
	  ans+=maxl[i];
	printf("%I64d\n",ans);
	return 0;
}