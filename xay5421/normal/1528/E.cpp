// author: xay5421
// created: Mon May 24 23:54:04 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
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
const int N=1000005,I2=(P+1)>>1,I6=po(6,P-2);
int n,f[N],g[N],h[N],sum[N];
int C2(int x){return 1LL*x*(x-1)%P*I2%P;}
int C3(int x){return 1LL*x*(x-1)%P*(x-2)%P*I6%P;}
int main(){
	scanf("%d",&n);
	f[0]=1,g[0]=1,h[0]=1,sum[0]=1;
	rep(i,1,n){
		uad(f[i],g[i-1]);
		h[i]=f[i];
		int s=i==1?0:sum[i-2];
		uad(f[i],mu(g[i-1],s),ad(C2(g[i-1]),g[i-1]));
		g[i]=f[i];
		uad(f[i],mu(g[i-1],ad(C2(s),s)),mu(ad(C2(g[i-1]),g[i-1]),s),ad(C3(g[i-1]),C2(g[i-1]),C2(g[i-1]),g[i-1]));
		sum[i]=ad(sum[i-1],g[i]);
	}
	int ans=su(ad(f[n],f[n]),1);
	rep(x,1,n-1){
		uad(ans,mu(su(g[x],h[x]),su(h[n-x],1)));
	}
	printf("%d\n",ans);
	return 0;
}