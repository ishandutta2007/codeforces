#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[200005],b[200005],w[200005],fa[200005],S[200005];
vector <int> v[200005];
struct edge
{
	int u,v,w;
}e[200005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
inline bool cmp(edge x,edge y)
{
	return x.w>y.w;
}
inline void merge(int x,int y)
{
	x=ff(x),y=ff(y);
	if(x==y) --S[y];
	else fa[x]=y,S[y]+=S[x],S[y]--;
}
int main()
{
	int n,m; 
	cin >> m >> n;
	for(int i=1;i<=m;i++) fa[i]=i,S[i]=1;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if((S[ff(e[i].u)]+S[ff(e[i].v)]))
		{
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	cout << ans;
	return 0;
}