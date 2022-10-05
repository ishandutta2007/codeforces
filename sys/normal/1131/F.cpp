#include <bits/stdc++.h>
using namespace std;
const int Maxn=150005;
int n,a[Maxn],head[Maxn],nxt[Maxn],rea[Maxn];
bool vis[Maxn];
int get_head(int x)
{
	return head[x]==x?x:head[x]=get_head(head[x]);
}
int get_nxt(int x)
{
	return nxt[x]==x?x:nxt[x]=get_nxt(nxt[x]);
}
void merge(int x,int y)
{
	int a=get_nxt(x),b=get_head(y);
	rea[a]=b;
	head[b]=a;
	nxt[a]=b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) head[i]=i,nxt[i]=i;
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		merge(a,b);
	}
	for(int i=1;i<=n;i++)
		vis[rea[i]]=true;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int u=i;
			for(int j=1;j<=n;j++)
			{
				printf("%d ",u);
				u=rea[u];
			}
			return 0;
		}
	return 0;
}