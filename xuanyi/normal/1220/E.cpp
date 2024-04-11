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
const int N=200005;
int n,m,all,ans,vis[N],a[N],d[N],f[N],he,ta,q[N];bool inq[N];
struct ed{ed*nxt;int to;}pool[N<<1],*p=pool,*lnk[N];
void ae(int u,int v){*++p=(ed){lnk[u],v},lnk[u]=p;}
void dfs(int u,int sum){
	vis[u]=1;all+=a[u],sum+=a[u];
	if(sum>ans)ans=sum;
	for(ed*i=lnk[u];i;i=i->nxt)if(!vis[i->to])dfs(i->to,sum);
}
signed main(){
	rd(n),rd(m);
	rep(i,1,n)rd(a[i]);
	rep(i,1,m){
		int u,v;rd(u),rd(v);
		ae(u,v),ae(v,u);
		++d[u],++d[v];
	}
	int s;rd(s);dfs(s,0);
	rep(i,1,n)if(i!=s&&vis[i]&&d[i]==1)q[++ta]=i,f[i]=0;
	int sum=0;
	while(he!=ta){
		int u=q[++he];sum+=a[u];inq[u]=1;
		for(ed*i=lnk[u];i;i=i->nxt){
			if(i->to!=s&&vis[i->to]&&--d[i->to]==1)
				q[++ta]=i->to;
			if(vis[i->to])
				f[i->to]=max(f[i->to],f[u]+a[u]);
		}
	}
	int mx=0;
	rep(i,1,n)if(!inq[i]&&vis[i]){
		if(!inq[s]||i!=s)mx=max(mx,f[i]);
	}
	ans=max(ans,all-sum+mx);
	pt(ans,'\n');
	return 0;
}