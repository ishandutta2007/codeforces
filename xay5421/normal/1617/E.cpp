#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int N=200005,INF=0X3F3F3F3F;
int n,a[N],b[N*35],b0,sz[N*35],dp[N*35],val[N*35],who[N*35],ans,ansu,ansv;
int pp,lnk[N*35],nxt[N*35],to[N*35];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int f(int x){
	if((x&(x-1))==0)return 0;
	return (1<<(__lg(x)+1))-x;
}
void dfs(int u){
	if(sz[u])dp[u]=0,who[u]=u;else dp[u]=~INF;
	for(int i=lnk[u];i;i=nxt[i]){
		dfs(to[i]);
		if(sz[u]>0&&sz[to[i]]>0){
			if(umax(ans,val[u]+val[to[i]]+1)){
				ansu=who[u],ansv=who[to[i]];
			}
		}
		if(umax(val[u],val[to[i]]+1)){
			who[u]=who[to[i]];
		}
		sz[u]+=sz[to[i]];
	}
}
int main(){
	scanf("%d",&n);
	set<int>used;
	rep(i,1,n){
		scanf("%d",&a[i]);
		int x=a[i];
		while(x>0){
			b[++b0]=x;
			x=f(x);
		}
	}
	b[++b0]=0;
	sort(b+1,b+1+b0);
	b0=unique(b+1,b+1+b0)-b-1;
	rep(i,1,n){
		sz[lower_bound(b+1,b+1+b0,a[i])-b]+=1;
	}
	rep(i,2,b0){
		int fa=lower_bound(b+1,b+1+b0,f(b[i]))-b;
		ae(fa,i);
	}
	dfs(1);
	auto get_id=[&](int x)->int{
		rep(i,1,n)if(a[i]==x)return i;
		return -1;
	};
	printf("%d %d %d\n",get_id(b[ansu]),get_id(b[ansv]),ans);
	return 0;
}