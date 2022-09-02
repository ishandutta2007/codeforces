// author: xay5421
// created: Mon Aug 30 09:05:53 2021
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
const int N=300005;
int n,a[N],sum[N];
int main(){
	scanf("%d",&n);
	rep(i,0,n-1)scanf("%d",&a[i]);
	sort(a,a+n);
	per(i,n-1,0)sum[i]=ad(sum[i+1],a[i]);
	const int invn=po(n,P-2);
	rep(k,1,n){
		if(k==n){puts("0");continue;}
		int ans=0;
		int len_=n%k;
		int tmp=n/k*k;
		int w=0;
		for(int i=tmp;i>=0;i-=k){
			int s1=su(sum[i],sum[i+len_]);
			uad(ans,mu(w,s1));
			if(i!=tmp){
				int s2=su(sum[i+len_],sum[i+k]);
				uad(ans,mu(w-1,s2));
			}
			++w;
		}
		printf("%d ",mu(ans,invn));
	}
	return 0;
}