#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m;
int a[maxn];
int pre[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	a[n+1]=m;
	int ans=0;
	for(int i=1;i<=n+1;++i)if(i&1)ans+=a[i]-a[i-1];
	for(int i=1;i<=n+1;++i)if(i&1)pre[i]=pre[i-1]+a[i]-a[i-1];else pre[i]=pre[i-1];
	pre[n+2]=pre[n+1];
	if(a[1]!=(a[0]+1))
	{
		int tmp=pre[0]+1+(m-(a[0]+1)-(pre[n+1]-pre[0]-1));
		ans=max(ans,tmp);
	}
	if(a[n]!=(a[n+1]-1))
	{
		int tmp=pre[n+1]-1+(m-(a[n+1]-1)-(pre[n+1]-pre[n+1]+1));
		ans=max(ans,tmp);
	}
	for(int i=1;i<=n;++i)
	{
		if(!(i&1))
		{
			if(a[i-1]!=(a[i]-1))
			{
				int tmp=pre[i]+(m-(a[i]-1)-(pre[n+1]-pre[i-1]));
				ans=max(ans,tmp);
			}
			if(a[i+1]!=(a[i]+1))
			{
				int tmp=pre[i]+1+(m-(a[i]+1)-(pre[n+1]-pre[i]-1));
				ans=max(ans,tmp);
			}
		}
		else
		{
			if(a[i-1]!=(a[i]-1))
			{
				int tmp=pre[i]-1+(m-(a[i]-1)-(pre[n+1]-pre[i]+1));
				ans=max(ans,tmp);
			}
			if(a[i+1]!=(a[i]+1))
			{
				int tmp=pre[i]+(m-(a[i]+1)-(pre[n+1]-pre[i]));
				ans=max(ans,tmp);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}