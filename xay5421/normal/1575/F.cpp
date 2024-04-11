// author: xay5421
// created: Tue Oct 12 18:36:39 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
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
const int N=100005;
int n,K,f[N],a[N],c[N],tot,fac[N],inv[N],ifac[N];
map<int,int>b;
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d%d",&n,&K);
	f[0]=0;
	f[1]=1;
	rep(x,1,n-1){
		int rhs=(n+1LL*n*K%P*f[x]-1LL*x*(K-1)%P*f[x-1]-(x+1LL*(n-x)*(K-1))%P*f[x])%P;
		if(rhs<P)rhs+=P;
		f[x+1]=mu(rhs,po(n-x,P-2));
	}
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]==-1)++tot;
		else ++b[a[i]];
	}
	int ans=0;
	for(auto x:b){
		++c[x.second];
	}
	c[0]+=K-SZ(b);
	const int invK=po(K,P-2);
	rep(i,0,n)if(c[i]){
		rep(j,0,tot){
			uad(ans,mu(c[i],f[i+j],C(tot,j),po(invK,j),po(su(1,invK),tot-j)));
		}
	}
	printf("%d\n",su(f[n],ans));
	return 0;
}