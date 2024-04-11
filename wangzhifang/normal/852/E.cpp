#include <cstdio>
#include <cstring>
#define max_n 100000
#define max_m max_n-1<<1
#define mod 1000000007ll
using namespace std;
//#define DEBUG for(int i=0; i<4; ++i)printf("dp%d:%d\n",i,g.edge[i].dp)
struct node{
	int v,nxt,prv;
	long long dp,bef,aft;
	node(){}
	node(int _v,int _nxt,int _prv):v(_v),nxt(_nxt),prv(_prv),dp(0),bef(0),aft(0){}
};
struct tree{
	int head[max_n+1];
	int cnt;
	node edge[max_m];
	void build(){
		memset(head,-1,sizeof(head));
		cnt=-1;
	}
	void insert(int u,int v){
		push(u,v);
		push(v,u);
	}
	void push(int u,int v){
		edge[++cnt]=node(v,head[u],-1);
		head[u]=edge[head[u]].prv=cnt;
	}
};
tree g;
long long f[max_n+1];
bool vis[max_n+1];
int unvis[max_n+1];
#define valbef(x) (bool(~x)?g.edge[x].bef:1)
#define valaft(x) (bool(~x)?g.edge[x].aft:1)
//	#include <windows.h>
long long dfs(int u,int e){
//	system("pause");
//	printf("dfs(%d,%d)*********\n",u,e);
//	printf("\t%d %d %lld\n",int(vis[u]),unvis[u],f[u]);
	if(vis[u]&&(-1==unvis[u]||unvis[u]==e))
		return g.edge[e].dp;
//	puts("\t**");
	if(vis[u]){
		dfs(g.edge[unvis[u]^1].v,unvis[u]^1);
		int bef;
		for(int i=unvis[u]^1; ~i; i=g.edge[i].nxt)
			g.edge[i].bef=valbef(g.edge[i].prv)*g.edge[i].dp%mod;
		for(int i=unvis[u]^1; ~i; i=g.edge[i].prv)
			g.edge[i].aft=valaft(g.edge[i].nxt)*g.edge[i].dp%mod;
//		printf("%lld %lld, %lld %lld\n",g.edge[g.head[u]].bef,g.edge[g.head[u]].aft,g.edge[g.edge[g.head[u]].nxt].bef,g.edge[g.edge[g.head[u]].nxt].aft);
		for(int i=g.head[u]; ~i; i=g.edge[i].nxt)
			g.edge[i^1].dp=valbef(g.edge[i].prv)*valaft(g.edge[i].nxt)*2%mod;
		unvis[u]=-1,f[u]=bool(~g.head[u])?g.edge[g.head[u]].aft*2%mod:1;
//		printf("FINISH%d\n",u);
		return g.edge[e].dp;
	}
	vis[u]=1,unvis[u]=e;
	int lst=e^1;
//	printf("*%d %d %d %d %d\n",u,e,e^1,g.head[u],int(g.head[u]!=(e^1)));
	for(int i=g.head[u]; i!=(e^1); i=g.edge[i].nxt){
//		printf("dfs%d %d:\n",g.edge[i].v,i);
		dfs(g.edge[i].v,i);
//		printf("%lld*%lld mod %lld=",valbef(g.edge[i].prv),g.edge[i].dp,mod);
		g.edge[i].bef=valbef(g.edge[i].prv)*g.edge[i].dp%mod;
//		printf("%lld\n",g.edge[i].bef);
	}
//	printf("%d\n",lst);
//	printf("%d %d %lld %lld %lld\n",g.head[u],g.edge[g.head[u]].v,g.edge[g.head[u]].bef,g.edge[g.head[u]].dp,valbef(g.edge[g.head[u]].prv));
	for(; ~g.edge[lst].nxt; lst=g.edge[lst].nxt);
//	printf("ch%d %d %d\n",lst,e^1,int(lst!=(e^1)));
	for(int i=lst; i!=(e^1); i=g.edge[i].prv)
		g.edge[i].aft=valaft(g.edge[i].nxt)*dfs(g.edge[i].v,i)%mod;
//	printf("%d %d %lld %lld %d %lld %lld\n",u,e,valaft(g.edge[e^1].nxt),valbef(g.edge[e^1].prv),g.edge[e^1].prv,g.edge[g.head[u]].dp,g.edge[g.head[u]].bef);
//	printf("c%d %d %d %d\n",e,e^1,g.edge[e^1].nxt,g.edge[e^1].prv);
	if((-1==g.edge[e^1].nxt)&&(-1==g.edge[e^1].prv))
		return g.edge[e].dp=1;
//	printf("b%d %d\n",u,e);
//	printf("%d %d %lld\n",u,e,valaft(g.edge[e^1].nxt)*valbef(g.edge[e^1].prv)*2%mod);
	return g.edge[e].dp=valaft(g.edge[e^1].nxt)*valbef(g.edge[e^1].prv)*2%mod;
}
long long dfs(int u){
//	printf("@@@@@@@@@@%d %d %d %d %d %d\n",int(vis[1]),unvis[1],int(vis[2]),unvis[2],int(vis[3]),unvis[3]);
//	printf("QAQWQYQDFS(%d)\n",u);
	if(vis[u]&&unvis[u]==-1)
		return f[u];
//	printf("READY%d\n",u);
	if(vis[u]){
//		printf("vis%d\n",u);
//		DEBUG;
//		printf("aaa%lld %lld\n",g.edge[1].dp,g.edge[2].dp);
		dfs(g.edge[unvis[u]^1].v,unvis[u]^1);
		int bef;
		for(int i=unvis[u]^1; ~i; i=g.edge[i].nxt)
			g.edge[i].bef=valbef(g.edge[i].prv)*g.edge[i].dp%mod;
		for(int i=unvis[u]^1; ~i; i=g.edge[i].prv)
			g.edge[i].aft=valaft(g.edge[i].nxt)*g.edge[i].dp%mod;
//		printf("QYQ%d %lld\n",g.head[u],g.edge[g.head[u]].aft);
		for(int i=g.head[u]; ~i; i=g.edge[i].nxt)
			g.edge[i^1].dp=(g.edge[i].prv==g.edge[i].nxt)?1:(valbef(g.edge[i].prv)*valaft(g.edge[i].nxt)*2%mod);
		unvis[u]=-1;
//		printf("FINISH%d\n",u);
		return f[u]=g.edge[g.head[u]].aft*2%mod;
	}
//	printf("deal%d\n",u);
//	DEBUG;
//	puts("EDBUG"); 
	vis[u]=1,unvis[u]=-1;
	if(-1==g.head[u])
		return f[u]=1;
	int lst=-1;
	for(int i=g.head[u]; ~i; i=g.edge[i].nxt)
		lst=i,g.edge[i].bef=valbef(g.edge[i].prv)*dfs(g.edge[i].v,i)%mod;
	for(int i=lst; ~i; i=g.edge[i].prv)
		g.edge[i].aft=valaft(g.edge[i].nxt)*g.edge[i].dp%mod;
	for(int i=g.head[u]; ~i; i=g.edge[i].nxt)
		g.edge[i^1].dp=(g.edge[i].prv==g.edge[i].nxt)?1:(valbef(g.edge[i].prv)*valaft(g.edge[i].nxt)*2%mod);
//	printf("QAQ%d %lld\n",g.head[u],g.edge[g.head[u]].aft);
//	printf("FINISH%d\n",u);
	return f[u]=g.edge[g.head[u]].aft*2%mod;
}
int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	g.build();
	for(int i=0,u,v; ++i<n; g.insert(u,v))
		scanf("%d%d",&u,&v);
//	printf("1 1:%lld\n",dfs(1,1));
//	printf("3 2:%lld\n",dfs(3,2));
//	printf("2 0:%lld\n",dfs(2,0));
//	printf("2 3:%lld\n",dfs(2,3));
//	printf("2 0:%d\n1 1:%d\n3 2:%d\n2 3:%d\n",dfs(2,0),dfs(1,1),dfs(3,2),dfs(2,3));
//	dfs(3,2);
//	printf("********************************%lld\n",g.edge[2].dp);
//	printf("********************************%lld\n",dfs(2,0));
	for(int i=0; ++i<=n; ans+=dfs(i)); 
//		printf("f[%d-1] %lld\n",i,f[i-1]);
//	DEBUG;
	printf("%lld\n",ans%mod);
	return 0;
}