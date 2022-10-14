#include <bits/stdc++.h>
#define SZ 100005
#define BT 512*1024*2
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n,q,s,id[SZ],cc[BT],mx;
vector<P> g[BT];
ll dist[BT];
void addEdge(int u,int v,int w)
{
//	printf("%d %d %d\n",u,v,w);
	g[u].push_back(P(v,w));
}
void build1(int v,int l,int r)
{
	if(l>r) return;
	if(l==r) { id[l]=v; return; }
//	printf("%d %d %d????\n",v,l,r);
	int m=(l+r)/2;
	build1(v*2+1,l,m);
	build1(v*2+2,m+1,r);
	addEdge(v,v*2+1,0);
	addEdge(v,v*2+2,0);
}
void build2(int v,int l,int r)
{
	if(l>r) return;
	if(l==r) { cc[v]=id[l]; return; }
	cc[v]=mx+v+1;
	int m=(l+r)/2;
	build2(v*2+1,l,m);
	build2(v*2+2,m+1,r);
	addEdge(cc[v*2+1],cc[v],0);
	addEdge(cc[v*2+2],cc[v],0);
}
void upd(int ql,int qr,int v,int l,int r,int i,int w,int t)
{
	if(qr<l||ql>r) return;
	if(ql<=l&&r<=qr)
	{
		if(t==0) addEdge(i,v,w);
		if(t==1) addEdge(cc[v],i,w);
		return;
	}
	int m=(l+r)/2;
	upd(ql,qr,v*2+1,l,m,i,w,t);
	upd(ql,qr,v*2+2,m+1,r,i,w,t);
}
void dijkstra()
{
	memset(dist,-1,sizeof(dist));
	set <pair <ll,int> > st;
	dist[id[s]]=0;
	st.insert({0,id[s]});
	while(!st.empty())
	{
		auto it=st.begin();
		int i=it->second;
		st.erase(it);
		for(auto e:g[i])
		{
			int v=e.first;
			int w=e.second;
			if(dist[v]==-1||dist[v]>dist[i]+w)
			{
				if(dist[v]!=-1) st.erase(st.find({dist[v],v}));
				dist[v]=dist[i]+w;
				st.insert({dist[v],v});
			}
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&q,&s);
	build1(0,1,n);
	mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,id[i]);
	build2(0,1,n);
	while(q--)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			addEdge(id[u],id[v],w);
		}
		else if(t==2)
		{
			int v,l,r,w;
			scanf("%d %d %d %d",&v,&l,&r,&w);
			upd(l,r,0,1,n,id[v],w,0);
		}
		else
		{
			int v,l,r,w;
			scanf("%d %d %d %d",&v,&l,&r,&w);
			upd(l,r,0,1,n,id[v],w,1);
		}
	}
	dijkstra();
	for(int i=1;i<=n;i++) printf("%lld ",dist[id[i]]);
	return 0;
}