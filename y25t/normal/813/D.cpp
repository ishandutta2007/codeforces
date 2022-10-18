#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 50005
#define M 1000005

namespace MCMF{
	int n,s,t;
	
	
	int hd[N],_hd;
	struct edge{
		int v,f,w,nxt;
	}e[M<<1];
	inline void adde(int u,int v,int f,int w){
		e[++_hd]=(edge){v,f,w,hd[u]};
		hd[u]=_hd;
		e[++_hd]=(edge){u,0,-w,hd[v]};
		hd[v]=_hd;
	}
	
	std::queue<int> q;
int cur[N],dis[N];
bool vis[N];
inline bool spfa(){
	for(int i=1;i<=n;i++)
		cur[i]=hd[i];
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w,f=e[i].f;
			if(f&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[t]<inf;
}
int mf,mc;
inline int dfs(int u,int flw){
	if(u==t)
		return flw;
	int res=0;
	vis[u]=1;
	for(int i=cur[u];i;i=e[i].nxt){
		cur[u]=i;
		int v=e[i].v,w=e[i].w,f=e[i].f;
		if(!vis[v]&&f&&dis[v]==dis[u]+w){
			f=dfs(v,std::min(flw,f));
			e[i].f-=f;
			e[i^1].f+=f;
			flw-=f;
			res+=f;
			mc+=w*f;
			if(!flw)
				break;
		}
	}
	vis[u]=0;
	return res;
}
	
	inline void mcmf(){
	while(spfa())
		mf+=dfs(s,inf);
}
	
	inline void init(int n_,int s_,int t_){
		_hd=1;
		for(int i=1;i<=n;i++)
			hd[i]=0;
		mc=0,mf=0;
		n=n_,s=s_,t=t_;
	}
	inline pii sol(){
		mcmf();
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
	adde(4*n+1,4*n+3,2,0);
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