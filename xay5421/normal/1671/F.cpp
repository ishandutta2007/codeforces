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
template<int P>
class mod_int{
	using Z=mod_int;
private:
	static int mo(int x){return x<0?x+P:x;}
public:
	int x;
	int val()const{return x;}
	mod_int():x(0){}
	template<class T>mod_int(const T&x_):x(x_>=0&&x_<P?static_cast<int>(x_):mo(static_cast<int>(x_%P))){}
	bool operator==(const Z&rhs)const{return x==rhs.x;}
	bool operator!=(const Z&rhs)const{return x!=rhs.x;}
	Z operator-()const{return Z(x?P-x:0);}
	Z pow(long long k)const{
		Z res=1,t=*this;
		while(k){
			if(k&1)res*=t;
			if(k>>=1)t*=t;
		}
		return res;
	}
	Z&operator++(){
		x<P-1?++x:x=0;
		return *this;
	}
	Z&operator--(){
		x?--x:x=P-1;
		return *this;
	}
	Z operator++(int){
		Z ret=x;
		x<P-1?++x:x=0;
		return ret;
	}
	Z operator--(int){
		Z ret=x;
		x?--x:x=P-1;
		return ret;
	}
	Z inv()const{
#ifdef xay5421
		assert(x!=0);
#endif
		return pow(P-2);
	}
	Z&operator+=(const Z&rhs){
		(x+=rhs.x)>=P&&(x-=P);
		return *this;
	}
	Z&operator-=(const Z&rhs){
		(x-=rhs.x)<0&&(x+=P);
		return *this;
	}
	Z&operator*=(const Z&rhs){
		x=1ULL*x*rhs.x%P;
		return *this;
	}
	Z&operator/=(const Z&rhs){
		return *this*=rhs.inv();
	}
#define setO(T,o) friend T operator o(const Z&lhs,const Z&rhs){Z res=lhs;return res o##=rhs;}
	setO(Z,+)setO(Z,-)setO(Z,*)setO(Z,/)
#undef setO
};
const int P=998244353;
using Z=mod_int<P>;
const int N=25;
int T;
Z f[N][N][12][12]; //  i  j k  t  p[i]>p[i+1]
Z g[12][12][N];
Z pre[N],suf[N],fac[N],ifac[N];
Z lag(Z *y,Z n){
	const int N=::N-12;
	Z cur=1;
	rep(i,1,N-1){
		pre[i]=cur;
		cur*=n-i;
	}
	cur=1;
	per(i,N-1,1){
		suf[i]=cur;
		cur*=n-i;
	}
	Z ans=0;
	rep(i,1,N-1){
		ans+=y[i]*pre[i]*suf[i]*ifac[i-1]*ifac[N-1-i]*((N-1-i)&1?P-1:1);
	}
	return ans;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=1;
	rep(i,1,N-1)fac[i]=fac[i-1]*i;
	ifac[N-1]=fac[N-1].inv();
	per(i,N-1,1)ifac[i-1]=ifac[i]*i;
	f[1][1][0][0]=1;
	rep(i,2,N-1){
		rep(j,1,i-1){
			rep(k,0,11)rep(t,0,11){
				rep(u,1,i){ //  u-0.5
					if(k+(i-u)<=11&&t+(j>=u)<=11){
						f[i][u][k+(i-u)][t+(j>=u)]+=f[i-1][j][k][t];
					}
				}
			}
		}
	}
	rep(i,1,N-1){
		rep(j,1,i){
			rep(k,0,11)rep(t,0,11){
				g[k][t][i]+=f[i][j][k][t];
			}
		}
	}
	rd(T);
	while(T--){
		int n,k,x;
		rd(n),rd(k),rd(x);
		if(n<=12)printf("%d\n",g[k][x][n].val());
		else printf("%d\n",lag(g[k][x]+12,n-12).val());
	}
	return 0;
}