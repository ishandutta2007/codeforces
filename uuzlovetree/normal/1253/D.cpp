#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,m;
int fa[maxn],sz[maxn],mx[maxn];
int find(int x)
{
	while(x!=fa[x])x=fa[x];
	return x;
}
void merge(int u,int v)
{
	if(find(u)==find(v))return;
	int fu=find(u),fv=find(v);
	if(sz[fu]<sz[fv])fa[fu]=fv,mx[fv]=max(mx[fv],mx[fu]),sz[fv]+=sz[fu];
	else fa[fv]=fu,mx[fu]=max(mx[fu],mx[fv]),sz[fu]+=sz[fv];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1,mx[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		merge(u,v);
	}
	int ans=0;
	for(int l=1;l<=n;++l)
	{
		for(int r=l+1;r<mx[find(l)];++r)
		{
			if(find(l)!=find(r))ans++,merge(l,r);
		}
		l=mx[find(l)];
	}
	cout<<ans<<endl;
}