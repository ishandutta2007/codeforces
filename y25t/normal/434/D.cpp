#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f3f
#define MX (inf>>7)
#define ll long long
#define N 20005
#define M 100005

namespace MF{
	int n,m,s,t;
	
	int hd[N],_hd;
	struct edge{
		int v,f,nxt;
	}e[M<<1];
	inline void addedge(int u,int v,int f){
		e[++_hd]=(edge){v,f,hd[u]};
		hd[u]=_hd;
		e[++_hd]=(edge){u,0,hd[v]};
		hd[v]=_hd;
	}
	
	int cur[N],dis[N];
	std::queue<int> q;
	inline bool bfs(int s,int t){
		for(int i=1;i<=n;i++)
			cur[i]=hd[i];
		for(int i=1;i<=n;i++)
			dis[i]=inf;
		dis[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=hd[u];i;i=e[i].nxt){
				int v=e[i].v,f=e[i].f;
				if(f&&dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		return dis[t]<inf;
	}
	inline int dfs(int u,int lmt,int t){
		if(u==t||!lmt)
			return lmt;
		int flw=0;
		for(int i=cur[u];i;i=e[i].nxt){
			cur[u]=i;
			int v=e[i].v,f=e[i].f;
			if(dis[v]!=dis[u]+1)
				continue;
			f=dfs(v,std::min(lmt,f),t);
			if(f){
				e[i].f-=f;
				e[i^1].f+=f;
				flw+=f;
				lmt-=f;
				if(!lmt)
					break;
			}
		}
		return flw;
	}
	inline ll dinic(int s,int t){
		ll res=0;
		while(bfs(s,t))
			res+=dfs(s,inf,t);
		return res;
	}
	
	int f[N];
	inline void init(int n_,int s_,int t_){
		for(int i=1;i<=n;i++)
			hd[i]=0;
		_hd=1;
		n=n_,s=s_,t=t_;
	}
	inline ll sol(){
		return dinic(s,t);
	}
}
using MF::init;
using MF::addedge;
using MF::sol;

int n,m,a[N],b[N],c[N],l[N],r[N];

inline int num(int x,int y){
	return (x)*300+y+150;
}

int s,t;

signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	s=num(n,101)+1,t=num(n,101)+2;
	init(num(n,101)+2,s,t);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
		addedge(s,num(i,l[i]),inf);
		for(int j=l[i];j<=r[i];j++)
			addedge(num(i,j),num(i,j+1),MX-(a[i]*j*j+b[i]*j+c[i]));
		addedge(num(i,r[i]+1),t,inf);
	}
	for(int i=1;i<=m;i++){
		int u,v,d;
		scanf("%lld%lld%lld",&u,&v,&d);
		for(int j=l[u];j<=r[u];j++)
			if(j-d>=l[v]&j-d<=r[v]+1)
				addedge(num(u,j),num(v,j-d),inf);
	}
	printf("%lld\n",n*MX-sol());
}