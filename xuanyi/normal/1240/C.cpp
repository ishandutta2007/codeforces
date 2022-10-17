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

const int N=500005;

int q,n,K,f[N][2];

int lnk[N],pp;
struct ed{int nxt,to,w;}G[N<<1];
void ae(int u,int v,int w){G[++pp]=(ed){lnk[u],v,w},lnk[u]=pp;}

bool cmp(const int&x,const int&y){return x>y;}

void dfs(int u,int fa){
	std::vector<int>t;
	for(int i=lnk[u];i;i=G[i].nxt)if(G[i].to!=fa){
		dfs(G[i].to,u);
		f[u][0]+=f[G[i].to][0];
		f[u][1]+=f[G[i].to][0];
		t.push_back(f[G[i].to][1]-f[G[i].to][0]+G[i].w); 
	}
	std::sort(t.begin(),t.end(),cmp);
	for(int i=0;i<(int)t.size()&&i<K;++i){
		if(t[i]<=0)break;
		if(i<K-1)f[u][1]+=t[i];
		f[u][0]+=t[i];
	}
	
}

signed main(){
	rd(q);
	while(q--){
		rd(n),rd(K);
		rep(i,2,n){
			int u,v,w;rd(u),rd(v),rd(w);
			ae(u,v,w),ae(v,u,w);
		}
		dfs(1,0);
		pt(f[1][0],'\n');
		pp=0;rep(i,1,n)lnk[i]=0,f[i][0]=f[i][1]=0;
	}
	return 0;
}