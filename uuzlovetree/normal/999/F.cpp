#include<bits/stdc++.h>
#define maxn 505
#define ll long long
using namespace std;
int n,k;
int c[maxn*10],f[maxn],h[maxn];
int has[100005];
vector<int> val[100005];
int dp[maxn][maxn*10];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*k;++i)
	{
		scanf("%d",&c[i]);
		has[c[i]]++;
	}
	for(int i=1;i<=n;++i)scanf("%d",&f[i]),val[f[i]].push_back(i);
	for(int i=1;i<=k;++i)scanf("%d",&h[i]);
	int ans=0;
	for(int i=1;i<=100000;++i)if(val[i].size())
	{
		int tot=has[i],r=val[i].size(),mx=min(tot,r*k);
		for(int j=1;j<=r;++j)
		{
			for(int x=1;x<=mx;++x)
			{
				for(int y=1;y<=x&&y<=k;++y)
				{
					dp[j][x]=max(dp[j][x],dp[j-1][x-y]+h[y]);
				}
			}
		}
		ans+=dp[r][mx];
		for(int j=1;j<=r;++j)
		for(int x=1;x<=mx;++x)dp[j][x]=0;
	}
	cout<<ans<<endl;
	return 0;
}