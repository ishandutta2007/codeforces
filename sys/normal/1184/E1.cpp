#include <bits/stdc++.h>
using namespace std;
const int Maxn=1000005;
int n,m,fa[Maxn];
bool choose[Maxn];
int get_fa(int x)
{
	return x==fa[x]?x:fa[x]=get_fa(fa[x]);
}
void merge(int x,int y)
{
	int a=get_fa(x),b=get_fa(y);
	fa[a]=b;
}
struct Edg
{
	int x,y,w,id;
	bool operator < (const Edg &tmp) const
	{
		if(w!=tmp.w) return w<tmp.w;
		return id<tmp.id;
	}
}Edge[Maxn];
void kruskal(void)
{
	memset(choose,0,sizeof(choose));
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(Edge+1,Edge+1+m);
	for(int i=1;i<=m;i++)
	{
		int x=Edge[i].x,y=Edge[i].y;
		if(get_fa(x)!=get_fa(y))
		{
			merge(x,y);
			choose[Edge[i].id]=true;
		}
	}
}
bool check(int mid)
{
	for(int i=1;i<=m;i++)
		if(Edge[i].id==1) Edge[i].w=mid;
	kruskal();
	return choose[1];
}
int main()
{
//	freopen("E.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&Edge[i].x,&Edge[i].y,&Edge[i].w),Edge[i].id=i;
	int l=0,r=1e9;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	if(check(r))
		printf("%d",r);
	else printf("%d",l);
	return 0;
}