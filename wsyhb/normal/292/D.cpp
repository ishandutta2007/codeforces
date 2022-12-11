#include<bits/stdc++.h>
using namespace std;
const int max_m=1e4+5;
const int max_n=500+5;
int fa[max_m<<1][max_n]; // prefix: 1 ~ m  suffix: m+1 ~ 2m
int get_fa(int k,int x)
{
	return fa[k][x]!=x?fa[k][x]=get_fa(k,fa[k][x]):x;
}
inline bool merge(int k,int x,int y)
{
	x=get_fa(k,x),y=get_fa(k,y);
	if(x!=y)
	{
		fa[k][x]=y;
		return true;
	}
	return false;
}
int x[max_m],y[max_m];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;++i)
		fa[0][i]=fa[m<<1|1][i]=i;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			fa[i][j]=fa[i-1][j];
		merge(i,x[i],y[i]);
	}
	for(int i=(m<<1);i>=m+1;--i)
	{
		for(int j=1;j<=n;++j)
			fa[i][j]=fa[i+1][j];
		merge(i,x[i-m],y[i-m]);
	}
	int k;
	scanf("%d",&k);
	int id=2*m+2;
	while(k--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		for(int i=1;i<=n;++i)
			fa[id][i]=fa[l-1][i];
		for(int i=1;i<=n;++i)
			merge(id,fa[m+r+1][i],i);
		int ans=0;
		for(int i=1;i<=n;++i)
			ans+=get_fa(id,i)==i;
		printf("%d\n",ans);
	}
	return 0;
}