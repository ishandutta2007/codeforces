#include<cstdio>
#include<algorithm>
#include<queue>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define ll long long
#define N 100005
#define M 800005

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
	inline int dinic(int s,int t){
		int res=0;
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
		addedge(t,s,inf);
	}
	inline int sol(){
		return dinic(s,t);
	}
}
using MF::init;
using MF::addedge;
using MF::sol;

int n,m,g,a[N],val[N];

int tot,s,t;

int ans;

int main(){
	scanf("%d%d%d",&n,&m,&g);
	tot=n,s=++tot,t=++tot;
	init(tot+2*m,s,t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		if(!a[i])
			addedge(s,i,val[i]);
		else
			addedge(i,t,val[i]);
	}
	for(int i=1;i<=m;i++){
		int b,w,k,tp;
		scanf("%d%d%d",&b,&w,&k);
		ans+=w;
		tot+=2;
		for(int j=1;j<=k;j++){
			int u;
			scanf("%d",&u);
			addedge(tot-1,u,inf);
			addedge(u,tot,inf);
		}
		scanf("%d",&tp);
		if(!b)
			addedge(s,tot-1,w+tp*g);
		else
			addedge(tot,t,w+tp*g);
	}
	printf("%d\n",ans-sol());
}