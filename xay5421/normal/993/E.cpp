#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
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
using LL=long long;
const int N=200005;
int n,x,a[N],s[N];
LL ans[N];
vector<int>gen(int l,int r){
	vector<int>f(n+1);
	rep(i,l,r)f[s[i]]+=1;
	return f;
}
int main(){
	scanf("%d%d",&n,&x);
	rep(i,1,n){
		scanf("%d",&a[i]);
		a[i]=a[i]<x;
	}
	rep(i,1,n){
		s[i]=s[i-1]+a[i];
	}
	vector<int>f1(gen(1,n)),f2(gen(0,n-1));
	const int B=4000;
	rep(i,0,n){
		if(f1[i]>=B){
			rep(j,0,i-1){
				ans[i-j]+=1LL*f1[i]*f2[j];
			}
			f1[i]=0;
		}
	}
	reverse(f2.begin(),f2.end());
	f1=f1*f2;
	rep(i,0,n){
		ans[i]+=f1[i+n];
	}
	ans[0]=0;
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(j<=n&&a[i]==a[j])++j;
		if(a[i]==0){
			ans[0]+=1LL*(j-i)*(j-i+1)/2;
		}
	}
	rep(i,0,n)printf("%lld ",ans[i]);
	puts("");
	return 0;
}