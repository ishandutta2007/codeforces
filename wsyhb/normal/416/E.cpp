#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int max_n=500+5;
int dis[max_n][max_n];
const int max_m=124750+5;
int x[max_m],y[max_m],l[max_m],cnt[max_n];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=i!=j?inf:0;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",x+i,y+i,l+i);
		dis[x[i]][y[i]]=dis[y[i]][x[i]]=l[i];
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int s=1;s<=n-1;++s)
	{
		for(int i=1;i<=n;++i)
			cnt[i]=0;
		for(int i=1;i<=m;++i)
		{
			if(dis[s][x[i]]+l[i]==dis[s][y[i]])
				++cnt[y[i]];
			else if(dis[s][y[i]]+l[i]==dis[s][x[i]])
				++cnt[x[i]];
		}
		for(int t=s+1;t<=n;++t)
		{
			int ans=0;
			for(int i=1;i<=n;++i)
			{
				if(dis[s][i]+dis[i][t]==dis[s][t])
					ans+=cnt[i];
			}
			printf("%d%c",ans,s<n-1?' ':'\n');
		}
	}
	return 0;
}