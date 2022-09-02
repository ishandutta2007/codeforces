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
	FastMod(unsigned long long b) : b(b), m((unsigned long long)((__uint128_t(1) << 64) / b)) {}
	unsigned long long reduce(unsigned long long a) {
		unsigned long long q = (unsigned long long)((__uint128_t(m) * a) >> 64);
		unsigned long long r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
}M(998244353);
int P;
int ad(int k1,int k2){return k1+k2>=P?k1+k2-P:k1+k2;}
int su(int k1,int k2){return k1-k2<0?k1-k2+P:k1-k2;}
int mu(int k1,int k2){return M.reduce(1ULL*k1*k2);}
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
const int N=2005;
int n,C[N][N],f[N][N],sum[N][N],coef[N][N];
vector<int>e[N];
int w[N];
void dfs1(int k1,int k2){
	each(x,e[k1])if(x!=k2)dfs1(x,k1);
	if(k1==1){
		f[k1][0]=1;
		each(x,e[k1])if(x!=k2){
			static int sf[N];
			rep(t,0,n){
				sf[t]=f[k1][t];
				if(t)uad(sf[t],sf[t-1]);
			}
			rep(t,0,n){
				f[k1][t]=ad(mu(f[k1][t],sum[x][t]),mu(su(sf[t],f[k1][t]),f[x][t]));
			}
		}
		rep(i,1,n){
			rep(j,0,i-1){
				usu(f[k1][i],mu(f[k1][j],C[i][j]));
			}
		}
		rep(i,0,n-2)printf("%d ",f[k1][i]);
		exit(0);
	}
	rep(t,0,n){
		int cur=1;
		per(i,SZ(e[k1])-1,0)if(e[k1][i]!=k2){
			w[e[k1][i]]=cur;
			cur=mu(cur,sum[e[k1][i]][t]);
		}
		cur=1;
		rep(i,0,SZ(e[k1])-1)if(e[k1][i]!=k2){
			uad(coef[e[k1][i]][t+1],mu(cur,w[e[k1][i]]));
			cur=mu(cur,sum[e[k1][i]][t]);
		}
		uad(f[k1][t],cur);
	}
	each(x,e[k1])if(x!=k2){
		rep(t,0,n){
			if(t)uad(coef[x][t],coef[x][t-1]);
			uad(f[k1][t],mu(f[x][t],coef[x][t]));
		}
	}
	rep(i,0,n){
		sum[k1][i]=f[k1][i];
		if(i)uad(sum[k1][i],sum[k1][i-1]);
	}
}
int main(){
	rd(n),rd(P);
	M=FastMod(P);
	rep(i,0,N-1){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=ad(C[i-1][j-1],C[i-1][j]);
	}
	rep(i,2,n){
		int u,v;
		rd(u),rd(v);
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	
	return 0;
}