// author: xay5421
// created: Tue Jan  5 23:18:04 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int T,n,m,fa[N]; bool vis[N],pd[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
void dfs(int k1,int k2){
	vis[k1]=1;
	pd[k1]=!pd[k2];
	for(int i=lnk[k1];i;i=nxt[i])if(vis[to[i]])pd[k1]&=!pd[to[i]];
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2&&!vis[to[i]]){
		dfs(to[i],k1);
	}
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		pp=0;
		rep(i,1,n)fa[i]=i,pd[i]=0,vis[i]=0,lnk[i]=0;
		rep(i,1,m){
			int k1,k2;
			rd(k1),rd(k2);
			ae(k1,k2),ae(k2,k1);
			fa[fd(k1)]=fd(k2);
		}
		bool err=0;
		rep(i,1,n)if(fd(i)!=fd(1)){
			err=1;
		}
		if(err){
			puts("NO");
			continue;
		}
		puts("YES");
		dfs(1,0);
		vector<int>v;
		rep(i,1,n)if(pd[i])v.push_back(i);
		pt(SZ(v),'\n');
		for(const auto&x:v)pt(x,' ');
		puts("");
	}
	return 0;
}