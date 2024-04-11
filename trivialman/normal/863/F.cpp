#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 105, M = 50000;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int to[M],cap[M],cost[M],nxt[M],head[N],path[N],d[N],v[N];
queue<int> Q;
int l[N], r[N];
int n,m,q,tot=1,S,T,ans=0,x,y,z,i;
 
void add(int x,int y,int z,int w){
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
	return d[T]!=INF;
}

void update(){
	for(y=T;y!=S;y=x){
		i=path[y],x=to[i^1];
		--cap[i],++cap[i^1];
	}
	ans+=d[T];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>q;
	rep(i,1,n) l[i]=1, r[i]=n;
	rep(i,1,q){
		int x,y,z,w;
		cin>>w>>x>>y>>z;
		if(w==1){
			rep(j,x,y) l[j] = max(l[j], z);
		}else{
			rep(j,x,y) r[j] = min(r[j], z);
		}
	}
	rep(i,1,n) if(l[i]>r[i]){
		cout<<"-1\n";
		return 0;
	}
	S=0, T=2*n+1;
	rep(i,1,n){
		add(S, i, 1, 0);
		rep(j,1,n) add(n+i, T, 1, j*2-1);
		rep(j,l[i],r[i]) add(i, n+j, 1, 0);
	}
	while(spfa()) update();
	cout<<ans<<endl;
	return 0;
}