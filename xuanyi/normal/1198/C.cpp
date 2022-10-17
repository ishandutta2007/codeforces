//by xay5421 2449670833@qq.com
#include<cstdio>
#define int long long
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;typedef unsigned long long ull;
template<typename T>inline void rd(T&x){int f=0,c;while(c=getchar(),c<48||57<c)f^=!(c^45);x=(c&15);while(c=getchar(),47<c&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=500005;
int T,n,m,len,vis[N],ans[N];
struct ed{ed*nxt;int to,id;}pool[N<<1],*p=pool,*lnk[N]; 
void ae(int u,int v,int id){*++p=(ed){lnk[u],v,id},lnk[u]=p;}
void push(int u){
	int v=-1,id=-1;
	for(ed*i=lnk[u];i;i=i->nxt)if(vis[i->to]){
		v=i->to,id=i->id;break;
	}
	if(v==-1)vis[u]=1;else{
		vis[v]=0;
		ans[++len]=id;
	}
}
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,m){
			int u,v;rd(u),rd(v);
			ae(u,v,i),ae(v,u,i);
		}
		rep(i,1,n*3){
			push(i);
		}
		if(len>=n){
			puts("Matching");
			rep(i,1,n)pt(ans[i],i==n?'\n':' '); 
		}else{
			puts("IndSet");
			int cnt=0;
			for(int i=1;i<=n*3;++i)if(vis[i]){
				pt(i,++cnt==n?'\n':' ');
				if(cnt==n)break;
			}
		}
		rep(i,1,n*3)lnk[i]=0,vis[i]=0;p=pool,len=0;
	}
	return 0;
}