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
const int N=100005;
int T,n,dep[N],deg[N];
vector<int>e[N];
void dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1;
	each(x,e[k1])if(x!=k2)dfs1(x,k1);
}
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)e[i].clear(),deg[i]=0;
		rep(i,2,n){
			int u,v;
			rd(u),rd(v);
			e[u].pb(v),e[v].pb(u);
			++deg[u],++deg[v];
		}
		dfs1(1,0);
		rep(i,1,n)printf("%d%c",deg[i]*(dep[i]&1?1:-1),i==n?'\n':' ');
	}
	return 0;
}