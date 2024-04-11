#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=500005,K=20;
int n,ord[N],idx,sz[N],dep[N];
vector<pair<int,int> >vec[N];
vector<int>e[N];
bool used[N],ban[N];
int a[N],len,st[N],top;
int fa[N][K];
void dfs1(int k1,int k2){
	ord[k1]=++idx,dep[k1]=dep[k2]+1,sz[k1]=1,fa[k1][0]=k2;
	rep(i,1,K-1)fa[k1][i]=fa[fa[k1][i-1]][i-1];
	each(x,e[k1])if(x!=k2)dfs1(x,k1),sz[k1]+=sz[x];
}
int LCA(int k1,int k2){
	if(dep[k1]<dep[k2])swap(k1,k2);
	int dt=dep[k1]-dep[k2];
	per(i,K-1,0)if(dt>>i&1)k1=fa[k1][i];
	if(k1==k2)return k1;
	per(i,K-1,0)if(fa[k1][i]!=fa[k2][i])k1=fa[k1][i],k2=fa[k2][i];
	return fa[k1][0];
}
int dp0[N];
vector<pair<int,int> >es;
void clear(int u){
	// D("clear %d\n",u);
	dp0[u]=sz[u];
}
LL ret;
void link(int u,int v){
	// D("link %d %d\n",u,v);
	es.eb(u,v);
	if(ban[v]){
		dp0[u]-=sz[v];
	}else{
		dp0[u]=dp0[u]-sz[v]+dp0[v];
	}
}
void call_back(int u,int v){
	if(ban[v]){
		ret+=1LL*dp0[u]*dp0[v];
	}else{
		dp0[v]=dp0[u];
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,2,n){
		int u,v,w;
		rd(u),rd(v),rd(w);
		vec[w].eb(u,v);
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	LL ans=0;
	rep(w,1,n){
		len=0;
		each(x,vec[w]){
			if(!used[get<0>(x)])a[++len]=get<0>(x),used[get<0>(x)]=1;
			if(!used[get<1>(x)])a[++len]=get<1>(x),used[get<1>(x)]=1;
			if(dep[get<0>(x)]>dep[get<1>(x)])ban[get<0>(x)]=1;
			else ban[get<1>(x)]=1;
		}
		sort(a+1,a+len+1,[&](int lhs,int rhs){return ord[lhs]<ord[rhs];});
		len=unique(a+1,a+len+1)-a-1;
		ret=0;
		es.clear();
		st[top=1]=1,clear(1);
		rep(_,1,len)if(a[_]!=1){
			int cur=LCA(st[top],a[_]);
			while(top>1&&dep[cur]<=dep[st[top-1]]){
				link(st[top-1],st[top]);
				--top;
			}
			if(st[top]!=cur){
				clear(cur);
				link(cur,st[top]);
				st[top]=cur;
			}
			if(a[_]!=cur){
				clear(a[_]);
				st[++top]=a[_];
			}
		}
		while(top>1){
			link(st[top-1],st[top]);
			--top;
		}
		per(i,SZ(es)-1,0){
			call_back(get<0>(es[i]),get<1>(es[i]));
		}
		each(x,vec[w])used[get<0>(x)]=used[get<1>(x)]=0,ban[get<0>(x)]=ban[get<1>(x)]=0;
		ans+=ret;
		// D("w=%d ret=%lld\n\n",w,ret);
	}
	printf("%lld\n",ans);
	return 0;
}