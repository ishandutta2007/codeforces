#include<bits/stdc++.h>
using namespace std;
int n,m,mod;
const int max_n=1e5+5;
int fa[max_n],sz[max_n];
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		fa[x]=y;
		sz[y]+=sz[x];
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=n;++i)
		fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		merge(a,b);
	}
	int ans=1,k=0;
	for(int i=1;i<=n;++i)
	{
		if(get_fa(i)==i)
		{
			++k;
			ans=1ll*ans*sz[i]%mod;
		}
	}
	if(k==1)
	{
		puts(mod>1?"1":"0");
		return 0;
	}
	for(int i=1;i<=k-2;++i)
		ans=1ll*ans*n%mod;
	printf("%d\n",ans);
    return 0;
}