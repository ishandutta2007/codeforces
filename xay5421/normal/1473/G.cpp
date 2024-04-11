// author: xay5421
// created: Sun Jan 17 14:55:30 2021
#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=998244353,N=200005;
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
void NTT(vector<int>&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=lim>>1;(j^=k)<k;k>>=1);
	}
	vector<int>w(lim>>1); w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=po(g,(P-1)/(i<<1));j<i;++j)w[j]=mu(w[j-1],wn);
		for(int j=0;j<lim;j+=i<<1)for(int k=0;k<i;++k){
			int x=a[j+k],y=mu(a[i+j+k],w[k]);
			a[j+k]=ad(x,y),a[i+j+k]=su(x,y);
		}
	}
	if(g!=3){
		const int I=po(lim,P-2);
		rep(i,0,lim-1)a[i]=mu(a[i],I);
	}
}
vector<int>operator*(vector<int>a,vector<int>b){
	int need=SZ(a)+SZ(b)-1,lim=1;
	while(lim<=need)lim<<=1;
	NTT(a,3,lim),NTT(b,3,lim);
	rep(i,0,lim-1)a[i]=mu(a[i],b[i]);
	NTT(a,332748118,lim);
	return a.resize(need),a;
}
int n,fac[N],inv[N],ifac[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d",&n);
	vector<int>ans{1};
	rep(i,1,n){
		int a,b;
		scanf("%d%d",&a,&b);
		int m=SZ(ans);
		vector<int>co;
		rep(j,b-m+1,m+a-1){
			co.push_back(C(a+b,j));
		}
		vector<int>res=ans*co;
		ans.resize(m+a-b);
		rep(i,0,SZ(ans)-1)ans[i]=res[m+i-1];
	}
	int res=0;
	rep(i,0,SZ(ans)-1)uad(res,ans[i]);
	printf("%d\n",res);
	return 0;
}