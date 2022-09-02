// author: xay5421
// created: Wed Apr  7 19:37:15 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=998244353;
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
const int N=8005;
int n,K,l,lim=1,fac[N],inv[N],ifac[N],f[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
void NTT(int*a,int g,int lim){
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	static int w[N]; w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=po(g,(P-1)/(i<<1));j<i;++j)w[j]=mu(w[j-1],wn);
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				int x=a[j+k],y=mu(a[i+j+k],w[k]);
				a[j+k]=ad(x,y),a[i+j+k]=su(x,y);
			}
		}
	}
	if(g!=3){
		const int I=po(lim,P-2);
		rep(i,0,lim-1)a[i]=mu(a[i],I);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d%d%d",&n,&K,&l);
	while(lim<=n*2)lim<<=1;
	int w=1,wn=po(3,(P-1)/lim);
	rep(i,0,lim-1){
		if(i)w=mu(w,wn);
		int x=mu(w*2,su(1,w)),tmp=po(su(1,x),P-2);
		int pw1=1,pw2=po(su(1,x),n);
		rep(j,0,n){
			if(j)pw1=mu(pw1,x),pw2=mu(pw2,tmp);
			if(j>=K)uad(f[i],mu(C(n,j),pw1,pw2));
		}
	}
	NTT(f,332748118,lim);
	int ans=0;
	rep(i,0,lim-1){
		uad(ans,mu(f[i],po(i+1,P-2)));
	}
	printf("%d\n",mu(ans,l));
	return 0;
}