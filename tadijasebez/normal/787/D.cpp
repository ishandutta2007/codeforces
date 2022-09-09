#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=5*N;
const ll inf=9e18;
vector<pair<int,int> > E[M];
int ls[M],rs[M],up,dw,tsz;
void Build(int &c, int &d, int ss, int se)
{
	c=++tsz;d=++tsz;
	if(ss==se){ c=d=ss;return;}
	int mid=ss+se>>1;
	Build(ls[c],ls[d],ss,mid);
	Build(rs[c],rs[d],mid+1,se);
	E[ls[c]].pb(mp(c,0));
	E[rs[c]].pb(mp(c,0));
	E[d].pb(mp(ls[d],0));
	E[d].pb(mp(rs[d],0));
}
void Add(int c, int ss, int se, int qs, int qe, int t, int u, int w)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ if(t==1) E[u].pb(mp(c,w));else E[c].pb(mp(u,w));return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,t,u,w);
	Add(rs[c],mid+1,se,qs,qe,t,u,w);
}
ll dist[M];
void Dijkstra(int s)
{
	for(int i=1;i<=tsz;i++) dist[i]=inf;
	dist[s]=0;
	priority_queue<pair<ll,int> , vector<pair<ll,int> > , greater<pair<ll,int> > > pq;
	pq.push(mp(0,s));
	while(pq.size())
	{
		int u=pq.top().second;
		ll d=pq.top().first;
		pq.pop();
		if(d!=dist[u]) continue;
		for(auto p:E[u])
		{
			int v=p.first;
			int w=p.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push(mp(dist[v],v));
			}
		}
	}
}
int main()
{
    int n,m,s,i,t,l,r,u,v,w;
    scanf("%i %i %i",&n,&m,&s);
    tsz=n;
    Build(up,dw,1,n);
    while(m--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i %i %i",&u,&v,&w),E[u].pb(mp(v,w));
		if(t==2) scanf("%i %i %i %i",&u,&l,&r,&w),Add(dw,1,n,l,r,1,u,w);
		if(t==3) scanf("%i %i %i %i",&u,&l,&r,&w),Add(up,1,n,l,r,0,u,w);
	}
	Dijkstra(s);
	for(i=1;i<=n;i++) printf("%lld ",dist[i]==inf?-1:dist[i]);
	return 0;
}