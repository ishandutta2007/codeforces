#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[200005],sz[200005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
struct edge
{
	int u,v,w;
}E[500005];
inline bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
pair <int,int> b[400006];
int ans[200005];

signed main(int argc, char** argv) {
	int n,q;
	cin >> n >> q;
	for(int i=1;i<n;i++)
		cin >> E[i].u >> E[i].v >> E[i].w;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	sort(E+1,E+n,cmp);
	for(int i=1;i<=q;i++)
	{
		cin >> b[i].first;
		b[i].second=i;
	}
	sort(b+1,b+q+1);
	int now=0,qwq=0;
	for(int i=1;i<=q;i++)
	{
		while(now<n-1&&E[now+1].w<=b[i].first)
		{
			++now;
			int u=E[now].u,v=E[now].v;
			if(ff(u)==ff(v)) continue;
			qwq-=sz[ff(u)]*(sz[ff(u)]-1)/2;
			qwq-=sz[ff(v)]*(sz[ff(v)]-1)/2;
			sz[ff(v)]+=sz[ff(u)];
			fa[ff(u)]=ff(v);
			qwq+=sz[ff(v)]*(sz[ff(v)]-1)/2;
		}
		ans[b[i].second]=qwq;
	}
	for(int i=1;i<=q;i++)
		cout << ans[i] << " ";
	return 0;
}