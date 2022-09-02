#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,INF=0X3F3F3F3F;
int n,K,ans[N],dis[N],q[N],he,ta,f[N],sz[N],full,rt;
bool ban[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void getrt(int k1,int k2){
	sz[k1]=1,f[k1]=0;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&!ban[to[i]]){
		getrt(to[i],k1);
		sz[k1]+=sz[to[i]];
		if(f[k1]<sz[to[i]])f[k1]=sz[to[i]];
	}
	if(f[k1]<full-sz[k1])f[k1]=full-sz[k1];
	if(f[k1]<f[rt])rt=k1;
}
int w[N];
void dfs1(int k1,int k2,int k3){
	int fi=min(full,dis[k1]-k3-1);
	if(fi>=0){
		w[fi]=max(w[fi],dis[k1]);
	}
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&!ban[to[i]])dfs1(to[i],k1,k3+1);
}
void dfs2(int k1,int k2,int k3){
	ans[k1]=max(ans[k1],w[k3]);
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&!ban[to[i]])dfs2(to[i],k1,k3+1);
}
void sol(int k1){
	int nfull=full;
	rep(i,0,full)w[i]=~INF;
	dfs1(k1,0,0);
	per(i,full-1,0)w[i]=max(w[i],w[i+1]);
	dfs2(k1,0,0);
	ban[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(!ban[to[i]]){
		full=sz[to[i]]<sz[k1]?sz[to[i]]:nfull-sz[k1];
		rt=0;
		getrt(to[i],k1);
		sol(rt);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(dis,63,sizeof(dis));
	scanf("%d",&n);
	rep(i,1,n-1){
		int k1,k2;scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	scanf("%d",&K);
	rep(i,1,K){int x;scanf("%d",&x);dis[x]=0,q[++ta]=x;}
	while(he!=ta){
		int k1=q[++he];
		for(int i=lnk[k1];i;i=nxt[i])if(dis[k1]+1<dis[to[i]])dis[to[i]]=dis[k1]+1,q[++ta]=to[i];
	}
	f[0]=INF,rt=0,full=n;
	getrt(1,0);
	sol(rt);
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}