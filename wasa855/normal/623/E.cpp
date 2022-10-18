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
#define mod 1000000007
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
int Inv(int x){return qpow(x,mod-2);}
const double pi=(acos(-1));
struct Complex
{
	double r,i;
	inline Complex(double r=0,double i=0):r(r),i(i){}
	inline Complex operator + (const Complex a) const {return Complex(a.r+r,a.i+i);}
	inline Complex operator - (const Complex a) const {return Complex(r-a.r,i-a.i);}
	inline Complex operator * (const Complex a) const {return Complex(r*a.r-i*a.i,r*a.i+i*a.r);}
	inline Complex operator / (const double a) const {return Complex(r/a,i/a);}
};
inline Complex conj(Complex x) {return Complex(x.r,-x.i);}
#define N 30005
int fac[N],inv[N],ifac[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
ll n;
int m;
namespace ArbitraryModPoly
{
	const Complex I(0,1);
	vector<int> rev;
	vector<Complex> rt;
	void init(int B)
	{
		rev.resize(1<<B),rt.resize(1<<B);
		for(int i=1;i<1<<B;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(B-1));
		for(int i=0;i<1<<B;i++) rt[i]=Complex(cos(2*pi*i/(1<<B)),sin(2*pi*i/(1<<B)));
	}
	void fft(vector<Complex> &a,int B)
	{
		for(int i=0;i<1<<B;i++) if(rev[i]>i) swap(a[i],a[rev[i]]);
		for(int i=1;i<1<<B;i<<=1)
		{
			for(int j=0;j<1<<B;j+=i<<1)
			{
				int go=(1<<B)/i/2;
				for(int k=0,c=0;k<i;k++,c+=go)
				{
					Complex x=a[j+k],y=a[i+j+k]*rt[c];
					a[j+k]=x+y,a[i+j+k]=x-y;
				}
			}
		}
	}
	vector<int> operator * (vector<int> a,vector<int> b)
	{
		int n=a.size()+b.size()-1;
		int B=0; while(1<<B<=n) B++;
		a.resize(1<<B),b.resize(1<<B),init(B);
		vector<Complex> f(1<<B),g(1<<B);
		for(int i=0;i<1<<B;i++) f[i]=Complex(a[i]&32767,a[i]>>15),g[i]=Complex(b[i]&32767,b[i]>>15);
		fft(f,B),fft(g,B);
		vector<Complex> ra(1<<B),rb(1<<B),rc(1<<B);
		Complex ta(0.5,0),tb(0,-0.5);
		for(int i=0;i<1<<B;i++)
		{
			int tmp=((1<<B)-i)&((1<<B)-1);
			Complex A=(f[i]+conj(f[tmp]))*ta,
					B=(f[i]-conj(f[tmp]))*tb,
					C=(g[i]+conj(g[tmp]))*ta,
					D=(g[i]-conj(g[tmp]))*tb;
			ra[i]=A*C,rb[i]=A*D+B*C,rc[i]=B*D;
		}
		for(int i=0;i<1<<B;i++) ra[i]=ra[i]+rb[i]*Complex(0,1);
		reverse(ra.begin()+1,ra.end()),reverse(rc.begin()+1,rc.end());
		fft(ra,B),fft(rc,B);
		for(int i=0;i<n;i++)
		{
			ll A=(ll)(ra[i].r/(1<<B)+0.5);
			int _B=(ll)(ra[i].i/(1<<B)+0.5)%mod;
			int C=(ll)(rc[i].r/(1<<B)+0.5)%mod;
			b[i]=(A+((ll)_B<<15)+((ll)C<<30))%mod;
		}
		b.resize(n);
		if((int)b.size()>m+1) b.resize(m+1);
		return b;
	}
};
using namespace ArbitraryModPoly;
vector<int> f[N];
vector<int> mrg(int x,int y)
{
	vector<int> A=f[x],B=f[y];
	B[0]=0;
	for(int i=1;i<(int)B.size();i++) B[i]=mul(B[i],ifac[i]);
	for(int i=1;i<(int)A.size();i++) A[i]=mul(A[i],ifac[i],qpow(2,i*y));
	vector<int> res=A*B;
	for(int i=1;i<(int)res.size();i++) res[i]=mul(res[i],fac[i]);
	return res;
}
vector<int> solve(int n)
{
	if(!f[n].empty()) return f[n];
	if(n==1)
	{
		f[1].resize(m+1);
		for(int i=1;i<=m;i++) f[1][i]=1;
		return f[1];
	}
	int x=n/2,y=n-x;
	solve(x),solve(y);
	return f[n]=mrg(x,y);
}
signed main()
{
	cin>>n>>m;
	if(n>m) cout<<"0\n",exit(0);
	init();
	vector<int> r=solve(n);
	int ans=0;
	for(int i=n;i<=m;i++) ans=add(ans,mul(C(m,i),r[i]));
	cout<<ans<<endl;
	return 0;
}