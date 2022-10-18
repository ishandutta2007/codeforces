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
	}
	inline int sol(){
		return dinic(s,t);
	}
}
using MF::init;
using MF::addedge;
using MF::sol;

int n,m;

pii e[N];

inline bool chk(int x,int tp=0){
	int s=n+m+1,t=n+m+2;
	init(n+m+2,s,t);
	for(int i=1;i<=m;i++){
		addedge(s,i,1);
		addedge(i,e[i].fir+m,1);
		addedge(i,e[i].sec+m,1);
	}
	for(int i=1;i<=n;i++)
		addedge(i+m,t,x);
	bool res=sol()==m;
	if(tp){
		for(int u=1;u<=m;u++)
			for(int i=MF::hd[u];i;i=MF::e[i].nxt)
				if(!MF::e[i].f){
					int v=MF::e[i].v;
					if(v==e[u].fir+m)
						printf("%d %d\n",e[u].fir,e[u].sec);
					else if(v==e[u].sec+m)
						printf("%d %d\n",e[u].sec,e[u].fir);
				}
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	if(!m){
		puts("0");
		return 0;
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&e[i].fir,&e[i].sec);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)){
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	printf("%d\n",ans);
	chk(ans,1);
}