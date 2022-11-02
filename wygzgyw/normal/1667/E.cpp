// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
const int mod=998244353;
const int max_len=1<<19,N=max_len+5;
int n;
int _inv_[N];
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
template<typename _Tp>inline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef vector<int> poly;
void print(const poly &a){
	for(auto it:a) printf("%d ",it);
	printf("\n");
}
inline poly operator << (poly a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator <<= (poly &a,uint b){return a.insert(a.begin(),b,0),a;}
inline poly operator >> (const poly &a,uint b){return b>=a.size()?poly():poly{a.begin()+b,a.end()};}
inline poly operator >>= (poly &a,uint b){return a=b>=a.size()?poly():poly{a.begin()+b,a.end()};}
poly operator += (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i)add(a[i],b[i]);
	return a;
}
inline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
poly operator -= (poly &a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(uint i=0;i<b.size();++i)sub(a[i],b[i]);
	return a;
}
inline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
ull Omgs[N];
int r[N];
const ull Omg=ksm(3,(mod-1)/max_len);
int getlen(int len){
	int limit=1;while(limit<len)limit<<=1;
	for(int i=0;i<limit;++i)r[i]=(r[i>>1]>>1)|(i&1?limit>>1:0);
	return limit;
}
void setup(){
	_inv_[0]=_inv_[1]=1;for(int i=2;i<N;++i)_inv_[i]=1ULL*_inv_[mod%i]*(mod-mod/i)%mod;
	Omgs[max_len>>1]=1;
	for(int i=(max_len>>1)+1;i<max_len;++i)Omgs[i]=Omgs[i-1]*Omg%mod;
	for(int i=(max_len>>1)-1;i>0;--i)Omgs[i]=Omgs[i<<1];
}
void dft(ull *A,int limit){
	for(int i=0;i<limit;++i)if(i<r[i])std::swap(A[i],A[r[i]]);
	for(int len=1;len<limit;len<<=1){
		for(int i=0;i<limit;++i)A[i]%=mod;
		for(int i=0;i<limit;i+=len<<1){
			ull *p=A+i,*q=A+i+len,*w=Omgs+len;
			for(int _=0;_<len;++_,++p,++q,++w){ull tmp=*q**w%mod;*q=*p+mod-tmp,*p+=tmp;}
		}
	}
	for(int i=0;i<limit;++i)A[i]%=mod;
}
void idft(ull *A,int limit){
	std::reverse(A+1,A+limit),dft(A,limit);
	ull inv=mod-(mod-1)/limit;for(int i=0;i<limit;++i) A[i]=inv*A[i]%mod;
}
ull _f[N],_g[N],_tp[N];
poly operator * (const poly &a,const poly &b){
	uint len=a.size()+b.size()-1;
	if(a.size()<=64u||b.size()<=64u){
		memset(_tp,0,len<<3);uint r=0;
		for(uint i=0;i<a.size();++i){
			for(uint j=0;j<b.size();++j)_tp[i+j]+=1ULL*a[i]*b[j];
			if(++r==18){r=0;for(uint j=i-17;j<i+b.size();++j)_tp[j]%=mod;}
		}
		if(r)for(uint j=0;j<len;++j)_tp[j]%=mod;
		poly c(len);for(uint i=0;i<len;++i)c[i]=_tp[i];
		return c;
	}
	int limit=getlen(len);
	memset(_f,0,limit<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	memset(_g,0,limit<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
	dft(_f,limit),dft(_g,limit);
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
poly mul(const poly &a,const poly &b,uint len,bool need=true){
	if(a.size()<=64u||b.size()<=64u){
		memset(_tp,0,len<<3);uint r=0;
		for(uint i=0;i<a.size();++i){
			for(uint j=0;j<b.size()&&i+j<len;++j)_tp[i+j]+=1ULL*a[i]*b[j];
			if(++r==18){r=0;for(uint j=i-17;j<len&&j<i+b.size();++j)_tp[j]%=mod;}
		}
		if(r)for(uint j=0;j<len;++j)_tp[j]%=mod;
		poly c(len);for(uint i=0;i<len;++i)c[i]=_tp[i];
		return c;
	}
	int limit=getlen(len);
	memset(_f,0,limit<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	dft(_f,limit);
	if(need){
		memset(_g,0,limit<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
		dft(_g,limit);
	}
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
inline poly operator *= (poly &a,const poly &b){return a=a*b;}
template<typename _Tp>inline poly operator *= (poly &a,const _Tp &b){
	for(auto &&it:a)it=1ULL*it*b%mod;
	return a;
}
template<typename _Tp>inline poly operator * (poly a,const _Tp &b){return a*=b;}
template<typename _Tp>inline poly operator * (const _Tp &b,poly a){return a*=b;}
template<typename _Tp>inline poly operator /= (poly &a,const _Tp &b){
	ull inv=ksm(b);for(auto &&it:a)it=1ULL*it*inv%mod;
	return a;
}
int jc[N],ivjc[N],ans[N];
int main() {
	read(n); setup();
	int S=(n+1)/2;
	jc[0]=ivjc[0]=1;
	for (int i=1;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod;
	ivjc[n]=ksm(jc[n],mod-2);
	for (int i=n-1;i>=1;i--) ivjc[i]=(ll)ivjc[i+1]*(i+1)%mod;
	poly dp(n+5);
	poly F(n+5),G(n+5);
	for (int j=S-1;j<=n-2;j++) F[j]=jc[n-j-2];
	for (int i=0;i<=n;i++) G[i]=ivjc[i];
	F=F*G;
	dp[1]=jc[n-1];
	for (int i=2;i<=n;i++) dp[i]=(ll)F[n-i]*(i-1)%mod*jc[n-i]%mod;
	int suf=0;
	for (int i=n;i>=1;i--) {
		ans[i]=dp[i]; int iv=ksm(i,mod-2);
		add(ans[i],mod-(ll)suf*iv%mod);
		add(suf,ans[i]);
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/