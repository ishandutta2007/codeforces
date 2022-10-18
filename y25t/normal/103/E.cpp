#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define N 1005
#define M 2000005

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

std::queue<int> q;
int cur[N],dis[N];
inline bool bfs(){
	for(int i=1;i<=n+n+2;i++)
		cur[i]=hd[i];
	memset(dis,0x3f,sizeof(dis));
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
inline ll dfs(int u,int flw){
	if(u==t||!flw)
		return flw;
	ll res=0;
	for(int i=cur[u];i;i=e[i].nxt){
		cur[u]=i;
		int v=e[i].v,f=e[i].f;
		if(dis[v]==dis[u]+1){
			f=dfs(v,std::min(flw,f));
			e[i].f-=f;
			e[i^1].f+=f;
			res+=f;
			flw-=f;
			if(!flw)
				break;
		}
	}
	return res;
}
inline ll mf(){
	ll res=0;
	while(bfs())
		res+=dfs(s,inf);
	return res;
}

ll ans;

int main(){
	scanf("%d",&n);
	s=n+n+1,t=n+n+2;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int j;
			scanf("%d",&j);
			adde(i,n+j,inf);
		}
	}
	int mx=3e8;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		adde(s,i,mx-x);
		ans+=x;
	}
	for(int i=1;i<=n;i++)
		adde(n+i,t,mx);
	ans+=mf()-1ll*n*mx;
	printf("%lld\n",ans);
}