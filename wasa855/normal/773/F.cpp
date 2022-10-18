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
#define ll long long
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
vector<int> rev,rt,one(1,1),zer;

#undef int

namespace Poly
{
	#define mod 31525197391593473LL
	#define int long long
	#define ull unsigned long long
	inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
	inline int add(int x,int y,int z){return add(add(x,y),z);}
	inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
	// inline ull mul(ull x,ull y){return (x*y-(ull)((long double)x/mod*y)*mod+mod)%mod;}
	inline int mul(int x,int y){return (__int128)x*y%mod;}
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
	int __inv[2000005];
	const int G=3;
	void Init_Inv()
	{
		__inv[0]=__inv[1]=1;
		for(int i=2;i<=2000000;i++) __inv[i]=mul(mod-mod/i,__inv[mod%i]);
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
	vector<int> Mul(vector<int> a,vector<int> b)
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
	#undef mod
};
#undef int

#define int long long
int n,m,mod;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
vector<int> _QAQ;
vector<int> operator * (vector<int> x,vector<int> y)
{
	vector<ll> a(x.size()),b(y.size());
	for(int i=0;i<(int)x.size();i++) a[i]=x[i];
	for(int i=0;i<(int)y.size();i++) b[i]=y[i];
	vector<ll> r=Poly::Mul(a,b);
	vector<int> ans(r.size());
	for(int i=0;i<(int)r.size();i++) ans[i]=r[i]%mod;
	if((int)ans.size()>n+1) ans.resize(n+1);
	return ans;
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
vector<int> a[200],b[200];
int cnt;
map<int,int> vis;
void print(vector<int> v)
{
	cout<<"-- ";
	for(int i :v) printf("%d ",i);
	cout<<"\n";
}
int solve(int x)
{
	if(vis[x]) return vis[x];
	vis[x]=++cnt;
	int cur=cnt;
	if(x==0)
	{
		a[cur]=b[cur]=zer;
		return cur;
	}
	int V=solve(x/2);
	vector<int> A=a[V],B=b[V];
	// print(A),print(B);
	if(x%2==0)
	{
		if((x/2)&1) a[cur]=A+(A+B+one)*B,b[cur]=B+(A+B+one)*A;
		else a[cur]=A+(A+B+one)*A,b[cur]=B+(A+B+one)*B;
	}
	else
	{
		int R=solve(x-1);
		vector<int> A=a[R],B=b[R];
		if(x&1) B=B+(A+B+one)*_QAQ;
		else A=A+(A+B+one)*_QAQ;
		a[cur]=A,b[cur]=B;
	/*
		vector<int> C=A,D=B;
		if((x/2)&1) C=C+(A+B+one)*_QAQ;
		else D=D+(A+B+one)*_QAQ;
		if((x/2)&1) a[cur]=A+(A+B+one)*C,b[cur]=A+(A+B+one)*D;
		else a[cur]=A+(A+B+one)*D,b[cur]=A+(A+B+one)*C;
	*/
	}
	return cur;
}
signed main()
{
	Poly::Init_Inv();
	_QAQ.resize(2); _QAQ[1]=1; zer.resize(1);
	// cout<<_QAQ[1]<<endl;
	cin>>n>>m>>mod;
	int ans=0;
	for(ll i=2;i<=m;i*=2)
	{
		int pl=solve(m/i);
		// printf("%d :\n",m/i);
		// for(int i=0;i<(int)a[pl].size();i++) printf("%d ",a[pl][i]); cout<<"\n";
		// for(int i=0;i<(int)b[pl].size();i++) printf("%d ",b[pl][i]); cout<<"\n";
		for(int i=1;i<(int)b[pl].size();i+=2) ans=add(ans,b[pl][i]);
	}
	cout<<ans<<endl;
	return 0;
}