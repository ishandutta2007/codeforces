#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
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
const int N=500005;
int n,a[N],fa[N],pre[N],dep[N],fac[N];
bool vis[N];
int pp=1,lnk[N],nxt[N*2],to[N*2],ll[N*2],rr[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
struct ufs{
	int fa[N*2];
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	ufs(){
		iota(fa+1,fa+N*2,1);
	}
	int mer(int u,int v){
		if(fd(u)==fd(v))return 0;
		fa[fd(u)]=fd(v);
		return 1;
	}
}o;
void dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		pre[to[i]]=i^1;
		fa[to[i]]=k1;
		dfs1(to[i],k1);
	}
}
vector<int>get_path(int u,int v){
	vector<int>que,st;
	while(dep[u]>dep[v]){
		que.pb(pre[u]);
		u=fa[u];
	}
	while(dep[v]>dep[u]){
		st.pb(pre[v]^1);
		v=fa[v];
	}
	while(u!=v){
		que.pb(pre[u]);
		st.pb(pre[v]^1);
		u=fa[u];
		v=fa[v];
	}
	reverse(st.begin(),st.end());
	que.insert(que.end(),st.begin(),st.end());
	st.clear(),st.shrink_to_fit();
	return que;
}
int first[N],last[N],deg[N];
bool xay_set(int&x,int y){
	if(x!=0){
		if(x!=y){
			puts("0"),exit(0);
		}
		return 0;
	}
	x=y;
	return 1;
}
void deal(int u,int v){
	vector<int>path(get_path(u,v));
	if(ll[path.front()]||rr[path.back()^1]){
		puts("0"),exit(0);
	}
	deg[u]-=xay_set(first[u],path.front());
	deg[v]-=xay_set(last[v],path.back()^1);
	rep(i,1,SZ(path)-1){
		int k1=to[path[i-1]];
		if(last[k1]==(path[i-1]^1)||first[k1]==path[i]||!o.mer(path[i-1]^1,path[i])){
			puts("0"),exit(0);
		}
		deg[k1]-=xay_set(rr[path[i-1]^1],path[i]);
		xay_set(ll[path[i]],path[i-1]^1);
	}
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	fac[0]=1;
	rep(i,1,N-1)fac[i]=mu(fac[i-1],i);
	rep(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		ae(u,v),ae(v,u);
		++deg[u],++deg[v];
	}
	dfs1(1,0);
	rep(i,1,n){
		int x;
		scanf("%d",&x);
		if(!x)continue;
		if(vis[x]||i==x){
			puts("0"),exit(0);
		}
		vis[x]=1;
		deal(i,x);
	}
	int ans=1;
	rep(u,1,n){
		if(first[u]&&last[u]){
			if(o.fd(first[u])==o.fd(last[u])){
				if(deg[u]!=-1){
					puts("0"),exit(0);
				}
			}else{
				ans=mu(ans,fac[deg[u]]);
			}
		}else{
			ans=mu(ans,fac[deg[u]]);
		}
	}
	printf("%d\n",ans);
	return 0;
}