// author: xay5421
// created: Wed Jul  7 20:42:51 2021
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
int P;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=505,M=N*N/2;
int n,f[N*N],C[N][N],fac[N];
int main(){
	scanf("%d%d",&n,&P);
	fac[0]=1;
	rep(i,1,N-1)fac[i]=mu(fac[i-1],i);
	rep(i,0,N-1){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=ad(C[i-1][j-1],C[i-1][j]);
	}
	f[M]=1;
	int sz=0,ans=0;
	rep(i,1,n){
		int res=0;
		rep(j,1,sz){
			int k=min(j,i);
			uad(res,mu(su(C[i][2],C[i-k+1][2]),f[M+j]));
		}
		uad(ans,mu(res,C[n][i],fac[n-i]));
		sz+=i-1;
		per(j,sz,-sz+i){
			usu(f[M+j],f[M+j-i]);
		}
		rep(j,-sz+1,sz){
			uad(f[M+j],f[M+j-1]);
		}
		rep(j,-sz,sz-i){
			usu(f[M+j],f[M+j+i]);
		}
		per(j,sz-1,-sz){
			uad(f[M+j],f[M+j+1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}