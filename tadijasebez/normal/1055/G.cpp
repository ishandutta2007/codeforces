#include <bits/stdc++.h>
using namespace std;
const bool debug=0;
#define ll long long
#define mp make_pair
#define pb push_back
struct pt{ ll x,y;pt(){}pt(ll a, ll b):x(a),y(b){}};
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
pt operator * (pt a, ll b){ return pt(a.x*b,a.y*b);}
pt operator / (pt a, ll b){ return pt(a.x/b,a.y/b);}
bool operator < (pt a, pt b){ return mp(a.x,a.y)<mp(b.x,b.y);}
bool operator > (pt a, pt b){ return b<a;}
ll cross(pt a, pt b){ return a.x*b.y-b.x*a.y;}
ll dot(pt a, pt b){ return a.x*b.x+a.y*b.y;}
ll sq(pt a){ return dot(a,a);}
ll dist(pt a, pt b){ return sq(a-b);}
struct line{ pt v;ll c;line(){}line(pt a, pt b):v(a-b),c(cross(v,a)){}};
ll side(line a, pt b){ return a.c-cross(a.v,b);}
void ccw(vector<pt> &a)
{
	if(cross(a[1]-a[0],a[2]-a[0])<0) reverse(a.begin(),a.end());
}
void rot(vector<pt> &a)
{
	ccw(a);
	int mn=0;
	for(int i=0;i<a.size();i++) if(a[mn]>a[i]) mn=i;
	vector<pt> b;
	for(int i=0;i<a.size();i++) b.pb(a[(mn+i)%a.size()]);
	a=b;
}
vector<pt> Minkowski(vector<pt> a, vector<pt> b)
{
    rot(a);
    rot(b);
    int asz=a.size(),bsz=b.size();
    vector<pt> ret,d1,d2;
    for(int i=0;i<asz;i++) d1.pb(a[(i+1)%asz]-a[i]);
    for(int i=0;i<bsz;i++) d2.pb(b[(i+1)%bsz]-b[i]);
    ret.pb(a[0]+b[0]);
	int i=0,j=0;
	while(i<asz || j<bsz)
	{
		if(i==asz) ret.pb(ret.back()+d2[j++]);
		else if(j==bsz) ret.pb(ret.back()+d1[i++]);
		else if(cross(d1[i],d2[j])>0) ret.pb(ret.back()+d1[i++]);
		else ret.pb(ret.back()+d2[j++]);
	}
	return ret;
}
vector<pt> operator - (vector<pt> a)
{
	vector<pt> b;
	for(int i=0;i<a.size();i++) b.pb(pt(-a[i].x,-a[i].y));
	return b;
}
bool CheckInside(vector<pt> a, pt b)
{
	for(int i=0;i<a.size();i++) if(cross(a[i]-b,a[(i+1)%a.size()]-b)<0) return 0;
	return 1;
}
bool Check(vector<pt> a, pt b, ll r)
{
    if(CheckInside(a,b)) return 1;
	for(pt p:a) if(dist(p,b)<r*r) return 1;
	for(int i=0;i<a.size();i++)
	{
		pt f=a[i],s=a[(i+1)%a.size()];
		line l=line(s,f);
		if(!(dot(f,l.v)<=dot(b,l.v) && dot(b,l.v)<=dot(s,l.v))) continue;
		ll dist=abs(side(l,b));
		if(debug)
		{
			if(dist*dist<r*r*sq(l.v))
			{
				printf("f:(%lld %lld) s:(%lld %lld) b:(%lld %lld)\n",f.x,f.y,s.x,s.y,b.x,b.y);
				printf("%lld %lld %lld\n",dot(f,l.v),dot(b,l.v),dot(s,l.v));
				printf("dist:%lld r*r*sq(l.v):%lld sq(l.v):%lld\n",dist,r*r*sq(l.v),sq(l.v));
			}
		}
		if(dist*dist<r*r*sq(l.v)) return 1;
	}
	return 0;
}
const int N=100050;
const int inf=1e9+7;
int s,t;
struct Edge{ int u,v,c;Edge(){}Edge(int a, int b, int d):u(a),v(b),c(d){}};
vector<Edge> edges;
vector<int> G[N];
void AddEdge(int u, int v, int c)
{
	G[u].pb(edges.size());
	edges.pb(Edge(u,v,c));
	G[v].pb(edges.size());
	edges.pb(Edge(v,u,0));
}
int was[N],Dist[N];
bool BFS()
{
	for(int i=s;i<=t;i++) was[i]=0,Dist[i]=inf;
	Dist[s]=0;
	queue<int> q;
	q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int e:G[u])
		{
			int v=edges[e].v;
			int c=edges[e].c;
			if(c && Dist[v]>Dist[u]+1)
			{
				Dist[v]=Dist[u]+1;
				q.push(v);
			}
		}
	}
	return Dist[t]!=inf;
}
int Cut(int u, int flow)
{
	if(u==t) return flow;
	if(Dist[u]>=Dist[t]) return 0;
	int ans=0;
	for(;was[u]<G[u].size();was[u]++)
	{
		int e=G[u][was[u]];
		int v=edges[e].v;
		int c=edges[e].c;
		if(!c || Dist[v]!=Dist[u]+1) continue;
		int cut=Cut(v,min(flow,c));
		edges[e].c-=cut;
		edges[e^1].c+=cut;
		ans+=cut;
		flow-=cut;
		if(!flow) return ans;
	}
	return ans;
}
int MaxFlow()
{
	int Flow=0;
	while(BFS()) Flow+=Cut(s,inf);
	return Flow;
}
struct circle{ pt cen;ll r;circle(){}circle(ll x, ll y, ll z):cen(x,y),r(z){}};
circle Jellyfish[N];
int main()
{
	int n,W,m;
	scanf("%i %i",&n,&W);
	vector<pt> a,b,sum;
	a.resize(n);
	for(int i=0;i<n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
	ll mnx=inf,mxx=-inf;
	for(pt p:a) mnx=min(mnx,p.x),mxx=max(mxx,p.x);
	int len=mxx-mnx;
	b=-a;
	sum=Minkowski(a,b);
	scanf("%i",&m);
	s=0;t=m*2+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&Jellyfish[i].cen.x,&Jellyfish[i].cen.y,&Jellyfish[i].r);
		AddEdge(i*2-1,i*2,1);
		if(Jellyfish[i].cen.x-Jellyfish[i].r<len) AddEdge(s,i*2-1,inf);
		if(W-(Jellyfish[i].cen.x+Jellyfish[i].r)<len) AddEdge(i*2,t,inf);
	}
	for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++)
	{
		if(Check(sum,Jellyfish[i].cen-Jellyfish[j].cen,Jellyfish[i].r+Jellyfish[j].r))
		{
			AddEdge(i*2,j*2-1,inf);
			AddEdge(j*2,i*2-1,inf);
			if(debug) printf("(%i %i)\n",i,j);
		}
	}
	printf("%i\n",MaxFlow());
	if(debug) for(pt p:sum) printf("(%lld %lld) ",p.x,p.y);printf("\n");
    return 0;
}