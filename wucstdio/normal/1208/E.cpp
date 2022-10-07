#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,w,m,lg2[1000005],a[1000005],maxx[26][1000005];
ll ans[1000005];
inline int ask(int l,int r)
{
	int d=lg2[r-l+1];
	return max(maxx[d][l],maxx[d][r-(1<<d)+1]);
}
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=2;i<=1000000;i++)
	  lg2[i]=lg2[i>>1]+1;
	while(n--)
	{
		scanf("%d",&m);
		for(int i=1;i<=m;i++)scanf("%d",&maxx[0][i]);
		for(int i=1;i<=lg2[m];i++)
		  for(int j=1;j<=m;j++)
		    maxx[i][j]=max(maxx[i-1][j],maxx[i-1][j+(1<<(i-1))]);
		if(w<=2*m)
		{
			for(int i=1;i<=w;i++)
			{
				int l=m-w+i,r=i;
				l=max(l,1),r=min(r,m);
				ll v=ask(l,r);
				if(m-w+i<1||i>m)v=max(v,0ll);
				ans[i]+=v,ans[i+1]-=v;
			}
		}
		else
		{
			int v1=0,v2=0;
			for(int i=1;i<=m;i++)
			{
				v1=max(v1,maxx[0][i]);
				v2=max(v2,maxx[0][m-i+1]);
				ans[i]+=v1,ans[i+1]-=v1;
				ans[w-i+1]+=v2,ans[w-i+2]-=v2;
			}
			ans[m+1]+=v1,ans[w-m+1]-=v1;
		}
	}
	for(int i=1;i<=w;i++)
	{
		ans[i]+=ans[i-1];
		printf("%lld ",ans[i]);
	}
	printf("\n");
	return 0;
}