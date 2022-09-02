// author: xay5421
// created: Wed Sep 29 09:51:43 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=3005,M=100005;
int n,m,f[N][N],sf[N],fac[M],inv[M],ifac[M];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int fun(int x,int y){ //   x  >=0  <=y
	return C(y+x,x);
}
int calc(int n,int m){
	memset(f,0,sizeof(f));
	rep(i,1,n){
		rep(j,1,m){
			f[i][j]=mu(fun(i-1,j-1),fun(i,m-j)); //  =j >=j
		}
	}
	int ans=0;
	rep(i,1,n-1){
		int sum=0;
		rep(j,1,m){
			uad(ans,mu(sum,f[i][j]));
			if(j<m)uad(sum,f[n-i][m-j+2]);
		}
	}
	return ad(ans,ans);
}
int calc_(int n,int m){
	int ans=0;
	memset(f,0,sizeof(f));
	rep(i,1,n){
		rep(j,1,m){
			f[i][j]=mu(fun(i-1,j-1),fun(i,m-j)); //  =j >=j
		}
	}
	rep(i,1,n-1){
		int sum=0;
		rep(j,1,m){
			uad(ans,mu(sum,f[i][j]));
			sum=f[n-i][m-j+1];
		}
	}
	return ad(ans,ans);
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<M;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d%d",&n,&m);
	printf("%d\n",ad(calc(n,m),calc(m,n),calc_(n,m)));
	return 0;
}