#include<bits/stdc++.h>
using namespace std;
const int N=35;
int n,u,r,a[N],b[N],k[N],p[N];
long long ans=-2e18;
void dfs(int res,int las)
{
	int t[N];
	long long sum=0;
	for(int i=1;i<=n;i++)
		t[i]=a[i],sum+=1ll*t[i]*k[i];
	if(res%2==0)
		ans=max(ans,sum);
	if(!res)
		return;
	if(las!=1)
	{
		for(int i=1;i<=n;i++)
			a[i]^=b[i];
		dfs(res-1,1);
	}
	for(int i=1;i<=n;i++)
		a[i]=t[p[i]]+r;
	dfs(res-1,2);
	for(int i=1;i<=n;i++)
		a[i]=t[i];
}
int main()
{
	scanf("%d%d%d",&n,&u,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	dfs(u,2);
	printf("%lld\n",ans);
	return 0;
}