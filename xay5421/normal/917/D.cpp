// author: xay5421
// created: Mon Sep  6 09:02:19 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
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
const int N=8005; // no MLE
int n,dp[N],sz[N],fac[N],inv[N],ifac[N];
vector<int>e[N];
vector<array<int,2> >dfs(int k1,int k2){
	sz[k1]=1;
	vector<array<int,2> >f={{1,1}};
	for(auto x:e[k1])if(x!=k2){
		vector<array<int,2> >h(dfs(x,k1));
		vector<array<int,2> >g(sz[k1]+sz[x]);
		rep(a,0,sz[k1]-1)rep(b,0,sz[x]-1){
			// link
			uad(g[a+b+1][0],mu(f[a][0],h[b][0]));
			uad(g[a+b+1][1],mu(f[a][0],h[b][1]));
			uad(g[a+b+1][1],mu(f[a][1],h[b][0]));
			// not link
			rep(c,0,1)uad(g[a+b][c],mu(f[a][c],h[b][1]));
		}
		sz[k1]+=sz[x];
		f=g;
	}
	return f;
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d",&n);
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		e[k1].push_back(k2),e[k2].push_back(k1);
	}
	const int invn=po(n,P-2);
	auto f=dfs(1,0);
	rep(i,0,n-1){
		dp[i]=mu(f[i][1],po(n,n-i-1),invn);
	}
	per(i,n-1,0){
		per(j,n-1,i+1){
			usu(dp[i],mu(dp[j],C(j,i)));
		}
	}
	rep(i,0,n-1)printf("%d ",dp[i]);
	return 0;
}