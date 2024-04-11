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
#define mod 20501757953LL
#define int long long
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return (x*y-(int)((long double)x/mod*y)*mod+mod)%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
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
int getInv(int x)
{
	return qpow(x,mod-2);
}
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
	vector<int> PolyInv(vector<int> a,int B)
	{
		if(B==0) return vector<int>(1,getInv(a[0]));
		int n=1<<B; a.resize(n);
		vector<int> f,f0=PolyInv(a,B-1);
		a.resize(n<<1),f.resize(n),f0.resize(n<<1);
		for(int i=0;i<(n>>1);i++) f[i]=add(f0[i],f0[i]);
		init(B+1); NTT(f0,B+1); NTT(a,B+1);
		for(int i=0;i<(n<<1);i++) f0[i]=mul(a[i],mul(f0[i],f0[i]));
		reverse(f0.begin()+1,f0.end());
		NTT(f0,B+1);
		f0.resize(n);
		int in=__inv[n<<1];
		for(int i=0;i<n;i++) f[i]=sub(f[i],mul(f0[i],in));
		return f;
	}
	vector<int> Inv(vector<int> a)
	{
		int B=0,n=a.size();
		while((1<<B)<n) B++;
		a=PolyInv(a,B);
		a.resize(n);
		return a;
	}
	vector<int> PolySqrt(vector<int> a,int B)
	{
		int n=1<<B;
		a.resize(n);
		if(n==1) return one;
		vector<int> f0=PolySqrt(a,B-1);
		f0.resize(n);
		a=a*Inv(f0)+f0;
		a.resize(n);
		for(int i=0;i<n;i++)
		{
			if(a[i]&1) a[i]=(a[i]+mod)>>1;
			else a[i]>>=1;
		}
		return a;
	}
	vector<int> Sqrt(vector<int> a)
	{
		int B=0,n=a.size();
		while((1<<B)<n) B++;
		a=PolySqrt(a,B);
		a.resize(n);
		return a;
	}
	vector<int> Qiudao(vector<int> a)
	{
		int n=a.size()-1;
		for(int i=0;i<n;i++) a[i]=mul(a[i+1],i+1);
		a.resize(n); return a;
	}
	vector<int> Jifen(vector<int> a)
	{
		int n=a.size()+1;
		a.resize(n);
		for(int i=n-1;i>=1;i--) a[i]=mul(a[i-1],__inv[i]);
		a[0]=0; return a;
	}
	vector<int> Ln(vector<int> a)
	{
		int n=a.size();
		a=Jifen(Qiudao(a)*Inv(a));
		a.resize(n); return a;
	}
	vector<int> PolyExp(vector<int> a,int B)
	{
		if(B==0) return one;
		int n=1<<B;
		a.resize(n);
		vector<int> f=PolyExp(a,B-1);
		f.resize(n);
		vector<int> ans=f*(a+one-Ln(f));
		ans.resize(n);
		return ans;
	}
	vector<int> Exp(vector<int> a)
	{
		int B=0,n=a.size();
		while((1<<B)<n) B++;
		a=PolyExp(a,B);
		a.resize(n);
		return a;
	}
	vector<int> Div(vector<int> f,vector<int> g)
	{
		vector<int> fr=f,gr=g;
		int len=f.size()-g.size()+1;
		reverse(fr.begin(),fr.end());
		reverse(gr.begin(),gr.end());
		fr.resize(len),gr.resize(len);
		vector<int> q=fr*Inv(gr);
		q.resize(len);
		reverse(q.begin(),q.end());
		return q;
	}
	vector<int> Mod(vector<int> f,vector<int> g)
	{
		vector<int> q=Div(f,g);
		vector<int> r=f-q*g;
		r.resize(g.size()-1);
		return r;
	}
	vector<int> Qpow(vector<int> a,int k)
	{
		int n=a.size();
		vector<int> b=Ln(a);
		for(int i=0;i<n;i++) b[i]=mul(b[i],k);
		a=Exp(b);
		return a;
	}
	vector<int> Spow(vector<int> a,int k) //Slow Pow
	{
		int n=a.size();
		vector<int> ans=one;
		while(k)
		{
			if(k&1) ans=ans*a,ans.resize(n);
			a=a*a,a.resize(n);
			k>>=1;
		}
		ans.resize(n);
		return ans;
	}
};
using namespace Poly;
#define N 400005
int a[N];
signed main()
{
	Init_Inv();
	int n=read(),x=read();
	for(int i=1;i<=n;i++) a[i]=(read()<x);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	// for(int i=1;i<=n;i++) printf("%d ",a[i]); cout<<"\n";
	vector<int> f(n+1),g(n+1);
	for(int i=1;i<=n;i++) f[a[i]]++;
	for(int i=1;i<=n;i++) g[n-a[i]]++;
	g[n]++;
	f=f*g;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]!=a[i]) continue;
		int r=i;
		while(r<n&&a[r+1]==a[i]) r++;
		// printf("%d %d\n",i,r);
		ans+=(r-i+2)*(r-i+1)/2;
		i=r;
	}
	cout<<ans<<" ";
	for(int i=n+1;i<=n+n;i++) printf("%lld ",f[i]);
	return 0;
}