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
struct FastMod {
	unsigned long long b, m;
	FastMod() {}
	FastMod(unsigned long long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}
	unsigned long long operator()(unsigned long long a) {
		unsigned long long q = (unsigned long long)((__uint128_t(m) * a) >> 64);
		unsigned long long r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
}M;
int P;
int ad(int k1,int k2){return k1+k2>=P?k1+k2-P:k1+k2;}
int su(int k1,int k2){return k1-k2<0?k1-k2+P:k1-k2;}
int mu(int k1,int k2){return M(1ULL*k1*k2);}
void uad(int&k1,int k2){(k1+=k2)>=P&&(k1-=P);}
void usu(int&k1,int k2){(k1-=k2)<0&&(k1+=P);}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=5005;
int n,f[N],g[N],fac[N],ifac[N];
int C(int n,int m){
	if(m<0||n<m)return 0;
	return mu(fac[n],ifac[m],ifac[n-m]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(P);
	M=FastMod(P);
	fac[0]=1;
	rep(i,1,N-1)fac[i]=mu(fac[i-1],i);
	ifac[N-1]=po(fac[N-1],P-2);
	per(i,N-1,1)ifac[i-1]=mu(ifac[i],i);
	
	rep(i,1,n){
		f[i]=mu(i,i-1);
		rep(j,1,i-1){
			uad(f[i],mu(f[j],i,C(i-1,j)));
		}
	}
	rep(i,1,n)f[i]=mu(f[i],n-1);
	g[0]=1;
	rep(i,1,n){
		rep(j,1,i){
			uad(g[i],mu(g[i-j],f[j],C(i-1,j-1)));
		}
	}
	printf("%d\n",g[n]);
	return 0;
}