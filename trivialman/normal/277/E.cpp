#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 805, M = 2e5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	int x, y;
}a[N];
int to[M],cap[M],nxt[M],head[N],path[N],v[N];
queue<int> Q;
int n,m,q,tot=1,S,T,x,y,z,i;
double ans=0,cost[M],d[N];
 
void add(int x,int y,int z,double w){
	to[++tot]=y,cap[tot]=z,cost[tot]=w,nxt[tot]=head[x],head[x]=tot;
	to[++tot]=x,cap[tot]=0,cost[tot]=-w,nxt[tot]=head[y],head[y]=tot;
}

bool spfa(){
	memset(v,0,sizeof(v));
	rep(i,0,N-1) d[i] = INF;
	Q.push(S),d[S]=0,v[S]=1;
	while(!Q.empty()){
		x=Q.front(),Q.pop(),v[x]=0;
		for(i=head[x];i;i=nxt[i])
			if(cap[i]&&d[y=to[i]]>d[x]+cost[i]){
				d[y]=d[x]+cost[i],path[y]=i;
				if(!v[y]) Q.push(y),v[y]=1;
			}
	}
	return d[T]<INF;
}

void update(){
	for(y=T;y!=S;y=x){
		i=path[y],x=to[i^1];
		--cap[i],++cap[i^1];
	}
	ans+=d[T];
}

double dist(dat x, dat y){
	int dx=x.x-y.x, dy=x.y-y.y;
	return sqrt(dx*dx+dy*dy);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n) cin>>a[i].x>>a[i].y;
	S = 0, T = 2*n+1;
	rep(i,1,n) add(S,i,2,0), add(n+i,T,1,0);
	rep(i,1,n) rep(j,1,n) if(a[i].y>a[j].y) add(i,n+j,1,dist(a[i],a[j]));
	int flow = 0;
	while(spfa()) update(), flow++;
	if(flow<n-1) cout<<"-1\n";
	else cout<<setprecision(10)<<fixed<<ans<<endl;
	return 0;
}