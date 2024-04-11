#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int maxi,n,a[Maxn],q,opt[Maxn],pos[Maxn],x[Maxn]; 
bool vis[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=q;i>=1;i--)
	{
		scanf("%d",&opt[i]);
		if(opt[i]==1)
			scanf("%d%d",&pos[i],&x[i]);
		else scanf("%d",&x[i]);
	}
	for(int i=1;i<=q;i++)
	{
		if(opt[i]==1)
		{
			int u=pos[i];
			if(!vis[u])
				vis[u]=true,a[u]=max(maxi,x[i]);
		}
		else
			maxi=max(maxi,x[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",!vis[i]?max(maxi,a[i]):a[i]);
	return 0;
}