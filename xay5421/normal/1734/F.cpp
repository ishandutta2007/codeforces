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
int T;
map<pair<LL,LL>,LL>mp;
LL solve(LL n,LL m){
	if(mp.count(make_pair(n,m)))return mp[make_pair(n,m)];
	if(m==0)return 0;
	LL&ret=mp[make_pair(n,m)];
	{
		LL x=63-__builtin_clzll(n^(n+m-1));
		if(n>>x){
			return ret=__builtin_parityll(n>>x)?m-solve(n&((1LL<<x)-1),m):solve(n&((1LL<<x)-1),m);
		}
	}
	if((m&(m-1))!=0){
		per(i,60,0)if(m>>i&1){
			return ret=solve(n,1LL<<i)+(m-(1LL<<i)-solve(n+(1LL<<i),m-(1LL<<i)));
		}
		assert(0);
	}else{
		if((n&(m-1))==0){
			return ret=__builtin_parityll(n/m)?m:0;
		}
		LL t=m-(n&(m-1));
		ret=solve(n,t)+solve(n+t+t,m-t);
		return ret;
	}
}
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		 LL n,m;
		 rd(n),rd(m);
		 printf("%lld\n",solve(n,m));
	}
	return 0;
}