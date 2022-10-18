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
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
int qpow(int x,ll y)
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
int getInv(int x) {return qpow(x,mod-2);}
int Inv(int x) {return qpow(x,mod-2);}
namespace Poly
{
	vector<int> rev,rt,one(1,1);
	int __inv[2000005];
	const int G=3;
	void Init_Inv()
	{
		__inv[0]=__inv[1]=1;
		for(int i=2;i<=2000000;i++) __inv[i]=mul(mod-mod/i,__inv[mod%i]);
	}
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
	void NTT(vector<int> &a,int B)
	{
		int n=1<<B;
		for(int i=0;i<n;i++) if(rev[i]>i) swap(a[i],a[rev[i]]);
		for(int mid=1;mid<n;mid<<=1)
		{
			for(int i=0;i<n;i+=(mid<<1))
			{
				for(int j=0;j<mid;j++)
				{
					int x=a[i+j],y=mul(a[i+j+mid],rt[j+mid]);
					a[i+j]=add(x,y),a[i+j+mid]=sub(x,y);
				}
			}
		}
	}
	vector<int> operator * (vector<int> a,vector<int> b)
	{
		int B=0,n=a.size()+b.size()-1;
		while((1<<B)<n) B++;
		a.resize(1<<B),b.resize(1<<B);
		init(B);
		NTT(a,B),NTT(b,B);
		for(int i=0;i<(1<<B);i++) a[i]=mul(a[i],b[i]);
		reverse(a.begin()+1,a.end());
		NTT(a,B);
		a.resize(n);
		int In=getInv(1<<B);
		for(int i=0;i<n;i++) a[i]=mul(a[i],In);
		return a;
	}
};
using namespace Poly;
#define N 200005
int p[N],n; ll m;
int fac[N],inv[N],ifac[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
signed main()
{
	Init_Inv(),init();
	cin>>n>>m;
	for(int i=0;i<=n;i++) p[i]=read();
	m++;
	vector<int> f(n+1),g(n+1);
	for(int i=0;i<=n;i++) f[i]=mul(fac[i],p[i]);
	for(int i=0;i<=n;i++) g[i]=ifac[i];
	reverse(g.begin(),g.end()); g=f*g; for(int i=0;i<=n;i++) f[i]=mul(g[i+n],Inv(qpow(i+1,m-1)));
	g.resize(n+1); for(int i=0;i<=n;i++) g[i]=(i&1)?mod-ifac[i]:ifac[i];
	reverse(g.begin(),g.end()); g=f*g; for(int i=0;i<=n;i++) f[i]=mul(g[i+n],ifac[i]);
	for(int i=0;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	return 0;
}