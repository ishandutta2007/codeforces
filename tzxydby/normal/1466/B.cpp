#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N],vis[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2+1;i++)
			a[i]=vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		int ans=0;
		for(int i=n*2;i>=1;i--)
		{
			if(!a[i])
				continue;
			if(vis[i+1])
			{
				vis[i]=1;
				continue;
			}
			if(a[i]==1)
				vis[i+1]=1;
			else
				vis[i]=vis[i+1]=1;
		}
		for(int i=1;i<=n*2+1;i++)
			ans+=vis[i];
		printf("%d\n",ans);
	}
	return 0;
}