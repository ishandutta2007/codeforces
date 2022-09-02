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
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int brand(){return rng()&0X7FFFFFFF;}
int n;
char s[40];
int high;
map<LL,int>mp;
LL mask;
LL unite(LL x,LL y){
	LL ret=0;
	rep(i,0,high-1){
		if(y>>i&1){
			ret^=x;
		}
		x<<=1;
		if(x>>high&1){
			x^=mask;
		}
	}
	return ret;
}
LL sol(LL mask){
	::mask=mask;
	high=63-__builtin_clzll(mask);
	LL u=1;
	rep(i,1,1000000){
		u<<=1;
		if(u>>high&1){
			u^=mask;
		}
		if(u==1)return i;
		mp[u]=i;
	}
	const LL base=u;
	u=base;
	for(int i=2;;++i){
		u=unite(base,u);
		if(mp.count(u))return i*1000000LL-mp[u];
	}
}
int main(){
	scanf("%s",s);
	n=strlen(s);
	int beg=0;
	while(s[beg]&&s[beg]=='0')++beg;
	if(count(s,s+n,'1')==0){
		puts("-1");
	}else if(count(s,s+n,'1')==1){
		printf("%d %d\n",beg+1,beg+1+1);
	}else{
		LL x=0;
		per(i,n-1,beg)x=x<<1|(s[i]-'0');
		LL ret=sol(x);
		printf("%d %lld\n",beg+1,beg+1+ret);
	}
	return 0;
}