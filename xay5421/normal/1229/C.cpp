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
const int N=100005;
std::vector<int>g[N],G[N];
int n,m,q,ans,in[N],ou[N];
signed main(){
	rd(n),rd(m);
	rep(i,1,m){
		int u,v;rd(u),rd(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(u,1,n)for(int v:g[u])
		if(u<v)++ou[u],G[u].push_back(v);
		else++in[u];
	rep(u,1,n)ans+=in[u]*ou[u];
	rd(q);
	pt(ans,'\n'); 
	while(q--){
		int u;rd(u);
		for(int v:G[u]){
			G[v].push_back(u);
			ans-=in[v]*ou[v],--in[v],++ou[v],ans+=in[v]*ou[v];
			ans-=in[u]*ou[u],--ou[u],++in[u],ans+=in[u]*ou[u];
		}
		G[u].clear();
		pt(ans,'\n');
	}
	return 0;
}