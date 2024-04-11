// author: xay5421
// created: Fri Dec 25 11:28:30 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,M=1000005;
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
int n,a[N],p[M*2],fac[M*2],inv[M*2],ifac[M*2];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,M*2-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		for(int j=a[i]+1;j<M*2;j+=n)++p[j];
	}
	int lim=M*2-1;
	rep(i,1,M*2-1){
		p[i]+=p[i-1];
		if(p[i]>i){lim=i-1;break;}
	}
	int ans=0;
	for(int i=lim;i>=0&&i>lim-n;--i){
		uad(ans,C(i-p[i]+n-1,n-1));
	}
	printf("%d\n",ans);
	return 0;
}