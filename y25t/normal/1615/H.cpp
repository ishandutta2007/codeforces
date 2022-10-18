#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 10005
#define M 10005

namespace MF{
	int n,s,t;
	
	int hd[M],_hd;
	struct edge{
		int v,f,nxt;
	}e[M];
	inline void addedge(int u,int v,int f){
		e[++_hd]=(edge){v,f,hd[u]};
		hd[u]=_hd;
		e[++_hd]=(edge){u,0,hd[v]};
		hd[v]=_hd;
	}
	
	inline void init(int n_,int s_,int t_){
		for(int i=1;i<=n;i++)
			hd[i]=0;
		_hd=1;
		n=n_,s=s_,t=t_;
	}
	
	std::queue<int> q;
	int cur[M],dis[M];
	inline bool bfs(){
		for(int i=1;i<=n;i++)
			cur[i]=hd[i];
		for(int i=1;i<=n;i++)
			dis[i]=inf;
		dis[s]=0;
		q.push(s);
		while(q.size()){
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
	inline int dfs(int u,int lmt){
		if(u==t||!lmt)
			return lmt;
		int res=0;
		for(int i=cur[u];i;i=e[i].nxt){
			cur[u]=i;
			int v=e[i].v,f=e[i].f;
			if(dis[v]!=dis[u]+1)
				continue;
			f=dfs(v,std::min(lmt,f));
			e[i].f-=f;
			e[i^1].f+=f;
			lmt-=f;
			res+=f;
			if(!lmt)
				break;
		}
		return res;
	}
	inline void sol(){
		while(bfs())
			dfs(s,inf);
	}
}

int n,m,y[M];

std::vector<int> e[M];

inline int cal(int u,int k){
	return k>y[u]?k-y[u]:y[u]-k;
}
int tot,Y[M],f[M],p[M],id[M],q[M];
inline void sol(int L,int R,int l,int r){
	if(l>r)
		return;
	if(L==R){
		for(int i=l;i<=r;i++)
			f[p[i]]=Y[L];
		return;
	}
	int mid=(L+R)>>1;
	MF::init(r-l+3,r-l+2,r-l+3);
	for(int i=l;i<=r;i++)
		id[p[i]]=i-l+1;
	for(int i=l;i<=r;i++){
		int u=p[i],w=cal(u,Y[mid])-cal(u,Y[mid+1]);
		if(w>0)
			MF::addedge(MF::s,id[u],w);
		else
			MF::addedge(id[u],MF::t,-w);
		for(auto v:e[u])
			if(id[v])
				MF::addedge(id[u],id[v],inf);
	}
	MF::sol();
	int pm=l-1;
	for(int i=l;i<=r;i++)
		if(MF::dis[id[p[i]]]==inf)
			q[++pm]=p[i];
	int tmp=pm;
	for(int i=l;i<=r;i++)
		if(MF::dis[id[p[i]]]<inf)
			q[++tmp]=p[i];
	for(int i=l;i<=r;i++)
		p[i]=q[i];
	for(int i=l;i<=r;i++)
		id[p[i]]=0;
	sol(L,mid,l,pm);
	sol(mid+1,R,pm+1,r);
}

int ans;

signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&y[i]),Y[++tot]=y[i];
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		e[u].push_back(v);
	}
	std::sort(Y+1,Y+tot+1);
	tot=std::unique(Y+1,Y+tot+1)-Y-1;
	for(int i=1;i<=n;i++)
		p[i]=i;
	sol(1,tot,1,n);
	for(int i=1;i<=n;i++)
		printf("%lld ",f[i]);
	puts("");
}