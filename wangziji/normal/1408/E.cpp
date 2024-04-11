#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005],b[100005];
struct edge
{
	int u,v,w;
}e[500005];
int cnt,fa[500005];
inline bool cmp(edge x,edge y)
{
	return x.w>y.w; 
}
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
int main(int argc, char** argv) {
	int n,m;
	cin >> m >> n;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	long long ans=0;
	for(int i=1;i<=500000;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int s;
		scanf("%d",&s);
		while(s--)
		{
			int t;
			scanf("%d",&t);
			e[++cnt]={i+200000,t,a[i]+b[t]};
			ans+=a[i]+b[t];
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
	//	cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
		if(ff(e[i].u)!=ff(e[i].v))
		{
			ans-=e[i].w;
			fa[ff(e[i].u)]=ff(e[i].v);
		}
	}
	cout << ans;
	return 0;
}