// author: xay5421
// created: Tue Dec  1 07:40:30 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=5005,P=1e9+7;
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
int n,K,a[N],f[N];
int main(){
	scanf("%d%d",&n,&K);
	rep(i,1,n)scanf("%d",&a[i]);
	f[0]=1;
	rep(i,1,n){
		per(j,N-1,0){
			f[j]=su(mu(f[j],a[i]),j?f[j-1]:0);
		}
	}
	int down=1,pw=1,in=po(n,P-2),ans=0;
	rep(i,0,N-1){
		if(i)down=mu(down,K-i+1),pw=mu(pw,in);
		ans=ad(ans,mu(down,pw,f[i]));
	}
	printf("%d\n",su(f[0],ans));
	return 0;
}