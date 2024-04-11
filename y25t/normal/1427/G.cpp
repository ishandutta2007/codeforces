#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 205
#define NN (N*N)
#define num(x,y) (((x)-1)*m+(y))

int n,m,a[NN];

int hd[NN],_hd=1;
struct edge{
	int v,f,nxt;
}e[NN<<2];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,0,hd[u]};
	hd[u]=_hd;
	e[++_hd]=(edge){u,0,hd[v]};
	hd[v]=_hd;
}

pii val[NN];
int tot;

bool S[NN],T[NN],vis[NN];
inline bool dfs(int u,int tp){
	if(T[u]&&tp==1)
		return 1;
	if(S[u]&&tp==-1)
		return 1;
	vis[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(vis[v])
			continue;
		if(tp==1&&e[i].f==1)
			continue;
		if(tp==-1&&e[i].f!=-1)
			continue;
		if(dfs(v,tp)){
			e[i].f++;
			e[i^1].f--;
			return 1;
		}
	}
	return 0;
}
int flw;
inline void sol(int u,int tp){
	while(dfs(u,tp)){
		flw+=tp;
		memset(vis,0,sizeof(vis));
	}
}

ll ans;

int main(){
	scanf("%d",&n);
	m=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[num(i,j)]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i>1&&a[num(i,j)]!=-1&&a[num(i-1,j)]!=-1)
				addedge(num(i,j),num(i-1,j));
			if(j>1&&a[num(i,j)]!=-1&&a[num(i,j-1)]!=-1)
				addedge(num(i,j),num(i,j-1));
			if(a[num(i,j)]>0){
				T[num(i,j)]=1;
				val[++tot]=mp(a[num(i,j)],num(i,j));
			}
		}
	std::sort(val+1,val+tot+1);
	for(int i=1;i<tot;i++){
		int u=val[i].sec;
		memset(vis,0,sizeof(vis));
		sol(u,-1);
		T[u]=0,S[u]=1;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=i;j++)
			if(!vis[val[j].sec])
				sol(val[j].sec,1);
		ans+=1ll*flw*(val[i+1].fir-val[i].fir);
	}
	printf("%lld\n",ans);
}