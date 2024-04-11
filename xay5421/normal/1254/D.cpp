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
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=150005;
int n,Q,sum,sz[N],inv[N],tin[N],tou[N],ind,son[N],fa[N],dep[N],dfn[N],bel[N];
vector<int>e[N];
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<=n;i+=i&-i)uad(t[i],k2);
	}
	void upd(int l,int r,int x){
		upd(l,x);
		upd(r+1,su(0,x));
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)uad(k2,t[i]);
		return k2;
	}
}t1,t2;
void dfs1(int k1,int k2){
	sz[k1]=1,fa[k1]=k2,dep[k1]=dep[k2]+1;
	for(auto&x:e[k1])if(x!=k2){
		dfs1(x,k1);
		sz[k1]+=sz[x];
		if(sz[x]>sz[son[k1]])son[k1]=x;
	}
}
void dfs2(int k1,int k2){
	tin[k1]=++ind,dfn[ind]=k1;
	if(son[k1]){
		bel[son[k1]]=bel[k1];
		dfs2(son[k1],k1);
	}
	for(auto&x:e[k1])if(x!=k2&&x!=son[k1]){
		bel[x]=x;
		dfs2(x,k1);
	}
	tou[k1]=ind;
}
int w[N];
void deal(int u,int d){
	uad(w[u],d);
	t1.upd(tin[u],tin[u],d);
	if(son[u]){
		t1.upd(tin[son[u]],tou[son[u]],mu(n-sz[son[u]],inv[n],d));
	}
	if(1<tin[u])t1.upd(1,tin[u]-1,mu(sz[u],inv[n],d));
	if(tou[u]<n)t1.upd(tou[u]+1,n,mu(sz[u],inv[n],d));
}
int ask(int u){
	int res=t1.qry(tin[u]);
	while(1){
		u=bel[u];
		if(u==1)break;
		uad(res,mu(n-sz[u],inv[n],w[fa[u]]));
		u=fa[u];
	}
	return res;
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	inv[0]=inv[1]=1;
	rep(i,2,N-1)inv[i]=mu(P-P/i,inv[P%i]);
	scanf("%d%d",&n,&Q);
	rep(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs1(1,0);
	bel[1]=1;
	dfs2(1,0);
	rep(_,1,Q){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int v,d;
			scanf("%d%d",&v,&d);
			uad(sum,d);
			deal(v,d);
		}else{
			int u;
			scanf("%d",&u);
			printf("%d\n",ask(u));
		}
	}
	return 0;
}