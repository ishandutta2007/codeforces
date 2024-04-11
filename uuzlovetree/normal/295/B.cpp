#include<bits/stdc++.h>
#define maxn 505
#define ll long long
using namespace std;
const int inf = (int)1e9;
int n;
int dis[maxn][maxn];
bool has[maxn];
int p[maxn];
ll ans[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)scanf("%d",&dis[i][j]);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int k=n;k>=1;--k)
	{
		int x=p[k];
		has[x]=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(dis[i][j]>dis[i][x]+dis[x][j])dis[i][j]=dis[i][x]+dis[x][j];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)if(has[i]&&has[j])ans[k]+=1ll*dis[i][j];
	}
	for(int k=1;k<=n;++k)printf("%I64d ",ans[k]);
	return 0;
}