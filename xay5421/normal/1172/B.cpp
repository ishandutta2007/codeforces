#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

const int N=200005,P=998244353;

int n,ans=1,f[N],sz[N],fac[N];

struct ed{ed*nxt;int to;}pool[N<<1],*p=pool,*lnk[N];
void ae(int u,int v){*++p=(ed){lnk[u],v},lnk[u]=p;}

void dfs(int u,int fa){
	sz[u]=f[u]=1;int tot=0;
	for(ed*i=lnk[u];i;i=i->nxt)if(i->to!=fa){
		dfs(i->to,u);
		++tot;
		sz[u]+=sz[i->to];
		f[u]=1ll*f[u]*f[i->to]%P;
	}
	if(u==1)f[u]=1ll*f[u]*n%P*fac[tot]%P;
	else f[u]=1ll*f[u]*(tot+1)%P*fac[tot]%P;
}

signed main(){
	rd(n);fac[0]=1;rep(i,1,N-1)fac[i]=1ll*fac[i-1]*i%P;
	rep(i,2,n){
		int u,v;rd(u),rd(v);
		ae(u,v),ae(v,u);
	}
	dfs(1,1);
	pt(f[1],'\n');
	return 0;
}