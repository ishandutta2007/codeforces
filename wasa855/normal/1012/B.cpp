#include<bits/stdc++.h>
using namespace std;
int fa[400005];
int find(int x)
{
	int i=x;
	while(i!=fa[i])
	{
		i=fa[i];
	}
	int j;
	while(x!=fa[x])
	{
		j=x;
		x=fa[x];
		fa[j]=i;
	}
	return i;
}
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=1;i<=m+n;i++)
	{
		fa[i]=i;
	}
	int u,v;
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d",&u,&v);
		int x=find(u),y=find(v+m);
		fa[x]=y;
	}
	u=find(1);
	int ans=0;
	for(int i=1;i<=m+n;i++)
	{
		v=find(i);
		if(u!=v)
		{
			ans++;
			fa[v]=u;
		}
	}
	cout<<ans<<endl;
	return 0;
}
// LUOGU HAVE BUG !!!!!!!!!!!!