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
const int N=2005;
int T,base,n,a[N],fa[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
bool check(){
	rep(i,1,n)fa[i]=i;
	rep(bit,0,30){
		int last=-1;
		rep(i,1,n)if(a[i]>>bit&1){
			if(last!=-1)fa[fd(i)]=fd(last);
			last=i;
		}
	}
	rep(i,1,n)if(fd(1)!=fd(i))return 0;
	return 1;
}
void out(int k){printf("%d\n",k);rep(i,1,n)printf("%d ",a[i]);puts("");}
void sol(){
	rd(n);
	base=0;
	rep(i,1,n){
		rd(a[i]);
		if(!a[i])++base,++a[i];
	}
	if(check()){
		out(base);
		return;
	}
	rep(i,1,n){
		++a[i];
		if(check()){
			out(base+1);
			return;
		}
		a[i]-=2;
		if(check()){
			out(base+1);
			return;
		}
		++a[i];
	}
	int pos=-1,t=-1;
	rep(i,1,n){
		int now=__builtin_ctz(a[i]);
		if(now>t){
			t=now,pos=i;
		}
	}
	--a[pos];
	rep(i,1,n){
		int now=__builtin_ctz(a[i]);
		if(now==t){
			++a[i];
			break;
		}
	}
	out(base+2);
}
int main(){
	rd(T);
	while(T--){
		sol();
		
	}
	return 0;
}