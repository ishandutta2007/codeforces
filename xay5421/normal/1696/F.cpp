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
const int N=105,INF=0X3F3F3F3F;
int T,n,g[N][N][N],f[N][N];
char s[N];
bool vis[N];
vector<pair<int,int> >es;
void dfs(int k1,int k2){
	vis[k1]=1;
	rep(i,1,n)if(i!=k2&&g[k1][i][k2]){
		if(!vis[i])es.eb(k1,i),dfs(i,k1);
	}
}
void sol(){
	rd(n);
	rep(k,1,n)rep(i,1,n)g[k][i][i]=1;
	rep(i,1,n-1){
		rep(j,i+1,n){
			scanf("%s",s+1);
			rep(k,1,n){
				g[k][i][j]=g[k][j][i]=s[k]-'0';
			}
		}
	}
	rep(u,2,n){
		fill(vis+1,vis+n+1,0);
		es.clear();
		es.eb(1,u);
		dfs(1,u);
		dfs(u,1);
		if(SZ(es)!=n-1)continue;
		rep(i,1,n)rep(j,1,n)f[i][j]=i==j?0:INF;
		each(x,es)f[get<0>(x)][get<1>(x)]=f[get<1>(x)][get<0>(x)]=1;
		rep(k,1,n)rep(i,1,n)rep(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		bool err=0;
		rep(i,1,n)rep(j,1,n)if(f[i][j]==INF)err=1;
		rep(k,1,n)rep(i,1,n)rep(j,1,n)if(g[k][i][j]!=(f[k][i]==f[k][j]))err=1;
		if(!err){
			puts("Yes");
			each(x,es)printf("%d %d\n",get<0>(x),get<1>(x));
			return;
		}
	}
	puts("No");
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		sol();
	}
	return 0;
}