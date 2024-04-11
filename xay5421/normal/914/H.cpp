// author: xay5421
// created: Wed Nov  3 20:38:25 2021
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
const int N=205;
int n,d,f[N][N],g[N][N],C[N][N];
void get_sum(int i){
	rep(j,0,n){
		g[i][j]=ad(j==0?0:g[i][j-1],f[i][j]);
	}
}
int main(){
	scanf("%d%d%d",&n,&d,&P);
	if(n==1)puts("1"),exit(0);
	if(d==1){
		if(n==2)puts("4"),exit(0);
		puts("0"),exit(0);
	}
	C[0][0]=1;
	rep(i,1,N-1){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=ad(C[i-1][j-1],C[i-1][j]);
	}
	f[1][0]=1,get_sum(1);
	rep(i,2,n){
		for(int j=1;j<i&&j<=d;++j){
			rep(k,1,i-1){
				uad(f[i][j],mu(f[i-k][j-1],g[k][d-1],C[i-2][k-1]));
			}
		}
		get_sum(i);
	}
	int ans=0;
	rep(i,1,n){
		rep(x,0,d)rep(y,0,d)if(x+y<=d){
			uad(ans,mu(f[i][x],f[n-i+1][y]));
		}
	}
	rep(i,1,n){
		rep(x,0,d-1)rep(y,0,d-1){
			usu(ans,mu(f[i][x],f[n-i][y]));
		}
	}
	printf("%d\n",mu(ans,n,n-1,2));
	return 0;
}