// author: xay5421
// created: Sun Nov  7 18:24:11 2021
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
const int N=1000005;
int n,f[N*2],dw[N];
int F(int n){ // F(n,1)
	return ad(mu(n,su(n,2)),2);
}
int main(){
	scanf("%d",&n);
	dw[0]=1;
	rep(i,1,n){
		dw[i]=mu(dw[i-1],n-i+1);
	}
	int len=mu(dw[n],n);
	int ans=mu(len,len+1,(P+1)>>1);
	rep(i,1,n-1){
		f[i]=mu(dw[i-1],F(n-i+1));
	}
	f[n]=su(dw[n],n);
	rep(i,n+1,n*2-1){
		f[i]=su(dw[n],f[i-n]);
	}
	rep(i,1,n*2)usu(ans,mu(f[i],i));
	printf("%d\n",ans);
	return 0;
}