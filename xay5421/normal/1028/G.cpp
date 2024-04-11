// author: xay5421
// created: Fri Oct 29 09:35:10 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using LL=long long;
map<tuple<LL,LL,LL>,LL>mp;
LL dp(LL cnt,LL x0,LL base){ //  cnt  x>=x0
	x0=min(x0,(LL)10000);
	base=min(base,(LL)10000);
	if(cnt==1)return x0;
	if(mp.count({cnt,x0,base}))return mp[{cnt,x0,base}];
	LL tmp=dp(cnt-1,x0,base);
	rep(i,1,x0){
		tmp+=1;
		tmp+=dp(cnt-1,tmp+1+base,tmp+base);
	}
	return mp[{cnt,x0,base}]=tmp;
}
void deal(LL cnt,LL x0,LL base){
	D("deal %lld %lld %lld\n",cnt,x0,base);
	x0=min(x0,(LL)10000);
	if(cnt==1){
		printf("%lld ",x0);
		rep(i,1,x0)printf("%lld ",base+i);
		puts("");
		fflush(stdout);
		return;
	}
	printf("%lld ",x0);
	LL tmp=dp(cnt-1,x0,base);
	rep(i,1,x0){
		tmp+=1;
		printf("%lld ",base+tmp);
		tmp+=dp(cnt-1,tmp+1+base,tmp+base);
	}
	puts("");
	fflush(stdout);
	int _;
	scanf("%d",&_);
	if(_==0){
		deal(cnt-1,x0,base);
	}
	tmp=dp(cnt-1,x0,base);
	rep(i,1,x0){
		tmp+=1;
		if(_==i)deal(cnt-1,tmp+1+base,tmp+base);
		tmp+=dp(cnt-1,tmp+1+base,tmp+base);
	}
}
int main(){
	deal(5,1,0);
	return 0;
}