#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define SZ(x) ((int)(x).size())
using namespace std;
const int N=400005,LG=20;
int n,K,r,dis[N],dep[N],fa[N][LG];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){D("ae %d %d\n",k1,k2),to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
struct ufs{
	int fa[N];ufs(){rep(i,1,N-1)fa[i]=i;}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
}o;
void dfs(int k1,int k2){
	D("dfs %d %d\n",k1,k2);
	dep[k1]=dep[k2]+1,fa[k1][0]=k2;rep(i,1,LG-1)fa[k1][i]=fa[fa[k1][i-1]][i-1];
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2)dfs(to[i],k1);
}
int LCA(int k1,int k2){
	if(dep[k1]<dep[k2])swap(k1,k2);
	int dt=dep[k1]-dep[k2];
	per(i,LG-1,0)if(dt>>i&1)k1=fa[k1][i];
	if(k1==k2)return k1;
	per(i,LG-1,0)if(fa[k1][i]!=fa[k2][i])k1=fa[k1][i],k2=fa[k2][i];
	return fa[k1][0];
}
int findk(int k1,int k2){
	per(i,LG-1,0)if(k2>>i&1)k1=fa[k1][i];
	return k1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&K,&r);
	rep(i,1,n-1){
		int k1,k2;scanf("%d%d",&k1,&k2);
		ae(k1,i+n),ae(i+n,k1);
		ae(i+n,k2),ae(k2,i+n);
	}
	memset(dis,63,sizeof(dis));
	queue<int>q;
	rep(i,1,r){
		int x;scanf("%d",&x),q.push(x),dis[x]=0;
	}
	while(SZ(q)){
		int k1=q.front();q.pop();
		for(int i=lnk[k1];i;i=nxt[i])if(dis[k1]+1<=K){
			o.fa[o.fd(k1)]=o.fd(to[i]);
			if(dis[k1]+1<dis[to[i]])dis[to[i]]=dis[k1]+1,q.push(to[i]);
		}
	}
	dfs(1,0);
	int T;scanf("%d",&T);
	rep(_,1,T){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		int k3=LCA(k1,k2);
		int dist=dep[k1]+dep[k2]-dep[k3]*2;
		if(dist<=K*2){
			puts("YES");
		}else{
			int t1=dep[k1]-dep[k3]>=K?findk(k1,K):findk(k2,dist-K);
			int t2=dep[k2]-dep[k3]>=K?findk(k2,K):findk(k1,dist-K);
			puts(o.fd(t1)==o.fd(t2)?"YES":"NO");
		}
	}
	return 0;
}