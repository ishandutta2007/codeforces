// author: xay5421
// created: Wed Nov  3 19:30:50 2021
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
namespace Module{
	using namespace std;
	#define ll long long
	#define ull unsigned ll
	const int N = 1<<20, P = 998244353;
	int Pow(ll x, int y=P-2){
		int ans=1;
		for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
		return ans;
	}
	int w[N];
	ull F[N];
	struct init{
		init(){
			for(int i=1; i<N; i<<=1){
				w[i]=1;
				int t=Pow(3, (P-1)/i/2);
				for(int j=1; j<i; ++j) w[i+j]=(ll)w[i+j-1]*t%P;
			}
		}
	} foo;
	int Get(int x){ int n=1; while(n<=x) n<<=1; return n;}
	void DFT(vector<int> &f, int n){
		if((int)f.size()!=n) f.resize(n);
		for(int i=0, j=0; i<n; ++i){
			F[i]=f[j];
			for(int k=n>>1; (j^=k)<k; k>>=1);
		}
		for(int i=1; i<n; i<<=1) for(int j=0; j<n; j+=i<<1){
			int *W=w+i;
			ull *F0=F+j, *F1=F+j+i;
			for(int k=j; k<j+i; ++k, ++W, ++F0, ++F1){
				ull t=(*F1)**W%P;
				(*F1)=*F0+P-t, (*F0)+=t;
			}
		}
		for(int i=0; i<n; ++i) f[i]=F[i]%P;
	}
	void IDFT(vector<int> &f, int n){
		f.resize(n), reverse(f.begin()+1, f.end()), DFT(f, n);
		int I=1;
		for(int i=1; i<n; i<<=1) I=(ll)I*(P+1)/2%P;
		for(int i=0; i<n; ++i) f[i]=(ll)f[i]*I%P;
	}
	vector<int> operator +(const vector<int> &f, const vector<int> &g){
		vector<int> ans=f;
		ans.resize(max(f.size(), g.size()));
		for(int i=0; i<(int)g.size(); ++i) (ans[i]+=g[i])%=P;
		return ans;
	}
	vector<int> operator *(const vector<int> &f, const vector<int> &g){
		vector<int> F, G;
		F=f, G=g;
		int p=Get(f.size()+g.size()-2);
		DFT(F, p), DFT(G, p);
		for(int i=0; i<p; ++i) F[i]=(ll)F[i]*G[i]%P;
		IDFT(F, p);
		return F.resize(f.size()+g.size()-1), F;
	}
	vector<int> Inv(const vector<int> &f, int n=-1){
		if(n==-1) n=f.size();
		if(n==1) return {Pow(f[0])};
		vector<int> ans=Inv(f, (n+1)/2), tmp(f.begin(), f.begin()+n);
		int p=Get(n*2-2);
		DFT(tmp, p), DFT(ans, p);
		for(int i=0; i<p; ++i) ans[i]=(2-(ll)ans[i]*tmp[i]%P+P)*ans[i]%P;
		IDFT(ans, p);
		return ans.resize(n), ans;
	}
	vector<int> Mod(const vector<int> &a, const vector<int> &b){
		if(b.size()>a.size()) return a;
		vector<int> A=a, B=b, iB;
		int n=a.size(), m=b.size();
		reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
		B.resize(n-m+1), iB=Inv(B, n-m+1);
		vector<int> d=A*iB;
		d.resize(n-m+1), reverse(d.begin(), d.end());
		vector<int> r=b*d;
		r.resize(m-1);
		for(int i=0; i<m-1; ++i) r[i]=(a[i]-r[i]+P)%P;
		return r;
	}
	vector<int> Prod(const vector<int> &a, const vector<int> &b){
		return a*b;
	}
	#undef ll
	#undef ull
}
using Module::Prod;
const int N=100005;
int n,A,B;
vector<int>sol(int l,int r){
	if(l==r)return vector<int>{l,1};
	int mid=(l+r)>>1;
	return Prod(sol(l,mid),sol(mid+1,r));
}
int C(int n,int m){
	if(n<0||m<0||n-m<0)return 0;
	int fz=1,fm=1;
	rep(i,1,m){
		fz=mu(fz,n-i+1);
		fm=mu(fm,i);
	}
	return mu(fz,po(fm,P-2));
}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	auto v=n==1?vector<int>{1}:sol(0,n-2);
	int ans;
	if(A+B-2<0||A+B-2>=SZ(v))ans=0;
	else ans=mu(v[A+B-2],C(A+B-2,A-1));
	printf("%d\n",ans);
	return 0;
}