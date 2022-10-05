#include <bits/stdc++.h>
using namespace std;
int n,a[100005],back[100005];
bool vis[100005],front[100005];
long long ans;
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(!vis[a[i]])
		{
			vis[a[i]]=true;
			front[i]=true;
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=n;i>=1;i--)
	{
		if(!vis[a[i]])
		{
			vis[a[i]]=true;
			back[i]=back[i+1]+1;
		}
		else
			back[i]=back[i+1];
	}
	for(int i=1;i<=n;i++)
		if(front[i])
			ans+=back[i+1];
	printf("%I64d",ans);
	return 0;
}