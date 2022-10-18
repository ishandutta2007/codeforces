#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1ULL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x) {return qpow(x,mod-2);}
/*
namespace Poly
{
	vector<int> rev,rt,one(1,1);
	const int G=3;
	vector<int> operator + (vector<int> a,vector<int> b)
	{
		int n=max(a.size(),b.size());
		a.resize(n),b.resize(n);
		for(int i=0;i<n;i++) a[i]=add(a[i],b[i]);
		return a;
	}
	vector<int> operator - (vector<int> a,vector<int> b)
	{
		int n=max(a.size(),b.size());
		a.resize(n),b.resize(n);
		for(int i=0;i<n;i++) a[i]=sub(a[i],b[i]);
		return a;
	}
	void init(int B)
	{
		int n=1<<B;
		rev.resize(n),rt.resize(n);
		for(int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(B-1));
		for(int mid=1;mid<n;mid<<=1)
		{
			int w=qpow(G,(mod-1)/(mid<<1));
			rt[mid]=1;
			for(int i=1;i<mid;i++) rt[mid+i]=mul(rt[mid+i-1],w);
		}
	}
	void ntt(vector<int> &a,int B)
	{
		for(int i=0;i<(int)a.size();i++) if(rev[i]>i) swap(a[rev[i]],a[i]);
		for(int i=1;i<1<<B;i<<=1)
		{
			for(int j=0;j<1<<B;j+=i<<1)
			{
				for(int k=0;k<i;k++)
				{
					int x=a[j+k],y=mul(a[i+j+k],rt[i+k]);
					a[j+k]=add(x,y),a[i+j+k]=sub(x,y);
				}
			}
		}
	}
	void idft(vector<int> &a,int B)
	{
		reverse(a.begin()+1,a.end()); ntt(a,B);
		int I=Inv(1<<B);
		for(int i=0;i<(int)a.size();i++) a[i]=mul(a[i],I);
	}
	vector<int> operator * (vector<int> x,vector<int> y)
	{
		int n=x.size()+y.size()-1;
		int B=0; while(1<<B<n) B++;
		x.resize(1<<B),y.resize(1<<B);
		init(B); ntt(x,B),ntt(y,B);
		for(int i=0;i<1<<B;i++) x[i]=mul(x[i],y[i]);
		idft(x,B);
		x.resize(n);
		return x;
	}
};
*/
namespace Poly
{
	#define SZ(x) ((int)x.size())
	const int max_len=1<<20,N=max_len+5;
	template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
	template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
	template<typename _Tp>inline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
	ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
	typedef unsigned uint;
	typedef unsigned long long ull;
	typedef std::vector<int> poly;
//	void print(const poly &a)
//	{
//		for(auto it:a)print(it);
//		putchar('\n');
//	}
	inline poly operator << (poly a,uint b){return a.insert(a.begin(),b,0),a;}
	inline poly operator <<= (poly &a,uint b){return a.insert(a.begin(),b,0),a;}
	inline poly operator >> (const poly &a,uint b){return b>=a.size()?poly():poly{a.begin()+b,a.end()};}
	inline poly operator >>= (poly &a,uint b){return a=b>=a.size()?poly():poly{a.begin()+b,a.end()};}
	poly operator += (poly &a,const poly &b)
	{
		if(SZ(b)>SZ(a)) a.resize(SZ(b));
		for(uint i=0;i<b.size();++i) add(a[i],b[i]);
		return a;
	}
	inline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
	poly operator -= (poly &a,const poly &b)
	{
		if(SZ(b)>SZ(a)) a.resize(SZ(b));
		for(uint i=0;i<b.size();++i) sub(a[i],b[i]);
		return a;
	}
	inline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
	ull Omgs[N];
	int r[N];
	const ull Omg=ksm(3,(mod-1)/max_len);
	int getlen(int len)
	{
		int limit=1;while(limit<len)limit<<=1;
		for(int i=0;i<limit;++i)r[i]=(r[i>>1]>>1)|(i&1?limit>>1:0);
		return limit;
	}
	void setup()
	{
		Omgs[max_len>>1]=1;
		for(int i=(max_len>>1)+1;i<max_len;++i) Omgs[i]=Omgs[i-1]*Omg%mod;
		for(int i=(max_len>>1)-1;i>0;--i) Omgs[i]=Omgs[i<<1];
	}
	void dft(ull *A,int limit)
	{
		for(int i=0;i<limit;++i)if(i<r[i])std::swap(A[i],A[r[i]]);
		for(int len=1;len<limit;len<<=1)
		{
			if(len==262144)for(int i=0;i<limit;++i)A[i]%=mod;
			for(int i=0;i<limit;i+=len<<1)
			{
				ull *p=A+i,*q=A+i+len,*w=Omgs+len;
				for(int _=0;_<len;++_,++p,++q,++w){ull tmp=*q**w%mod;*q=*p+mod-tmp,*p+=tmp;}
			}
		}
		for(int i=0;i<limit;++i)A[i]%=mod;
	}
	void idft(ull *A,int limit)
	{
		std::reverse(A+1,A+limit),dft(A,limit);
		ull inv=mod-(mod-1)/limit;for(int i=0;i<limit;++i) A[i]=inv*A[i]%mod;
	}
	ull _f[N],_g[N];
	poly operator * (const poly &a,const poly &b)
	{
		uint len=a.size()+b.size()-1;
		if(a.size()<=64u||b.size()<=64u)
		{
			poly c(len);
			for(uint i=0;i<len;++i)
			{
				int j=min(SZ(a)-1,(int)i),ed=max(0,(int)i-SZ(b)+1);ull v=0;
				for(;j-17>=ed;j-=18)v=(v+1ULL*a[j-0]*b[i-j+0]+1ULL*a[j-1]*b[i-j+1]+1ULL*a[j-2]*b[i-j+2]+1ULL*a[j-3]*b[i-j+3]+1ULL*a[j-4]*b[i-j+4]+1ULL*a[j-5]*b[i-j+5]+1ULL*a[j-6]*b[i-j+6]+1ULL*a[j-7]*b[i-j+7]+1ULL*a[j-8]*b[i-j+8]+1ULL*a[j-9]*b[i-j+9]+1ULL*a[j-10]*b[i-j+10]+1ULL*a[j-11]*b[i-j+11]+1ULL*a[j-12]*b[i-j+12]+1ULL*a[j-13]*b[i-j+13]+1ULL*a[j-14]*b[i-j+14]+1ULL*a[j-15]*b[i-j+15]+1ULL*a[j-16]*b[i-j+16]+1ULL*a[j-17]*b[i-j+17])%mod;
				for(;j>=ed;--j)v+=1ULL*a[j]*b[i-j];
				c[i]=v%mod;
			}
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
	poly mul(const poly &a,const poly &b,uint len,bool need=true)
	{
		if(a.size()<=64u||b.size()<=64u)
		{
			poly c(len);
			for(uint i=0;i<len;++i)
			{
				int j=min(SZ(a)-1,(int)i),ed=max(0,(int)i-SZ(b)+1);ull v=0;
				for(;j-17>=ed;j-=18)v=(v+1ULL*a[j-0]*b[i-j+0]+1ULL*a[j-1]*b[i-j+1]+1ULL*a[j-2]*b[i-j+2]+1ULL*a[j-3]*b[i-j+3]+1ULL*a[j-4]*b[i-j+4]+1ULL*a[j-5]*b[i-j+5]+1ULL*a[j-6]*b[i-j+6]+1ULL*a[j-7]*b[i-j+7]+1ULL*a[j-8]*b[i-j+8]+1ULL*a[j-9]*b[i-j+9]+1ULL*a[j-10]*b[i-j+10]+1ULL*a[j-11]*b[i-j+11]+1ULL*a[j-12]*b[i-j+12]+1ULL*a[j-13]*b[i-j+13]+1ULL*a[j-14]*b[i-j+14]+1ULL*a[j-15]*b[i-j+15]+1ULL*a[j-16]*b[i-j+16]+1ULL*a[j-17]*b[i-j+17])%mod;
				for(;j>=ed;--j)v+=1ULL*a[j]*b[i-j];
				c[i]=v%mod;
			}
			return c;
		}
		int limit=getlen(len);
		memset(_f,0,limit<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
		dft(_f,limit);
		if(need)
		{
			memset(_g,0,limit<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
			dft(_g,limit);
		}
		for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
		idft(_f,limit);
		poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
		return ans;
	}
	inline poly operator *= (poly &a,const poly &b){return a=a*b;}
	template<typename _Tp>inline poly operator *= (poly &a,const _Tp &b)
	{
		for(auto &&it:a) it=1ll*it*b%mod;
		return a;
	}
	template<typename _Tp>inline poly operator * (poly a,const _Tp &b){return a*=b;}
	template<typename _Tp>inline poly operator * (const _Tp &b,poly a){return a*=b;}
	template<typename _Tp>inline poly operator /= (poly &a,const _Tp &b)
	{
		ull inv=ksm(b);for(auto &&it:a) it=1ll*it*inv%mod;
		return a;
	}
	template<typename _Tp>inline poly operator / (poly a,const _Tp &b){return a/=b;}
	template<typename _Tp>inline poly operator / (const _Tp &b,poly a){return a/=b;}
};
//using namespace Poly;
using Poly::operator +;
using Poly::operator *;
#define N 100005
int fac[N],inv[N],ifac[N],A[N];
int n,k;
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
	A[0]=1; for(int i=1;i<=k;i++) A[i]=mul(A[i-1],k-i+1);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
vector<int> G[N];
int val[N],sum[N],siz[N];
vector<int> qwq[N];
namespace N1
{
	int w[N];
	vector<int> solve(int l,int r)
	{
		if(l==r) return {1,w[l]};
		int mid=(l+r)/2;
		return solve(l,mid)*solve(mid+1,r);
	}
	int work(vector<int> f,int _id)
	{
		int n=(int)f.size();
		if(n==0) return 1;
		for(int i=0;i<n;i++) w[i+1]=f[i];
		vector<int> res=solve(1,n);
		qwq[_id]=res;
		int ans=0;
		for(int i=0;i<(int)res.size();i++) ans=add(ans,mul(res[i],A[i]));
		return ans;
	}
};
int ans;
void dfs1(int u,int fa)
{
	siz[u]=1;
	vector<int> f;
	for(int v:G[u]) if(v!=fa) dfs1(v,u),siz[u]+=siz[v],f.pb(siz[v]);
	val[u]=N1::work(f,u); sum[u]=val[u];
	int pre=0;
	for(int v:G[u]) if(v!=fa)
	{
		sum[u]=add(sum[u],sum[v]);
		ans=add(ans,mul(pre,sum[v]));
		pre=add(pre,sum[v]);
	}
}
int w1[N],w2[N],cnt;
pair<vector<int>,vector<int>> solve(int l,int r)
{
	if(l>r) return {{0},{0}};
	if(l==r) return {{w1[l]},{1,w2[l]}};
	int mid=(l+r)/2;
	auto [lx,ly]=solve(l,mid);
	auto [rx,ry]=solve(mid+1,r);
	vector<int> A=lx*ry+ly*rx,B=ly*ry;
	return {A,B};
}
void dfs2(int u,int fa)
{
	for(int v:G[u]) if(v!=fa) dfs2(v,u);
	cnt=0;
	for(int v:G[u]) if(v!=fa)
	{
		cnt++,w1[cnt]=sum[v],w2[cnt]=siz[v];
	}
	auto [r,s]=solve(1,cnt);
	vector<int> qwq={1,n-siz[u]};
	r=r*qwq;
	for(int i=0;i<(int)r.size();i++) ans=add(ans,mul(r[i],A[i]));
	// printf("%d %d\n",u,ans);
}
signed main()
{
	Poly::setup();
	cin>>n>>k;
	init();
	if(k==1)
	{
		cout<<1LL*n*(n-1)/2%mod<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans<<endl;
	return 0;
}