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
using namespace Poly;
#define N 100005
const int i2=(mod+1)/2;
int fac[N],inv[N],ifac[N];
int norm(int x) {return ((x%mod)+mod)%mod;}
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
int a[N],b[N],n,m;
struct Node
{
	vector<int> a[2][2];
	int coef;
	Node() {coef=0; for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j].resize(1);}
};
vector<int> shift(vector<int> a)
{
	int n=(int)a.size()+1;
	vector<int> ans(n);
	for(int i=0;i<(int)a.size();i++) ans[i+1]=a[i];
	return ans;
}
vector<int> mul(vector<int> a,int b)
{
	b=norm(b);
	// printf("***** %d : ",b),print(a);
	for(int i=0;i<(int)a.size();i++) a[i]=mul(a[i],b);
	// print(a);
	return a;
}
int sgn(int x)
{
	if(x>0) return 1;
	else if(x==0) return 0;
	else return -1;
}
Node solve(int l,int r)
{
	if(l==r)
	{
		Node ans;
		ans.coef=a[l]>1?2:1;
		return ans;
	}
	int mid=(l+r)/2;
	Node A=solve(l,mid),B=solve(mid+1,r);
	Node ans; ans.coef=sgn(A.coef)*sgn(B.coef)*-2;
	int c=abs(A.coef),d=abs(B.coef);
	int p=c>1,q=d>1;
	// printf("%d %d\n",A.coef,B.coef);
	for(int i=0;i<2;i++) for(int j=0;j<2;j++)
	{
		for(int c=0;c<2;c++) for(int d=0;d<2;d++)
		{
			vector<int> r=A.a[i][j]*B.a[c][d];
			ans.a[i][d]=ans.a[i][d]+shift(r);
			if(j==1&&c==1) r=mul(r,i2);
			if(j==0&&c==0) r=mul(r,2);
			// printf("$$ %d %d %d %d : ",i,j,c,d),print(r);
			ans.a[i][d]=ans.a[i][d]-r;
		}
	}
	// printf("%d %d : \n",l,r);
	// for(int i=0;i<2;i++) for(int j=0;j<2;j++) printf("%d %d : ",i,j),print(ans.a[i][j]);
	// cout<<"-----------\n";
	for(int i=0;i<2;i++) for(int j=0;j<2;j++)
	{
		ans.a[i][q]=ans.a[i][q]+shift(mul(A.a[i][j],B.coef));
		int qwq=(j==0)?2:1;
		qwq*=sgn(B.coef);
		// printf("$$ %d %d : ",i,j),print(mul(A.a[i][j],qwq));
		ans.a[i][1]=ans.a[i][1]-mul(A.a[i][j],qwq);
		// print(ans.a[i][1]);
	}
	// print(ans.a[1][1]);
	for(int c=0;c<2;c++) for(int d=0;d<2;d++)
	{
		ans.a[p][d]=ans.a[p][d]+shift(mul(B.a[c][d],A.coef));
		int qwq=(c==0)?2:1;
		qwq*=sgn(A.coef);
		ans.a[1][d]=ans.a[1][d]-mul(B.a[c][d],qwq);
	}
	c=c>1,d=d>1;
	if(ans.a[c][d].size()<2) ans.a[c][d].resize(2);
	ans.a[c][d][1]=add(ans.a[c][d][1],norm(A.coef*B.coef));
	// printf("%d %d : \n",l,r);
	// for(int i=0;i<2;i++) for(int j=0;j<2;j++) printf("%d %d : ",i,j),print(ans.a[i][j]);
	return ans;
}
signed main()
{
	init();
	cin>>n; for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;)
	{
		a[++m]=b[i];
		for(int j=0;j<b[i];j++) if(b[i+j]!=b[i]) return cout<<"0\n",0;
		i+=b[i];
	}
	// for(int i=1;i<=m;i++) printf("%d%c",a[i]," \n"[i==m]);
	// return 0;
	Node res=solve(1,m);
	int Ans=0;
	vector<int> ans=res.a[0][0]+res.a[0][1]+res.a[1][0]+res.a[1][1];
	ans[0]=add(ans[0],res.coef);
	// print(ans);
	for(int i=0;i<(int)ans.size();i++) Ans=add(Ans,mul(fac[i+1],ans[i]));
	cout<<Ans<<endl;
	return 0;
}