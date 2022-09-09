#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=100050;
const int inf=1e9;
int par[N];ll w[N];
void Init(){ for(int i=0;i<N;i++) par[i]=i,w[i]=0;}
int Find(int x){ return x==par[x]?x:par[x]=Find(par[x]);}
priority_queue<pair<ll,int> ,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
ll min(ll a, ll b){ return a>b?b:a;}
vector<pair<int,int> > sol;
int main()
{
	int n,m,p,q,i,u,v,l;
	scanf("%i %i %i %i",&n,&m,&p,&q);
	int c=n;Init();
	while(m--)
	{
		scanf("%i %i %i",&u,&v,&l);
		if(Find(u)==Find(v)) w[Find(u)]+=l;
		else w[Find(u)]+=w[Find(v)]+l,par[Find(v)]=Find(u),c--;
	}
	if(c<q || c-p>q) return printf("NO\n"),0;
	for(i=1;i<=n;i++) if(par[i]==i) pq.push(mp(w[i],i));
	while(c>q)
	{
		int x=pq.top().second;
		pq.pop();
		int y=pq.top().second;
		pq.pop();
		l=min(w[x]+w[y]+1,inf);
		w[x]+=w[y]+l;
		par[y]=x;
		sol.pb(mp(x,y));
		pq.push(mp(w[x],x));
		c--;p--;
	}
	if(c==n && p) return printf("NO\n"),0;
	for(i=1;i<=n;i++) if(par[i]!=i) u=i,v=par[i];
	while(p--) sol.pb(mp(u,v));
	printf("YES\n");
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}