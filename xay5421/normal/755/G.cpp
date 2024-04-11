#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=(1<<15)+5;
int n,K,fac[N],inv[N],ifac[N],down[N];
void NTT(vector<int>&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	vector<int>w(lim>>1);
	w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=po(g,(P-1)/(i<<1));j<i;++j)w[j]=mu(w[j-1],wn);
		for(int j=0;j<lim;j+=i<<1){
			rep(k,0,i-1){
				int x=a[j+k],y=mu(a[i+j+k],w[k]);
				a[j+k]=ad(x,y),a[i+j+k]=su(x,y);
			}
		}
	}
	if(g!=3){
		const int I=po(lim,P-2);
		for(int i=0;i<lim;++i)a[i]=mu(a[i],I);
	}
}
vector<int>pmu(vector<int>a,vector<int>b){
	int need=SZ(a)+SZ(b)-1;
	int lim=1;
	while(lim<=need)lim<<=1;
	NTT(a,3,lim),NTT(b,3,lim);
	rep(i,0,lim-1)a[i]=mu(a[i],b[i]);
	NTT(a,332748118,lim);
	return a.resize(need),a;
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d%d",&n,&K);
	down[0]=1;
	rep(i,1,N-1)down[i]=mu(down[i-1],n-i+1);
	vector<int>f(K+1);
	rep(i,0,K){
		f[i]=mu(i&1?P-1:1,ifac[i],po(down[i],P-2));
	}
	vector<int>g(K+1);
	rep(i,0,K){
		g[i]=mu(po(2,i),ifac[i],ifac[i]);
	}
	vector<int>h(pmu(f,g));
	rep(i,1,K)printf("%d ",mu(fac[i],down[i],h[i]));
	return 0;
}