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
#define SZ 666666
struct comp {ld a,b;
comp() {}
comp(ld x):a(x),b(0) {}
comp(ld x,ld y):a(x),b(y) {}
}; //a+bi
inline comp operator + (comp a,comp b)
{return comp(a.a+b.a,a.b+b.b);}
inline comp operator - (comp a,comp b)
{return comp(a.a-b.a,a.b-b.b);}
inline comp operator * (comp a,comp b)
{return comp(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);}
ostream& operator << (ostream& a,comp b)
{a<<"("<<b.a<<","<<b.b<<")"; return a;}
int K; comp w[2][SZ];
comp qp(comp a,ll b)
{
	comp x=1;
	while(b)
	{
		if(b&1) x=x*a;
		a=a*a; b>>=1;
	}
	return x;
}
const int MOD=998244353;//1e9+9; //stm
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
const ld pi=acos(-1);
int rev[SZ];
void init(int s)
{
	for(K=1;K<s;K<<=1);
	{
	ld t=pi*2/K;
	for(int i=0;i<=K;++i)
		w[0][i]=comp(cos(t*i),sin(t*i));
	}
	for(int i=0;i<=K;++i)
		w[1][i]=w[0][K-i];
	for(int i=0;i<K;++i)
	{
		int t=0,x=i;
		for(int j=1;j<K;j<<=1)
			t=t*2+(x&1),x>>=1;
		rev[i]=t;
	}
}
void fft(comp*x,int k)
{
	for(int i=0;i<K;++i)
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	for(int i=2;i<=K;i<<=1)
		for(int j=0;j<K;j+=i)
			for(int s=0;s<(i>>1);++s)
			{
				comp t=x[j+s+(i>>1)]*w[k][K/i*s];
				x[j+s+(i>>1)]=x[j+s]-t;x[j+s]=x[j+s]+t;
			}
	if(k) return;
	//better precision!
	ld sK=sqrt(K);
	for(int i=0;i<K;++i)
		x[i].a/=sK, x[i].b/=sK;
}
int a0_[SZ],b0_[SZ],a1_[SZ],b1_[SZ]; ll x0_[SZ],x1_[SZ];
comp a0[SZ],b0[SZ],a1[SZ],b1[SZ],x0[SZ],x1[SZ],x2[SZ];
comp ps[SZ];
template<class T>
void comb_fft0(T*a,T*b,comp*aa,comp*bb)
{
	for(int i=0;i<K;++i)
		ps[i].a=a[i],ps[i].b=b[i];
	fft(ps,0);
	for(int i=0;i<K;++i)
	{
		comp pr=ps[i?(K-i):i];
		pr.b=-pr.b;
		aa[i]=(ps[i]+pr)*0.5;
		bb[i]=(ps[i]-pr)*0.5;
		swap(bb[i].a,bb[i].b);
		bb[i].b=-bb[i].b;
	}
}
template<class T>
void comb_fft1(comp*aa,comp*bb,T*a,T*b)
{
	for(int i=0;i<K;++i)
	{
		comp t=bb[i]; t.b*=-1;
		swap(t.a,t.b); ps[i]=aa[i]+t;
	}
	fft(ps,1);
	for(int i=0;i<K;++i)
		a[i]=llround(ps[i].a),
		b[i]=llround(ps[i].b);
}
#define B 32768
vector<int> conv(const vector<int>& a,const vector<int>& b,int p=MOD)
{
	if(a.size()&&b.size());else return vector<int>();
	init(a.size()+b.size()+2);
	for(int i=0;i<K;++i) a0_[i]=a1_[i]=b0_[i]=b1_[i]=0;
	for(int i=0;i<(int)a.size();++i)
	{
		int t=(a[i]%p+p)%p;
		a0_[i]=t%B,a1_[i]=t/B;
	}
	for(int i=0;i<(int)b.size();++i)
	{
		int t=(b[i]%p+p)%p;
		b0_[i]=t%B,b1_[i]=t/B;
	}
	comb_fft0(a0_,a1_,a0,a1);
	comb_fft0(b0_,b1_,b0,b1);
	for(int i=0;i<K;++i)
		x0[i]=a0[i]*b0[i],
		x1[i]=a0[i]*b1[i]+a1[i]*b0[i],
		x2[i]=a1[i]*b1[i];
	comb_fft1(x0,x1,x0_,x1_); fft(x2,1);
	vector<int> c;
	for(int i=0;i<int(a.size()+b.size()-1);++i)
	{
		ll s=x0_[i]%p+x1_[i]%p*B
		+llround(x2[i].a)%p*B%p*B;
		s=(s%p+p)%p; c.pb(s);
	}
	return c;
}
#undef B
int n,k,sz[SZ],fa[SZ]; Edg
void dfs(int x,int f=0)
{
	sz[x]=1; fa[x]=f;
	for esb(x,e,b) if(b!=f)
		dfs(b,x),sz[x]+=sz[b];
}
int tn,ts[SZ];
vector<int> calc(int l,int r)
{
	if(l>r)
	{
		vector<int> t(1,1);
		return t;
	}
	if(l==r)
	{
		vector<int> t(2,1);
		t[1]=ts[l]; return t;
	}
	int m=(l+r)>>1;
	return conv(calc(l,m),calc(m+1,r));
}
int vx[SZ]; ll f[SZ],coe[SZ],sf[SZ],rs[SZ];
vector<int> vv[SZ],vg[SZ],tt;
ll ans=0;
void ddd(int x)
{
	sf[x]=f[x];
	for esb(x,e,b) if(b!=fa[x])
		ddd(b),sf[x]=(sf[x]+sf[b])%MOD;
	vg[x]=vv[x];
	vg[x].pb(0);
	for(int i=int(vg[x].size())-1;i;--i)
		vg[x][i]=(vg[x][i]+vg[x][i-1]*(ll)(n-sz[x]))%MOD;
	ll su=0;
	for esb(x,e,b) if(b!=fa[x])
	{
		if(vx[sz[b]]!=x)
		{
			tt=vg[x];
			for(int i=1;i<int(tt.size());++i)
				tt[i]=(tt[i]-tt[i-1]*(ll)sz[b])%MOD;
			rs[sz[b]]=0;
			for(int i=0;i<int(tt.size());++i)
				rs[sz[b]]=(rs[sz[b]]+tt[i]*coe[i])%MOD;
			vx[sz[b]]=x;
		}
		ans+=(rs[sz[b]]+su)*sf[b]; ans%=MOD;
		(su+=sf[b])%=MOD;
	}
}
int main()
{
	srand(time(0));
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("%lld\n",n*(ll)(n-1)/2%MOD);
		return 0;
	}
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	coe[0]=1;
	for(int i=1;i<=k;++i)
		coe[i]=coe[i-1]*(k-i+1)%MOD;
	int t=rand()%n+1; dfs(t);
	for(int i=1;i<=n;++i)
	{
		tn=0;
		for esb(i,e,b) if(b!=fa[i])
			ts[++tn]=sz[b];
		vv[i]=calc(1,tn);
		for(int j=0;j<int(vv[i].size());++j)
			f[i]=(f[i]+vv[i][j]*coe[j])%MOD;
	}
	ddd(t);
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}