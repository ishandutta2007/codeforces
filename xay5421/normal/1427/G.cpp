#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define EB emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=205,INF=0X3F3F3F3F;
int n,a[N][N];
int res;
int zip(int x,int y){return (x-1)*n+y;}
bool IN(int x,int y){return 1<=x&&x<=n&&1<=y&&y<=n;}
struct MaxFlow{
	static const int N=::N*::N,M=N*8;
	int S,T;
	int dep[N],q[N];
	int pp,lnk[N],cur[N],nxt[M*2],to[M*2],we[M*2];
	bool vis[N];
	MaxFlow(){pp=1;}
	void init(int n){
		S=0,T=n+1;
	}
	void ae(int k1,int k2,int k3,int k4=0){
		D(">>> %d %d %d %d\n",k1,k2,k3,k4);
		to[++pp]=k2,nxt[pp]=lnk[k1],we[pp]=k3,lnk[k1]=pp;
		to[++pp]=k1,nxt[pp]=lnk[k2],we[pp]=k4,lnk[k2]=pp;
	}
	bool bfs(){
		rep(i,0,T)dep[i]=0;
		int he=0,ta=0;
		q[++ta]=S,dep[S]=1;
		while(he!=ta){
			int k1=q[++he];
			for(int i=lnk[k1];i;i=nxt[i])if(we[i]&&dep[to[i]]==0){
				dep[to[i]]=dep[k1]+1;
				q[++ta]=to[i];
			}
		}
		return !!dep[T];
	}
	int DFS(int k1,int k2){
		if(k1==T)return 1;
		if(vis[k1])return 0;
		vis[k1]=1;
		for(int i=lnk[k1];i;i=nxt[i])if(we[i^1]){
			if(to[i]==T&&k1!=k2)continue;
			if(DFS(to[i],k2)){
				--we[i^1],++we[i];
				return 1;
			}
		}
		return 0;
	}
	int dfs(int k1,int k2){
		if(k1==T)return k2;
		int k3=k2;
		for(int&i=cur[k1];i;i=nxt[i])if(dep[k1]+1==dep[to[i]]&&we[i]){
			int f=dfs(to[i],min(k3,we[i]));
			we[i]-=f,we[i^1]+=f,k3-=f;
			if(!k3)return k2;
		}
		return k2-k3;
	}
	void sol(){
		while(bfs()){
			rep(i,0,T)cur[i]=lnk[i];
			res+=dfs(S,INF);
		}
	}
	void del(int k1){
		for(int i=lnk[k1];i;i=nxt[i])if(to[i]==T){
			if(we[i^1]>0){
				assert(we[i^1]==1);
				rep(j,0,T)vis[j]=0;
				res-=we[i^1];
				assert(DFS(S,k1));
				we[i]+=we[i^1];
				we[i^1]=0;
				D("del %d %d\n",k1,T);
			}
			we[i]=0;
		}
	}
	void add(int k1){
		for(int i=lnk[S];i;i=nxt[i])if(to[i]==k1){
			assert(we[i]==0);
			D("add %d %d\n",S,k1);
			we[i]+=INF;
		}
	}
}M;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	vector<tuple<int,int,int> >g;
	rep(i,1,n)rep(j,1,n){
		scanf("%d",&a[i][j]);
		if(a[i][j]>0)g.EB(a[i][j],i,j);
	}
	LL ans=0;
	sort(g.begin(),g.end());
	M.init(n*n);
	rep(i,1,n)rep(j,1,n)if(a[i][j]>0)M.ae(M.S,zip(i,j),0),M.ae(zip(i,j),M.T,INF);
	rep(i,1,n)rep(j,1,n)if(a[i][j]!=-1){
		if(j<n&&a[i][j+1]!=-1){
			if(a[i][j]>0&&a[i][j+1]>0){
				ans+=abs(a[i][j]-a[i][j+1]);
			}else M.ae(zip(i,j),zip(i,j+1),1,1);
		}
		if(i<n&&a[i+1][j]!=-1){
			if(a[i][j]>0&&a[i+1][j]>0){
				ans+=abs(a[i+1][j]-a[i][j]);
			}else M.ae(zip(i,j),zip(i+1,j),1,1);
		}
	}
	M.sol();
	rep(_,0,SZ(g)-2){
		int w,x,y;
		tie(w,x,y)=g[_];
		M.del(zip(x,y));
		M.add(zip(x,y));
		M.sol();
		D("res=%d\n",res);
		ans+=1LL*res*(get<0>(g[_+1])-get<0>(g[_]));
	}
	printf("%lld\n",ans);
	return 0;
}