//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
template<typename T>inline T gcd(T a,T b){
	if(!a)return b;if(!b)return a;
	while(a^=b^=a^=b%=a,a);return b; 
}
const int N=200005,K=20,P=1000000007;
int n,ans,a[N],dep[N],f[N][K],g[N][K];
int lnk[N],pp;struct ed{int nxt,to;}G[N<<1];
void ae(int u,int v){G[++pp]=(ed){lnk[u],v},lnk[u]=pp;}
void dfs(int u){
	dep[u]=dep[f[u][0]]+1;
	g[u][0]=a[u];
	rep(i,1,K-1)f[u][i]=f[f[u][i-1]][i-1],g[u][i]=gcd(g[u][i-1],g[f[u][i-1]][i-1]);
	for(int i=lnk[u];i;i=G[i].nxt)if(G[i].to!=f[u][0]){
		f[G[i].to][0]=u;
		dfs(G[i].to);
	}
}
signed main(){
	rd(n);rep(i,1,n)rd(a[i]);
	rep(i,2,n){
		int u,v;rd(u),rd(v);
		ae(u,v),ae(v,u);
	}
	dfs(1);
	rep(i,1,n){
		int u=i;
		for(int j=K-1;j>=0;--j)if(g[u][j]==0)u=f[u][j];
		int now=a[u];
		if(!now)continue;
		while(1){
			int v=u;
			for(int j=K-1;j>=0;--j)if(g[u][j]%now==0){
				u=f[u][j];
			}
			(ans+=1ll*now%P*(dep[v]-dep[u])%P)%=P;
			if(!u)break;
			now=gcd(now,a[u]);
		}
	}
	pt(ans,'\n');
	return 0;
}