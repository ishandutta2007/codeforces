// author: xay5421
// created: Thu Jun  3 22:01:33 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
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
namespace ntt{
	int base=1,root=-1,maxbase=-1;
	std::vector<int>roots={0,1},rev={0,1};
	void init(){
		int tmp=P-1;
		maxbase=0;
		while(!(tmp&1))tmp>>=1,maxbase++;
		root=2;
		while(1){
			if(po(root,1<<maxbase)==1&&po(root,1<<(maxbase-1))!=1)break;
			root++;
		}
	}
	void ensure_base(int nbase){
		if(maxbase==-1)init();
		if(nbase<=base)return;
		rev.resize(1<<nbase);
		for(int i=1;i<(1<<nbase);++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
		roots.resize(1<<nbase);
		while(base<nbase){
			int z=po(root,1<<(maxbase-base-1));
			for(int i=(1<<(base-1));i<(1<<base);++i)roots[i<<1]=roots[i],roots[i<<1|1]=mu(roots[i],z);
			base++;
		}
	}
	void dft(std::vector<int>&a){
		int n=a.size(),zeros=__builtin_ctz(n);
		ensure_base(zeros);
		int shift=base-zeros;
		for(int i=0;i<n;++i)if(i<(rev[i]>>shift))std::swap(a[i],a[rev[i]>>shift]);
		for(int mid=1;mid<n;mid<<=1)for(int i=0;i<n;i+=(mid<<1))for(int j=0;j<mid;++j){
			int x=a[i+j],y=mu(a[i+j+mid],roots[mid+j]);
			a[i+j]=ad(x,y);
			a[i+j+mid]=su(x,y);
		}
	}
	std::vector<int>operator*(std::vector<int>a,std::vector<int>b){
		if(SZ(a)<=50&&SZ(b)<=50){
			vector<int>c(SZ(a)+SZ(b)-1);
			rep(i,0,SZ(a)-1)rep(j,0,SZ(b)-1)uad(c[i+j],mu(a[i],b[j]));
			return c;
		}
		int need=a.size()+b.size()-1,nbase=0;
		while((1<<nbase)<need)nbase++;
		ensure_base(nbase);
		int size=1<<nbase;
		a.resize(size);
		b.resize(size);
		dft(a);
		dft(b);
		int inv=po(size,P-2);
		for(int i=0;i<size;++i)a[i]=mu(a[i],mu(b[i],inv));
		std::reverse(a.begin()+1,a.end());
		dft(a);
		a.resize(need);
		return a;
	}
}
using ntt::operator*;
const int N=100005;
int n,K,fac[N],inv[N],ifac[N];
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d%d",&n,&K);
	vector<int>f(K+1),_(K+1);
	rep(i,0,K)f[i]=mu(po(i,K),ifac[i]);
	rep(i,0,K)_[i]=i&1?su(0,ifac[i]):ifac[i];
	f=f*_;
	f.resize(K+1);
	int dw=1,ans=0;
	rep(j,0,K){
		if(j)dw=mu(dw,n-j+1);
		if(dw==0)break;
		uad(ans,mu(f[j],dw,po(n+1,n-j)));
	}
	printf("%d\n",ans);
	return 0;
}