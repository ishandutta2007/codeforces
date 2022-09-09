#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
int p[N],c[N];
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
/*{
	if(p[x]==x) return x;
	int f=Find(p[x]);
	c[x]+=c[p[x]];
	return p[x]=f;
}*/
void Union(int u, int v)
{
	u=Find(u);v=Find(v);
	c[v]+=c[u];
	p[u]=v;
}
vector<pair<int,pair<int,int> > > edges;
int main()
{
	int n,m,k,i,x,u,v,w;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) p[i]=i,c[i]=0;
	for(i=1;i<=k;i++) scanf("%i",&x),c[x]=1;
	while(m--) scanf("%i %i %i",&u,&v,&w),edges.pb(mp(w,mp(u,v)));
	sort(edges.begin(),edges.end());
	for(auto e:edges)
	{
		int w=e.first;
		int u=e.second.first;
		int v=e.second.second;
		if(Find(u)!=Find(v))
		{
			Union(u,v);
			if(c[Find(v)]==k)
			{
				for(i=1;i<=k;i++) printf("%i ",w);
				return 0;
			}
		}
	}
	return 0;
}