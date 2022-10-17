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
const int N=200005;
int T,n,p[N],l[N],r[N],dp[N];
LL rr[N];
vector<int>e[N];
void dfs1(int k1,int k2){
	dp[k1]=0,rr[k1]=0;
	each(x,e[k1])if(x!=k2){
		dfs1(x,k1);
		dp[k1]+=dp[x];
		rr[k1]+=rr[x];
	}
	if(l[k1]<=min(rr[k1],(LL)r[k1])){
		rr[k1]=min(rr[k1],(LL)r[k1]);
	}else{
		++dp[k1];
		rr[k1]=r[k1];
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)e[i].clear();
		rep(i,2,n)rd(p[i]),e[p[i]].pb(i);
		rep(i,1,n)rd(l[i]),rd(r[i]);
		dfs1(1,0);
		printf("%d\n",dp[1]);
	}
	return 0;
}