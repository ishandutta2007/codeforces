#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 200005
#define M 4000005

namespace MF{
	int n,m,s,t;
	
	int hd[N],_hd=1;
	struct edge{
		int v,f,nxt;
	}e[M<<1];
	inline void adde(int u,int v,int f){
		e[++_hd]=(edge){v,f,hd[u]};
		hd[u]=_hd;
		e[++_hd]=(edge){u,0,hd[v]};
		hd[v]=_hd;
	}
	
	int cur[N],dis[N];
	std::queue<int> q;
	inline bool bfs(){
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
	inline int dfs(int u,int lmt){
		if(u==t||!lmt)
			return lmt;
		int flw=0;
		for(int i=cur[u];i;i=e[i].nxt){
			cur[u]=i;
			int v=e[i].v,f=e[i].f;
			if(dis[v]!=dis[u]+1)
				continue;
			f=dfs(v,std::min(lmt,f));
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
	inline int dinic(){
		int res=0;
		while(bfs())
			res+=dfs(s,inf);
		return res;
	}
	
	inline void init(int n_,int s_,int t_){
		for(int i=1;i<=n+2;i++)
			hd[i]=0;
		_hd=1;
		n=n_,s=s_,t=t_;
	}
}

int T;

int n,a[N],b[N];

inline void adde(int u,int v){
	MF::adde(u,v+n+n,1);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[a[i]]=i;
		}
		MF::init(n*4,n*4+1,n*4+2);
		for(int i=1;i<=n;i++){
			adde(i,i+n);
			if(a[i]<=200){
				for(int j=1;j<=n;j++) if(j!=i&&a[j]%a[i]==0)
					adde(i,j),adde(i,j+n),adde(i+n,j+n);
			}
			else{
				for(int j=a[i]+a[i];j<=5e4;j+=a[i]) if(b[j])
					adde(i,b[j]),adde(i,b[j]+n),adde(i+n,b[j]+n);
			}
		}
		for(int i=1;i<=n+n;i++)
			MF::adde(MF::s,i,1);
		for(int i=1;i<=n+n;i++)
			MF::adde(i+n+n,MF::t,1);
		printf("%d\n",MF::dinic()-n);
		for(int i=1;i<=n;i++)
			b[a[i]]=0;
	}
}