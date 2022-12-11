#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n,k;
int x[maxn],last[maxn];
bool vis[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	int tot=0;
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&x[i]);
		last[x[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=k;++i)
	{
		vis[x[i]]=1;
		if(last[x[i]]==i)
		{
			if(x[i]!=1&&!vis[x[i]-1])ans++;
			if(x[i]!=n&&!vis[x[i]+1])ans++;
		}
	}
	for(int i=1;i<=n;++i)if(!vis[i])
	{
		ans+=3;if(i==1)ans--;if(i==n)ans--;
	}
	printf("%d\n",ans);
	return 0;
}