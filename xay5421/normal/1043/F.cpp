// author: xay5421
// created: Wed Sep 15 09:04:40 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=998244853;
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
const int N=300005,K=20;
int n,m,a[N],lim,f[K][N],g[N],h[N];
int p[N];
bool ban[N];
void sieve(){
	ban[0]=ban[1]=1;
	for(int i=2;i<N;++i){
		if(!ban[i]){
			p[++p[0]]=i;
		}
		for(int j=1;j<=p[0]&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	sieve();
	rd(n),m=1;
	rep(i,1,n)rd(a[i]),++h[a[i]],g[a[i]]=a[i];
	lim=*max_element(a+1,a+1+n);
	for(int i=1;i<=p[0]&&p[i]<=lim;++i){
		per(j,lim/p[i],1){
			g[j]=__gcd(g[j],g[j*p[i]]);
			uad(h[j],h[j*p[i]]);
		}
	}
	rep(j,1,lim)f[1][j]=h[j];
	rep(i,2,K-1){
		rep(j,1,lim){
			f[i][j]=mu(f[i-1][j],h[j]);
		}
	}
	rep(_,1,K-1){
		int*f=::f[_];
		for(int i=1;i<=p[0]&&p[i]<=lim;++i){
			for(int j=1;j*p[i]<=lim;++j){
				usu(f[j],f[j*p[i]]);
			}
		}
	}
	rep(i,1,m){
		if(g[i]!=i){
			puts("-1");
		}else{
			int ans1=1;
			while(f[ans1][i]==0)++ans1;
			pt(ans1,'\n');
		}
	}
	return 0;
}