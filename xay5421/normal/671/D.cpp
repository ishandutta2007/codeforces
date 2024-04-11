#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=300005;
int n,m,cf[N],dep[N],x[N],y[N],z[N];
int rt[N],dis[N],tg[N],id[N],lc[N],rc[N];
vector<int>G[N];
LL ans;
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void pst(int k1,int k2){
	if(k1)z[id[k1]]+=k2,tg[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(lc[k1],tg[k1]);
		pst(rc[k1],tg[k1]);
		tg[k1]=0;
	}
}
int mer(int k1,int k2){
	if(!k1||!k2)return k1+k2;
	psd(k1),psd(k2);
	if(z[id[k1]]>z[id[k2]])swap(k1,k2);
	rc[k1]=mer(rc[k1],k2);
	if(dis[lc[k1]]<dis[rc[k1]])swap(lc[k1],rc[k1]);
	dis[k1]=dis[lc[k1]]+1;
	return k1;
}
void pop(int&k1){k1=mer(lc[k1],rc[k1]);}
int ind;
int newnode(int _id){
	int k1=++ind;
	id[k1]=_id;
	return k1;
}
void dfs(int k1,int k2){
	dep[k1]=dep[k2]+1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs(to[i],k1);
		cf[k1]+=cf[to[i]];
		rt[k1]=mer(rt[k1],rt[to[i]]);
	}
	if(!cf[k1]&&k1>1){
		puts("-1");
		exit(0);
	}
	for(auto j:G[k1]){
		rt[k1]=mer(rt[k1],newnode(j));
	}
	while(rt[k1]&&dep[y[id[rt[k1]]]]>=dep[k1])pop(rt[k1]);
	if(rt[k1]){
		D(">>> %d %d\n",k1,z[id[rt[k1]]]);
		ans+=z[id[rt[k1]]];
		pst(rt[k1],-z[id[rt[k1]]]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,2,n){
		int k1,k2;scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	rep(i,1,m){
		int k1,k2,k3;scanf("%d%d%d",&k1,&k2,&k3);
		++cf[k1],--cf[k2];
		x[i]=k1,y[i]=k2,z[i]=k3;
		G[k1].PB(i);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}