#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define lf double
#define N 55
#define M 3005

int hd[N],_hd=1;
struct edge{
	int v,f,w,nxt;
}e[M<<1];
inline void addedge(int u,int v,int f,int w){
	e[++_hd]=(edge){v,f,w,hd[u]};
	hd[u]=_hd;
	e[++_hd]=(edge){u,0,-w,hd[v]};
	hd[v]=_hd;
}

std::queue<int> q;
int s,t,dis[N],flw[N],lst[N];
bool vis[N];
inline bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	memset(flw,0x3f,sizeof(flw));
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v,f=e[i].f,w=e[i].w;
			if(f&&dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				flw[v]=std::min(flw[u],f);
				lst[v]=i;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[t]<inf;
}
std::vector<pii> ver;
inline void ek(){
	int mc=0,mf=0;
	while(spfa()){
		int f=flw[t];
		mf+=f;
		mc+=f*dis[t];
		for(int u=t;u!=s;u=e[lst[u]^1].v){
			e[lst[u]].f-=f;
			e[lst[u]^1].f+=f;
		}
//		printf("&%d %d %d\n",f,mf,mc);
		ver.push_back(mp(mc,mf));
	}
}

int n,m,Q;

lf ans;

int main(){
	scanf("%d%d",&n,&m);
	s=1,t=n;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,1,w);
	}
	ek();
	scanf("%d",&Q);
	while(Q--){
		int x;
		scanf("%d",&x);
		ans=1e9;
		for(auto i:ver)
			ans=std::min(ans,(lf)(i.fir+x)/(lf)(i.sec));
		printf("%.6lf\n",ans);
//		std::cout<<ans<<'\n';
	}
}