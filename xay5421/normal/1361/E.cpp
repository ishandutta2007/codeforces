#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
const int N=100005,M=200005,INF=0X3F3F3F3F;
int T,n,m,err,dep[N],vis[N],sz[N],f[N];PII up[N];
int pp,lnk[N],nxt[M],to[M];
int brand(){return(rand()<<16)+(rand()<<1)+(rand()&1);}
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void chk(int k1){
	vis[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])
		if(!vis[to[i]])dep[to[i]]=dep[k1]+1,chk(to[i]);
		else if(vis[to[i]]==2)err=1;
	vis[k1]=2;
}
void dfs(int k1){
	for(int i=lnk[k1];i;i=nxt[i]){
		if(dep[k1]>dep[to[i]])++sz[k1],--sz[to[i]],up[k1]=min(up[k1],MP(dep[to[i]],to[i]));
		else dfs(to[i]),sz[k1]+=sz[to[i]],up[k1]=min(up[k1],up[to[i]]);
	}
}
void dfs2(int k1){
	if(dep[k1]>1)f[k1]=(sz[k1]==1&&f[up[k1].se]);
	for(int i=lnk[k1];i;i=nxt[i])if(dep[k1]<dep[to[i]])dfs2(to[i]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,m){
			int k1,k2;scanf("%d%d",&k1,&k2);
			ae(k1,k2);
		}
		int TT=100;
		int rt=-1;
		while(TT--){
			int k1=brand()%n+1;
			rep(i,1,n)vis[i]=0;
			err=0,dep[k1]=1,chk(k1);
			if(!err){rt=k1;break;}
		}
		VI ans;
		if(rt==-1){
			puts("-1");goto qaq;
		}
		rep(i,1,n)vis[i]=0,sz[i]=0,up[i]=MP(INF,INF);
		dfs(rt);
		f[rt]=1;
		dfs2(rt);
		rep(i,1,n)if(f[i])ans.PB(i);
		if(SZ(ans)*5<n){
			puts("-1");
		}else{
			rep(i,0,SZ(ans)-1)printf("%d ",ans[i]);puts("");
		}
		qaq:;
		rep(i,1,n)lnk[i]=0;pp=0;
	}
	return 0;
}