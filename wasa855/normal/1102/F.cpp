#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
int n,m;
int a[20][10005];
int dis[20][20];
int f[1048576][20];
int work(int t)
{
	memset(f,0,sizeof(f));
	f[1<<(t-1)][t]=INF;
	int T=1<<n;
	for(int i=1;i<T;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i&(1<<(j-1)))==0)
			{
				continue;
			}
			for(int k=1;k<=n;k++)
			{
				if((i&(1<<(k-1)))==0)
				{
					continue;
				}
				int to=min(f[i-(1<<(j-1))][k],dis[k][j]);
//				printf("**%d %d %d %d %d\n",i,f[i-(1<<(j-1))][k],j,k,to);
				if(f[i][j]<to)
				{
					f[i][j]=to;
				}
			}
		}
	}
//	for(int i=1;i<T;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",f[i][j]);
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=f[T-1][i];
		for(int j=1;j<m;j++)
		{
			if(abs(a[t][j+1]-a[i][j])<tmp)
			{
				tmp=abs(a[t][j+1]-a[i][j]);
			}
		}
		if(tmp>ans)
		{
			ans=tmp;
		}
	}
//	cout<<ans<<endl;
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(abs(a[i][k]-a[j][k])<dis[i][j])
				{
					dis[i][j]=abs(a[i][k]-a[j][k]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",dis[i][j]);
//		}
//		cout<<"\n";
//	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=work(i);
		if(x>ans)
		{
			ans=x;
		}
	}
	cout<<ans<<endl;
	return 0;
}