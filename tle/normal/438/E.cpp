#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#pragma GCC optimize("-fno-math-errno")
#pragma GCC optimize("-funsafe-math-optimizations")
#pragma GCC optimize("-freciprocal-math")
#pragma GCC optimize("-fno-trapping-math")
#pragma GCC optimize("-ffinite-math-only")
#pragma GCC optimize("-fno-stack-protector")
#pragma GCC target("sse4","avx2")
#include <immintrin.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 2345678
const int MOD=998244353;
ll qp(ll a,ll b)
{
	ll ans=1; a%=MOD;
	while(b)
	{
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return ans;
}
int getK(int n)
{int s=1; while(s<n) s<<=1; return s;}
typedef unsigned us;
typedef unsigned long long ull;
us pool[SZ*4+10000] __attribute__ ((aligned(64))),*ptr=pool;
us *p0[SZ],*p1[SZ],*q0[SZ],*q1[SZ];
template<class T>
__attribute__((always_inline)) void bit_flip(T*p,int t)
{
	for(int i=0,j=0;i<t;++i)
	{
		if(i>j) swap(p[i],p[j]);
		for(int l=t>>1;(j^=l)<l;l>>=1);
	}
}
void prep(int n)
{
	static int t=1;
	for(;t<n;t<<=1)
	{
		int g=qp(3,(MOD-1)/(t*2));
		us*p,*q;
		p=p0[t]=ptr; ptr+=max(t,16); p[0]=1;
		for(int m=1;m<t;++m)
			p[m]=p[m-1]*(ull)g%us(MOD);
		bit_flip(p,t);
		q=q0[t]=ptr; ptr+=max(t,16);
		for(int i=0;i<t;++i)
			q[i]=(ull(p[i])<<32)/MOD;
		g=qp(g,MOD-2);
		p=p1[t]=ptr; ptr+=max(t,16); p[0]=1;
		for(int m=1;m<t;++m)
			p[m]=p[m-1]*(ull)g%us(MOD);
		bit_flip(p,t);
		q=q1[t]=ptr; ptr+=max(t,16);
		for(int i=0;i<t;++i)
			q[i]=(ull(p[i])<<32)/MOD;
	}
}
typedef unsigned long long ull;
__attribute__((always_inline)) us my_mul(us a,us b,us c)
{
	return b*(ull)a-((ull(a)*c)>>32)*ull(998244353);
}
__attribute__((always_inline)) __m128i my_mullo_epu32(const __m128i&a, const __m128i& b)
{
	#if defined ( __SSE4_2__ )
	return _mm_mullo_epi32(a,b);
	#else
	__m128i a13    = _mm_shuffle_epi32(a, 0xF5);          // (-,a3,-,a1)
	__m128i b13    = _mm_shuffle_epi32(b, 0xF5);          // (-,b3,-,b1)
	__m128i prod02 = _mm_mul_epu32(a, b);                 // (-,a2*b2,-,a0*b0)
	__m128i prod13 = _mm_mul_epu32(a13, b13);             // (-,a3*b3,-,a1*b1)
	__m128i prod   = _mm_unpacklo_epi64(
	_mm_unpacklo_epi32(prod02,prod13),
	_mm_unpackhi_epi32(prod02,prod13));   // (ab3,ab2,ab1,ab0)
	return prod;
	#endif
}
__attribute__((always_inline)) __m128i my_mulhi_epu32(const __m128i&a, const __m128i& b)
{
	__m128i a13    = _mm_shuffle_epi32(a, 0xF5);          // (-,a3,-,a1)
	__m128i b13    = _mm_shuffle_epi32(b, 0xF5);          // (-,b3,-,b1)
	__m128i prod02 = _mm_mul_epu32(a, b);                 // (a2*b2,-,a0*b0,-)
	__m128i prod13 = _mm_mul_epu32(a13, b13);             // (a3*b3,-,a1*b1,-)
	__m128i prod   = _mm_unpackhi_epi64(
	_mm_unpacklo_epi32(prod02,prod13),
	_mm_unpackhi_epi32(prod02,prod13));   // (ab3,ab2,ab1,ab0)
	return prod;
}
void ntt(us* x,int n,bool f=true)
{
	prep(n);
	int t=n;
	for(int m=1;m<n;m<<=1)
	{
		t>>=1;
		us* p=p0[m];
		us* q=q0[m];
		if(t==1||t==2)
		{
			us *xa=x,*xb=x+t;
			for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
				for(int j=0;j<t;++j)
				{
					us u=xa[j]-(xa[j]>=us(MOD+MOD))*us(MOD+MOD);
					us v=my_mul(xb[j],p[i],q[i]);
					xa[j]=u+v;
					xb[j]=u-v+us(MOD+MOD);
				}
		}
		else if(t==4)
		{
			us *xa=x,*xb=x+t;
			for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
			{
				const __m128i p4=_mm_set1_epi32(p[i]),
				q4=_mm_set1_epi32(q[i]),
				mm=_mm_set1_epi32(MOD+MOD),
				m0=_mm_set1_epi32(0),
				m1=_mm_set1_epi32(MOD);
				for(int j=0;j<t;j+=4)
				{
					__m128i u=_mm_loadu_si128((__m128i*)(xa+j));
					u=_mm_sub_epi32(u,
					_mm_and_si128(_mm_or_si128(_mm_cmpgt_epi32(u,mm),
					_mm_cmpgt_epi32(m0,u)),mm));
					__m128i v=_mm_loadu_si128((__m128i*)(xb+j));
					v=_mm_sub_epi32(my_mullo_epu32(v,p4),
					my_mullo_epu32(my_mulhi_epu32(v,q4),m1));
					_mm_storeu_si128((__m128i*)(xa+j),_mm_add_epi32(u,v));
					_mm_storeu_si128((__m128i*)(xb+j),_mm_add_epi32(_mm_sub_epi32(u,v),mm));
				}
			}
		}
		else
		{
			us *xa=x,*xb=x+t;
			for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
			{
				const __m128i p4=_mm_set1_epi32(p[i]),
				q4=_mm_set1_epi32(q[i]),
				mm=_mm_set1_epi32(MOD+MOD),
				m0=_mm_set1_epi32(0),
				m1=_mm_set1_epi32(MOD);
				//unfold 2x
				for(int j=0;j<t;j+=8)
				{
					__m128i u0=_mm_loadu_si128((__m128i*)(xa+j));
					__m128i u1=_mm_loadu_si128((__m128i*)(xa+j+4));
					__m128i v0=_mm_loadu_si128((__m128i*)(xb+j));
					__m128i v1=_mm_loadu_si128((__m128i*)(xb+j+4));
					u0=_mm_sub_epi32(u0,
					_mm_and_si128(_mm_or_si128(_mm_cmpgt_epi32(u0,mm),
					_mm_cmpgt_epi32(m0,u0)),mm));
					u1=_mm_sub_epi32(u1,
					_mm_and_si128(_mm_or_si128(_mm_cmpgt_epi32(u1,mm),
					_mm_cmpgt_epi32(m0,u1)),mm));
					v0=_mm_sub_epi32(my_mullo_epu32(v0,p4),
					my_mullo_epu32(my_mulhi_epu32(v0,q4),m1));
					v1=_mm_sub_epi32(my_mullo_epu32(v1,p4),
					my_mullo_epu32(my_mulhi_epu32(v1,q4),m1));
					_mm_storeu_si128((__m128i*)(xa+j),_mm_add_epi32(u0,v0));
					_mm_storeu_si128((__m128i*)(xa+j+4),_mm_add_epi32(u1,v1));
					_mm_storeu_si128((__m128i*)(xb+j),
					_mm_add_epi32(_mm_sub_epi32(u0,v0),mm));
					_mm_storeu_si128((__m128i*)(xb+j+4),
					_mm_add_epi32(_mm_sub_epi32(u1,v1),mm));
				}
			}
		}
	}
	for(int i=0;i<n;++i)
		x[i]-=(x[i]>=us(MOD+MOD))*us(MOD+MOD),
		x[i]-=(x[i]>=us(MOD))*us(MOD);
	if(f) bit_flip(x,n);
}
void intt(us* x,int n,bool f=true)
{
	prep(n); int t=1;
	if(f) bit_flip(x,n);
	for(int m=(n>>1);m;m>>=1)
	{
		us* p=p1[m];
		us* q=q1[m];
		if(t==1||t==2)
		{
			us *xa=x,*xb=x+t;
			for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
				for(int j=0;j<t;++j)
				{
					us u=xa[j],v=xb[j];
					xa[j]=u+v-(u+v>=us(MOD+MOD))*us(MOD+MOD);
					xb[j]=my_mul(u-v+us(MOD+MOD),p[i],q[i]);
				}
		}
		else if(t==4)
		{
			us *xa=x,*xb=x+t;
			for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
			{
				const __m128i p4=_mm_set1_epi32(p[i]),
				q4=_mm_set1_epi32(q[i]),
				mm=_mm_set1_epi32(MOD+MOD),
				m0=_mm_set1_epi32(0),
				m1=_mm_set1_epi32(MOD);
				for(int j=0;j<t;j+=4)
				{
					__m128i u=_mm_loadu_si128((__m128i*)(xa+j));
					__m128i v=_mm_loadu_si128((__m128i*)(xb+j));
					__m128i uv=_mm_add_epi32(u,v);
					_mm_storeu_si128((__m128i*)(xa+j),_mm_sub_epi32(uv,
					_mm_and_si128(_mm_or_si128(_mm_cmpgt_epi32(uv,mm),
					_mm_cmpgt_epi32(m0,uv)),mm)));
					uv=_mm_add_epi32(_mm_sub_epi32(u,v),mm);
					_mm_storeu_si128((__m128i*)(xb+j),
					_mm_sub_epi32(my_mullo_epu32(uv,p4),
					my_mullo_epu32(my_mulhi_epu32(uv,q4),m1)));
				}
			}
		}
		else
		{
			us *xa=x,*xb=x+t;
			for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
			{
				const __m128i p4=_mm_set1_epi32(p[i]),
				q4=_mm_set1_epi32(q[i]),
				mm=_mm_set1_epi32(MOD+MOD),
				m0=_mm_set1_epi32(0),
				m1=_mm_set1_epi32(MOD);
				//unfold 2x
				for(int j=0;j<t;j+=8)
				{
					__m128i u0=_mm_loadu_si128((__m128i*)(xa+j));
					__m128i u1=_mm_loadu_si128((__m128i*)(xa+j+4));
					__m128i v0=_mm_loadu_si128((__m128i*)(xb+j));
					__m128i v1=_mm_loadu_si128((__m128i*)(xb+j+4));
					__m128i uv0=_mm_add_epi32(u0,v0);
					__m128i uv1=_mm_add_epi32(u1,v1);
					_mm_storeu_si128((__m128i*)(xa+j),_mm_sub_epi32(uv0,
					_mm_and_si128(_mm_or_si128(_mm_cmpgt_epi32(uv0,mm),
					_mm_cmpgt_epi32(m0,uv0)),mm)));
					_mm_storeu_si128((__m128i*)(xa+j+4),_mm_sub_epi32(uv1,
					_mm_and_si128(_mm_or_si128(_mm_cmpgt_epi32(uv1,mm),
					_mm_cmpgt_epi32(m0,uv1)),mm)));
					uv0=_mm_add_epi32(_mm_sub_epi32(u0,v0),mm);
					uv1=_mm_add_epi32(_mm_sub_epi32(u1,v1),mm);
					_mm_storeu_si128((__m128i*)(xb+j),
					_mm_sub_epi32(my_mullo_epu32(uv0,p4),
					my_mullo_epu32(my_mulhi_epu32(uv0,q4),m1)));
					_mm_storeu_si128((__m128i*)(xb+j+4),
					_mm_sub_epi32(my_mullo_epu32(uv1,p4),
					my_mullo_epu32(my_mulhi_epu32(uv1,q4),m1)));
				}
			}
		}
		t<<=1;
	}
	us rn=qp(n,MOD-2);
	for(int i=0;i<n;++i)
		x[i]=x[i]*(ull)rn%MOD;
}
/*
void ntt(us* x,int n,bool f=true)
{
	prep(n); int t=n>>1;
	for(int m=1;m<n;m<<=1,t>>=1)
	{
		us *p=p0[m],*q=q0[m],*xa=x,*xb=x+t;
		for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
			for(int j=0;j<t;++j)
			{
				us u=xa[j]-(xa[j]>=us(MOD+MOD))*us(MOD+MOD);
				us v=my_mul(xb[j],p[i],q[i]);
				xa[j]=u+v; xb[j]=u-v+us(MOD+MOD);
			}
	}
	for(int i=0;i<n;++i)
		x[i]-=(x[i]>=us(MOD+MOD))*us(MOD+MOD),
		x[i]-=(x[i]>=us(MOD))*us(MOD);
	if(f) bit_flip(x,n);
}
void intt(us* x,int n,bool f=true)
{
	prep(n); int t=1;
	if(f) bit_flip(x,n);
	for(int m=(n>>1);m;m>>=1,t<<=1)
	{
		us *p=p1[m],*q=q1[m],*xa=x,*xb=x+t;
		for(int i=0;i<m;++i,xa+=t+t,xb+=t+t)
			for(int j=0;j<t;++j)
			{
				us u=xa[j],v=xb[j];
				xa[j]=u+v-(u+v>=us(MOD+MOD))*us(MOD+MOD);
				xb[j]=my_mul(u-v+us(MOD+MOD),p[i],q[i]);
			}
	}
	us rn=qp(n,MOD-2);
	for(int i=0;i<n;++i)
		x[i]=x[i]*(ull)rn%MOD;
}*/
//modint
struct mi
{
us w;
mi() {}
mi(us u) {w=u;}
mi(int u) {u%=MOD; w=u+((u<0)?MOD:0);}
explicit operator us() {return w;}
explicit operator int() {return w;}
};
mi operator + (const mi& a,const mi& b)
{return mi{a.w+b.w-((a.w+b.w>=MOD)?(MOD):0)};}
mi operator - (const mi& a,const mi& b)
{return mi{a.w-b.w+((a.w<b.w)?(MOD):0)};}
mi operator * (const mi& a,const mi& b)
{return mi{us((ull)a.w*b.w%MOD)};}
mi operator / (const mi& a,const mi& b)
{return mi{us((ull)a.w*qp(b.w,MOD-2)%MOD)};}
mi inv(const mi& a)
{return mi{us(qp(a.w,MOD-2))};}
bool operator == (const mi& a,const mi& b) {return a.w==b.w;}
bool operator != (const mi& a,const mi& b) {return a.w!=b.w;}
mi& operator += (mi& a,const mi& b) {a.w=a.w+b.w-((a.w+b.w>=MOD)?MOD:0); return a;}
mi& operator -= (mi& a,const mi& b) {a.w=a.w-b.w+((a.w<b.w)?MOD:0); return a;}
mi operator - (const mi& a)
{return mi{a.w?(MOD-a.w):0};}
mi& operator ++ (mi& a) {a.w=a.w+1-((a.w+1>=MOD)?MOD:0); return a;}
mi& operator -- (mi& a) {a.w=a.w-1+(a.w?0:MOD); return a;}
//what could possibly go wrong?
void ntt(mi* x,int n,bool f=true) {ntt((us*)x,n,f);}
void intt(mi* x,int n,bool f=true) {intt((us*)x,n,f);}
void fft(mi* x,int n,bool r,bool f=true)
{
	if(r) intt(x,n,f);
	else ntt(x,n,f);
}
void cp(mi*t,mi*s,int K)
{
	if(s) memcpy(t,s,sizeof(mi)*K);
	else memset(t,0,sizeof(mi)*K);
}
void cp(mi*t,mi s,int K)
{
	if(s.w==0) memset(t,0,sizeof(mi)*K);
	else for(int i=0;i<K;++i) t[i]=s;
}
mi mempool[SZ*8+10000] __attribute__ ((aligned(64))),*pt=mempool;
mi*alc(int t,bool c=0)
{
	if(c) cp(pt,0,t);
	pt+=t; return pt-t;
}
void ginv_K(mi*x,mi*o,int K)
{
	if(K==1)
	{
		o[0]=inv(x[0]);
		return;
	}
	ginv_K(x,o,K>>1);
	mi*fo=alc(K,1),*fx=alc(K),*fw=alc(K);
	cp(fo,o,(K>>1)); fft(fo,K,0); cp(fx,x,K); fft(fx,K,0);
	for(int i=0;i<K;++i) fw[i]=fx[i]*fo[i];
	fft(fw,K,1); cp(fw,fw+(K>>1),K>>1);
	cp(fw+(K>>1),0,K>>1); ntt(fw,K);
	for(int i=0;i<K;++i) fw[i]=fw[i]*fo[i]; fft(fw,K,1);
	for(int i=0;i<(K>>1);++i) o[i+(K>>1)]=-fw[i];
	pt-=K+K+K;
}
void ginv(mi*x,mi*o,int n)
{
	int K=getK(n);
	mi *fx=alc(K),*fo=alc(K);
	cp(fx,x,n); ginv_K(fx,fo,K);
	cp(o,fo,n); pt-=K+K;
}
void gdiv(mi*a,mi*b,mi*d,int n,int m)
{
	int s=getK(max(n,m));
	mi *ra=alc(s+s,1),*rb=alc(s+s,1);
	for(int i=0;i<n;++i) ra[i]=a[n-1-i];
	for(int i=0;i<m;++i) rb[i]=b[m-1-i];
	ginv(rb,rb,s); fft(ra,s+s,0); fft(rb,s+s,0);
	for(int i=0;i<s+s;++i) rb[i]=ra[i]*rb[i];
	fft(rb,s+s,1); for(int i=0;i<=n-m;++i) d[i]=rb[n-m-i];
	pt-=s*4;
}
void gdiv(mi*a,mi*b,mi*d,mi*r,int n,int m)
{
	gdiv(a,b,d,n,m);
	int s=getK(n+1);
	mi *bb=alc(s,1),*dd=alc(s,1);
	cp(bb,b,m); cp(dd,d,n-m+1);
	fft(bb,s,0); fft(dd,s,0);
	for(int i=0;i<s;++i)
		bb[i]=-bb[i]*dd[i];
	fft(bb,s,1);
	for(int i=0;i<m;++i)
		r[i]=a[i]+bb[i];
	pt-=s*2;
}
#define SZ 666666
mi fac[SZ],rfac[SZ];
struct Fac_Initer
{
Fac_Initer()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i;
	rfac[SZ-1]=inv(fac[SZ-1]);
	for(int i=SZ-1;i;--i) rfac[i-1]=rfac[i]*i;
}
}fac__initer__;
void gln(mi*a,mi*b,int n)
{
	int s=getK(n+n);
	mi *ra=alc(s,1);
	ginv(a,ra,n);
	mi *rb=alc(s,1);
	for(int i=0;i+1<n;++i)
		rb[i]=a[i+1]*(i+1);
	fft(ra,s,0); fft(rb,s,0);
	for(int i=0;i<s;++i)
		ra[i]=ra[i]*rb[i];
	fft(ra,s,1); b[0]=0;
	for(int i=1;i<n;++i)
		b[i]=ra[i-1]*rfac[i]*fac[i-1];
	pt-=s*2;
}
void gsqrt_K(mi*f,mi*g,mi*h,int K,bool ch=1)
{
	static mi gh[SZ];
	if(K==1)
	{
		if(f[0]!=1)
			throw "todo";
		g[0]=h[0]=gh[0]=1;
		return;
	}
	gsqrt_K(f,g,h,K>>1);
	mi*fh=alc(K,1),*gg=alc(K>>1),*rr=alc(K,1);
	cp(fh,h,(K>>1)); fft(fh,K,0); cp(gg,gh,K>>1);
	for(int i=0;i<(K>>1);++i)
		gg[i]=gg[i]*gg[i];
	fft(gg,K>>1,1);
	for(int i=0;i<(K>>1);++i)
		rr[i+(K>>1)]=gg[i]-f[i]-f[i+(K>>1)];
	fft(rr,K,0);
	for(int i=0;i<K;++i)
		rr[i]=rr[i]*fh[i]*((MOD+1)/2);
	fft(rr,K,1);
	for(int i=(K>>1);i<K;++i)
		g[i]=-rr[i];
	if(ch)
	{
		mi *fg=alc(K),*fw=alc(K);
		cp(fg,g,K); fft(fg,K,0);
		for(int i=0;i<K;++i) fw[i]=fg[i]*fh[i];
		fft(fw,K,1); for(int i=0;i<(K>>1);++i)
		fw[i]=fw[i+(K>>1)]; cp(fw+(K>>1),0,K>>1);
		fft(fw,K,0); for(int i=0;i<K;++i)
		fw[i]=fw[i]*fh[i]; fft(fw,K,1);
		for(int i=0;i<(K>>1);++i) h[i+(K>>1)]=-fw[i];
		cp(gh,fg,K); pt-=K+K;
	}
	pt-=K+K+(K>>1);
}
void gsqrt(mi*f,mi*g,int n)
{
	int s=getK(n);
	mi *mf=alc(s,1),
	*mg=alc(s),*mh=alc(s);
	cp(mf,f,n); gsqrt_K(mf,mg,mh,s,0);
	cp(g,mg,n); pt-=s+s+s;
}
void gexp_K(mi*f,mi*g,mi*h,int K,bool ch=1)
{
	if(K==1)
	{
		g[0]=h[0]=1;
		return;
	}
	gexp_K(f,g,h,K>>1);
	mi*gg=alc(K>>1),*hh=alc(K>>1),*fh,
	*dg=alc(K>>1),*t1=alc(K,1),*t2=alc(K,1);
	dg[(K>>1)-1]=0;
	for(int i=0;i+1<(K>>1);++i)
		dg[i]=g[i+1]*(i+1);
	cp(gg,g,K>>1); mi c=0;
	for(int i=0;i<(K>>1);++i)
		c=c+dg[i]*h[((K>>1)-1)-i];
	if(!ch)
		cp(hh,h,K>>1), fft(hh,K>>1,0);
	else
	{
		fh=alc(K,1); cp(fh,h,(K>>1)); fft(fh,K,0);
		for(int i=0;i<K;i+=2) hh[i>>1]=fh[i];
	}
	fft(gg,K>>1,0); fft(dg,K>>1,0);
	for(int i=0;i<(K>>1);++i) gg[i]=gg[i]*hh[i];
	fft(gg,K>>1,1);
	for(int i=0;i<(K>>1);++i)
		t1[i+(K>>1)]=(i==0)-gg[i];
	for(int i=0;i+1<(K>>1);++i)
		t2[i]=f[i+1]*(i+1);
	fft(t1,K,0); fft(t2,K,0);
	for(int i=0;i<K;++i) t1[i]=t1[i]*t2[i];
	fft(t1,K,1);
	for(int i=0;i<(K>>1);++i) t1[i]=0;
	for(int i=0;i+1<K;++i)
		t1[i]=t1[i]-f[i+1]*(i+1);
	for(int i=0;i<(K>>1);++i) dg[i]=dg[i]*hh[i];
	fft(dg,K>>1,1); mi r;
	for(int i=0;i<(K>>1);++i)
		r=(i+1==(K>>1))?c:(f[i+1]*(i+1)),
		t1[i]=t1[i]+r,t1[i+(K>>1)]=t1[i+(K>>1)]+dg[i]-r;
	t2[0]=0;
	for(int i=0;i+1<K;++i)
		t2[i+1]=t1[i]*rfac[i+1]*fac[i];
	cp(t1,g,K>>1); cp(t1+(K>>1),0,K>>1);
	fft(t1,K,0); fft(t2,K,0);
	for(int i=0;i<K;++i) t1[i]=t1[i]*t2[i];
	fft(t1,K,1);
	for(int i=(K>>1);i<K;++i)
		g[i]=-t1[i];
	pt-=K*2+(K>>1)*3;
	if(ch)
	{
		mi *fg=alc(K),*fw=alc(K);
		cp(fg,g,K); fft(fg,K,0);
		for(int i=0;i<K;++i) fw[i]=fg[i]*fh[i];
		fft(fw,K,1); for(int i=0;i<(K>>1);++i)
		fw[i]=fw[i+(K>>1)]; cp(fw+(K>>1),0,K>>1);
		fft(fw,K,0); for(int i=0;i<K;++i)
		fw[i]=fw[i]*fh[i]; fft(fw,K,1);
		for(int i=0;i<(K>>1);++i) h[i+(K>>1)]=-fw[i];
		pt-=K+K+K;
	}
}
void gexp(mi*f,mi*g,int n)
{
	int s=getK(n);
	mi *mf=alc(s,1),
	*mg=alc(s),*mh=alc(s);
	cp(mf,f,n); gexp_K(mf,mg,mh,s,0);
	cp(g,mg,n); pt-=s+s+s;
}

//copied from http://uoj.ac/submission/386710
typedef unsigned uint;
struct IO_Tp
{
	const static int _I_Buffer_Size = 2 << 20;
	char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;
	const static int _O_Buffer_Size = 2 << 20;
	char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;
	uint m[10000];
	IO_Tp()
	{
		constexpr uint e0 = '\0\0\0\1', e1 = '\0\0\1\0', e2 = '\0\1\0\0', e3 = '\1\0\0\0';
		int x = 0;
		for (uint i = 0, c0 = '0000'; i != 10; ++i, c0 += e0)
			for (uint j = 0, c1 = c0; j != 10; ++j, c1 += e1)
				for (uint k = 0, c2 = c1; k != 10; ++k, c2 += e2)
					for (uint l = 0, c3 = c2; l != 10; ++l, c3 += e3)
						m[x++] = c3;
		
		fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
	}
	~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }
	IO_Tp &operator>>(int &res)
	{
		while (!isdigit(*_I_pos))
			++_I_pos;
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		return *this;
	}
	IO_Tp &operator>>(mi &res_)
	{
		uint res=0;
		while (!isdigit(*_I_pos))
			++_I_pos;
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		(res>=MOD+MOD)?(res-=MOD+MOD):0;
		(res>=MOD)?(res-=MOD):0;
		res_.w=res;
		return *this;
	}
	IO_Tp &operator>>(uint &res)
	{
		while (!isdigit(*_I_pos))
			++_I_pos;
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		return *this;
	}
	IO_Tp &operator<<(mi x_)
	{
		us x=x_.w;
		if (x == 0)
		{
			*_O_pos++ = '0';
			return *this; 
		}
		static char _buf[12];
		char *_pos = _buf + 12;
		if (x >= 10000)
			*--reinterpret_cast<uint *&>(_pos) = m[x % 10000], x /= 10000;
		if (x >= 10000)
			*--reinterpret_cast<uint *&>(_pos) = m[x % 10000], x /= 10000;
		*--reinterpret_cast<uint *&>(_pos) = m[x];
		_pos += (x < 1000) + (x < 100) + (x < 10);
		_O_pos = std::copy(_pos, _buf + 12, _O_pos);
		return *this;
	}
	IO_Tp &operator<<(uint x)
	{
		if (x == 0)
		{
			*_O_pos++ = '0';
			return *this; 
		}
		static char _buf[12];
		char *_pos = _buf + 12;
		if (x >= 10000)
			*--reinterpret_cast<uint *&>(_pos) = m[x % 10000], x /= 10000;
		if (x >= 10000)
			*--reinterpret_cast<uint *&>(_pos) = m[x % 10000], x /= 10000;
		*--reinterpret_cast<uint *&>(_pos) = m[x];
		_pos += (x < 1000) + (x < 100) + (x < 10);
		_O_pos = std::copy(_pos, _buf + 12, _O_pos);
		return *this;
	}
	IO_Tp &operator<<(char ch)
	{
		*_O_pos++ = ch;
		return *this;
	}
} IO;
int n,m;
mi c[SZ] __attribute__ ((aligned(64))),cg[SZ] __attribute__ ((aligned(64)));
int main()
{
	IO>>n>>m; c[0]=1;
	for(int i=1,w;i<=n;++i)
	{IO>>w; if(w<=m) c[w]=-4;}
	gsqrt(c,cg,m+1); ++cg[0];
	ginv(cg,c,m+1);
	for(int i=1;i<=m;++i) IO<<c[i]*2<<'\n';
}