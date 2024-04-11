#include<cstdio>
#include<algorithm>
#include<queue>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 20005
#define M 200005

namespace MCMF{
	int n,s,t,ss,tt;
	
	int mc,mf;
	
	int hd[N],_hd;
	struct edge{
		int v,f,w,nxt;
	}e[M<<1];
	inline void addedge(int u,int v,int f,int w){
		e[++_hd]=(edge){v,f,w,hd[u]};
		hd[u]=_hd;
		e[++_hd]=(edge){u,0,-w,hd[v]};
		hd[v]=_hd;
	}
	
	int sum[N];
	inline void adde(int u,int v,int f,int w){
		if(w<0){
			addedge(v,u,f,-w);
			sum[u]-=f;
			sum[v]+=f;
			mc+=w*f;
		}
		else
			addedge(u,v,f,w);
	}
	
	std::priority_queue<pii> hp;
	int h[N],dis[N],flw[N],lst[N];
	bool vis[N];
	inline bool dij(int s,int t){
		for(int i=1;i<=n;i++){
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		flw[s]=inf;
		hp.push(mp(0,s));
		while(hp.size()){
			int u=hp.top().sec;
			hp.pop();
			if(vis[u])
				continue;
			vis[u]=1;
			for(int i=hd[u];i;i=e[i].nxt){
				int v=e[i].v,f=e[i].f,w=e[i].w;
				if(f&&dis[u]+w+h[u]-h[v]<dis[v]){
					dis[v]=dis[u]+w+h[u]-h[v];
					flw[v]=std::min(flw[u],f);
					lst[v]=i;
					hp.push(mp(-dis[v],v));
				}
			}
		}
		return vis[t];
	}
	inline void cal(int s,int t){
		while(dij(s,t)){
			int f=flw[t];
			mf+=f;
			mc+=f*(dis[t]-h[s]+h[t]);
			for(int u=t;u!=s;u=e[lst[u]^1].v){
				e[lst[u]].f-=f;
				e[lst[u]^1].f+=f;
			}
			for(int i=1;i<=n;i++)
				h[i]+=dis[i];
		}
	}
	
	inline void init(int n_,int s_,int t_){
		_hd=1;
		for(int i=1;i<=n;i++)
			hd[i]=h[i]=sum[i]=0;
		mc=0,mf=0;
		n=n_,s=s_,t=t_;
		ss=++n,tt=++n;
		addedge(t,s,inf,0);
	}
	inline pii sol(){
		for(int i=1;i<=n;i++)
			if(sum[i]>0)
				addedge(ss,i,sum[i],0);
			else
				addedge(i,tt,-sum[i],0);
		dij(ss,tt);
		for(int i=1;i<=n;i++)
			h[i]=dis[i];
		cal(ss,tt);
		mf=0;
		cal(s,t);
		return mp(mf,mc);
	}
}
using MCMF::adde;
using MCMF::init;
using MCMF::sol;

int n,a[N];

int s,t;

int main(){
//	freopen(".in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	init(4*n+3,4*n+1,4*n+2);
	adde(4*n+1,4*n+3,4,0);
	for(int i=1;i<=n;i++){
		adde(4*n+3,i+2*n,inf,0);
		adde(i+0*n,i+2*n,inf,0);
		adde(i+1*n,i+2*n,inf,0);
		adde(i+2*n,i+3*n,1,-1);
		adde(i+3*n,4*n+2,inf,0);
		for(int j=i+1;j<=n;j++)
			if(a[i]-a[j]==1){
				adde(i+3*n,j+1*n,inf,0);
				break;
			}
		for(int j=i+1;j<=n;j++)
			if(a[j]-a[i]==1){
				adde(i+3*n,j+1*n,inf,0);
				break;
			}
		for(int j=i+1;j<=n;j++)
			if(a[i]%7==a[j]%7){
				adde(i+3*n,j+0*n,inf,0);
				adde(i+0*n,j+0*n,inf,0);
				break;
			}
		for(int j=i+1;j<=n;j++)
			if(a[i]==a[j]){
				adde(i+1*n,j+1*n,inf,0);
				break;
			}
	}
	printf("%d\n",-sol().sec);
}