// author: xay5421
// created: Thu Dec 10 07:47:19 2020
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
const int N=200005;
int n,q,ans,fac[N],inv[N],ifac[N];
char s[N];
int C(int k1,int k2){
	if(k1<0||k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	int x=0,y=count(s+1,s+1+n,'?');
	rep(i,1,n){
		if(i&1)x+=s[i]=='b';
		else x+=s[i]=='w';
	}
	x-=n/2;
	for(int i=x&1;i<=y;i+=2){
		uad(ans,mu(C(y,i),abs(x+i)));
	}
	printf("%d\n",mu(ans,po((P+1)>>1,y)));
	return 0;
}