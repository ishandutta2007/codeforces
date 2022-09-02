#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define SZ(x) ((int)(x).size())
using namespace std;
const int N=20005,INF=0X3F3F3F3F;
int n,m,ind,tim;
int sz[N],dep[N],son[N],dfn[N],bel[N],fa[N],pre[N],tin[N],eid[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int S,T;
struct maxFlow{
	const static int N=1000005;
	int pp,cur[N],lnk[N],nxt[N*2],to[N*2],we[N*2],dep[N];
	maxFlow(){pp=1;}
	void out(int k1){
		if(k1==S)D("S ");
		else if(k1==T)D("T ");
		else{
			if(k1<=m)D("(%d) ",k1);
			else if(k1<=n+m)D("<%d> ",k1-m);
			else D("%d ",k1);
		}
	}
	void ae(int k1,int k2,int k3){
		D("mf.ae ");
		out(k1);
		out(k2);
		D("%d\n",k3);
		to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
		to[++pp]=k1,we[pp]= 0,nxt[pp]=lnk[k2],lnk[k2]=pp;
	}
	bool bfs(){
		queue<int>q;
		q.push(S);
		rep(i,1,T)dep[i]=INF;
		dep[S]=0;
		while(SZ(q)){
			int k1=q.front();
			q.pop();
			for(int i=lnk[k1];i;i=nxt[i])if(we[i]&&dep[k1]+1<dep[to[i]]){
				dep[to[i]]=dep[k1]+1;
				q.push(to[i]);
			}
		}
		return dep[T]!=INF;
	}
	int dfs(int k1,int k2){
		if(k1==T)return k2;
		int k3=k2;
		for(int&i=cur[k1];i;i=nxt[i])if(we[i]&&dep[k1]+1==dep[to[i]]){
			int f=dfs(to[i],min(k3,we[i]));
			we[i]-=f,we[i^1]+=f,k3-=f;
			if(!k3){
				dep[k1]=INF;
				return k2;
			}
		}
		return k2-k3;
	}
	bool vis[N];
	void dfs(int k1){
		vis[k1]=1;
		for(int i=lnk[k1];i;i=nxt[i])if(!vis[to[i]]&&we[i])dfs(to[i]);
	}
	void sol(){
		int res=0;
		while(bfs()){
			memcpy(cur,lnk,sizeof(cur));
			while(int t=dfs(S,INF)){
				res+=t;
			}
		}
		printf("%d\n",res);
		dfs(S);
		{
			vector<int>v;
			rep(i,1,m){
				if(!vis[i])v.PB(i);
			}
			printf("%d ",SZ(v));
			for(auto x:v)printf("%d ",x);
			puts("");
		}
		{
			vector<int>v;
			rep(i,m+1,m+n){
				if(vis[i])v.PB(i);
			}
			printf("%d ",SZ(v));
			for(auto x:v)printf("%d ",eid[x-m]);
			puts("");
		}
		exit(0);
	}
}mf;
void dfs1(int k1,int k2){
	sz[k1]=1,fa[k1]=k2,dep[k1]=dep[k2]+1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		eid[to[i]]=(i+1)/2,dfs1(to[i],k1),sz[k1]+=sz[to[i]];
		if(sz[to[i]]>sz[son[k1]])son[k1]=to[i];
	}
}
void dfs2(int k1,int k2){
	tin[k1]=++tim,dfn[tim]=k1;
	pre[k1]=++ind;
	mf.ae(pre[k1],k1+m,INF);
	if(bel[k1]==bel[k2]){
		mf.ae(pre[k1],pre[k2],INF);
	}
	if(son[k1]){
		bel[son[k1]]=bel[k1];
		dfs2(son[k1],k1);
	}
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&to[i]!=son[k1]){
		bel[to[i]]=to[i];
		dfs2(to[i],k1);
	}
}
int t[N*4];
void bud(int k1,int k2,int k3){
	if(k2==k3){
		t[k1]=dfn[k2]+m;
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	t[k1]=++ind;
	mf.ae(t[k1],t[k1*2],INF);
	mf.ae(t[k1],t[k1*2+1],INF);
}
void jb(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		mf.ae(k6,t[k1],INF);
		return;
	}
	int mid=(k2+k3)>>1;
	jb(k1*2,k2,mid,k4,k5,k6),jb(k1*2+1,mid+1,k3,k4,k5,k6);
}
void adde(int k1,int k2,int k3){
	while(bel[k1]!=bel[k2]){
		if(dep[bel[k1]]<dep[bel[k2]])swap(k1,k2);
		mf.ae(k3,pre[k1],INF);
		k1=fa[bel[k1]];
	}
	if(dep[k1]<dep[k2])swap(k1,k2);
	if(k1!=k2)jb(1,1,n,tin[k2]+1,tin[k1],k3);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	ind=n+m;
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	dfs1(1,0);
	bel[1]=1;
	dfs2(1,0);
	bud(1,1,n);
	S=++ind,T=++ind;
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		adde(k1,k2,i);
	}
	rep(i,1,m){
		mf.ae(S,i,1);
	}
	rep(i,m+1,m+n){
		mf.ae(i,T,1);
	}
	mf.sol();
	return 0;
}