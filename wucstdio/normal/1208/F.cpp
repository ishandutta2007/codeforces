#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans,a[2000005],f[4000005],g[4000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g[a[i]]=f[a[i]],f[a[i]]=i;
	}
	for(int s=(1<<21)-1;s>=0;s--)
	{
		for(int i=0;i<21;i++)
		{
			if((1<<i)&s)
			{
				int ss=s^(1<<i);
				if(f[s]>f[ss])g[ss]=f[ss],f[ss]=f[s];
				else if(f[s]>g[ss]&&f[s]!=f[ss])g[ss]=f[s];
				if(g[s]>f[ss])g[ss]=f[ss],f[ss]=g[s];
				else if(g[s]>g[ss]&&g[s]!=f[ss])g[ss]=g[s];
			}
		}
	}
	for(int i=1;i<=n-2;i++)
	{
		int nows=0;
		for(int j=20;j>=0;j--)
		{
			if((1<<j)&a[i])continue;
			if(g[nows|(1<<j)]>i)nows|=(1<<j);
		}
		ans=max(ans,nows|a[i]);
	}
	printf("%d\n",ans);
	return 0;
}