#include<cstdio>
#include<algorithm>
#include<queue>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define ll long long
#define N 400005
#define M 800005

namespace MF{
	bool flg;
	
	int n,m,s,t;
	
	int hd[N],_hd;
	struct edge{
		int v,f,id,nxt;
	}e[M<<1];
	inline void addedge(int u,int v,int f,int id=0){
		e[++_hd]=(edge){v,f,id,hd[u]};
		hd[u]=_hd;
		e[++_hd]=(edge){u,0,id,hd[v]};
		hd[v]=_hd;
	}
	
	int cur[N],dis[N];
	std::queue<int> q;
	inline bool bfs(int s,int t){
		for(int i=1;i<=n+2;i++)
			cur[i]=hd[i];
		for(int i=1;i<=n+2;i++)
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
		flg=0;
		for(int i=1;i<=n+2;i++)
			hd[i]=0;
		_hd=1;
		n=n_,s=s_,t=t_;
		addedge(t,s,inf);
	}
	inline void adde(int u,int v,int l,int r,int id=0){
//		printf("&%d %d %d %d\n",u,v,l,r);
		if(l>r)
			flg=1;
		addedge(u,v,r-l,id);
		f[u]-=l,f[v]+=l;
	}
	inline int sol(){
		if(flg)
			return -1;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(f[i]>0){
				addedge(n+1,i,f[i]);
				sum+=f[i];
			}
			else if(f[i]<0)
				addedge(i,n+2,-f[i]);
		}
		if(dinic(n+1,n+2)!=sum)
			return -1;
		return dinic(s,t);
	}
}
using MF::init;
using MF::adde;
using MF::sol;

int n,m,r,b;

pii a[N];

struct qry{
	int t,l,d;
}q[N];

int vx[N],tx,vy[N],ty;

int s,t;

int deg[N],d[N];

ll ans;
int col[N];

int main(){
	scanf("%d%d%d%d",&n,&m,&r,&b);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].fir,&a[i].sec);
		vx[++tx]=a[i].fir,vy[++ty]=a[i].sec;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].t,&q[i].l,&q[i].d);
		if(q[i].t==1)
			vx[++tx]=q[i].l;
		else
			vy[++ty]=q[i].l;
	}
	std::sort(vx+1,vx+tx+1);
	tx=std::unique(vx+1,vx+tx+1)-vx-1;
	std::sort(vy+1,vy+ty+1);
	ty=std::unique(vy+1,vy+ty+1)-vy-1;
	s=tx+ty+1,t=tx+ty+2;
	init(tx+ty+2,s,t);
	for(int i=1;i<=n;i++){
		a[i].fir=std::lower_bound(vx+1,vx+tx+1,a[i].fir)-vx;
		a[i].sec=std::lower_bound(vy+1,vy+ty+1,a[i].sec)-vy;
		adde(a[i].fir,tx+a[i].sec,0,1,i);
		deg[a[i].fir]++,deg[a[i].sec+tx]++;
	}
	for(int i=1;i<=tx+ty;i++)
		d[i]=inf;
	for(int i=1;i<=m;i++){
		int t=q[i].t,l=q[i].l,dd=q[i].d;
		if(q[i].t==1){
			l=std::lower_bound(vx+1,vx+tx+1,l)-vx;
			d[l]=std::min(d[l],dd);
		}
		else{
			l=std::lower_bound(vy+1,vy+ty+1,l)-vy;
			d[l+tx]=std::min(d[l+tx],dd);
		}
	}
	for(int i=1;i<=tx;i++)
		adde(s,i,std::max(0,(deg[i]-d[i]+1)/2),(deg[i]+d[i])/2);
	for(int i=1;i<=ty;i++)
		adde(i+tx,t,std::max(0,(deg[i+tx]-d[i+tx]+1)/2),(deg[i+tx]+d[i+tx])/2);
	int tmp=sol();
	if(tmp==-1){
		puts("-1");
		return 0;
	}
	ans=1ll*std::min(r,b)*tmp+1ll*std::max(r,b)*(n-tmp);
	printf("%lld\n",ans);
	for(int u=1;u<=tx;u++)
		for(int i=MF::hd[u];i;i=MF::e[i].nxt)
			if(!MF::e[i].f&&MF::e[i].id)
				col[MF::e[i].id]=1;
	for(int i=1;i<=n;i++)
		putchar((r<=b)^col[i]?'b':'r');
	puts("");
}