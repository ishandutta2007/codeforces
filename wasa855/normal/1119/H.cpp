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
inline int add(int a,int b,int c,int d){return add(a,b,add(c,d));};
inline int mul(int a,int b,int c,int d){return mul(a,b,mul(c,d));};
inline int add(int a,int b,int c,int d,int e){return add(a,b,c,add(d,e));}
inline int mul(int a,int b,int c,int d,int e){return mul(a,b,c,mul(d,e));}
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
int Inv(int x){return qpow(x,mod-2);}
const int i2=Inv(2),i4=Inv(4);
#define N (1<<17)
int f1[N],f2[N],f3[N],n,k,x,y,z,a[N],b[N],c[N],sum;
int ans[N];
void fwt(int a[],int B)
{
	for(int i=1;i<1<<B;i<<=1) for(int j=0;j<1<<B;j+=(i<<1)) for(int k=0;k<i;k++)
	{
		int x=a[j+k],y=a[i+j+k];
		a[j+k]=add(x,y),a[i+j+k]=sub(x,y);
	}
}
void ifwt(int a[],int B)
{
	fwt(a,B); int I=Inv(1<<B);
	for(int i=0;i<1<<B;i++) a[i]=mul(a[i],I);
}
signed main()
{
	cin>>n>>k>>x>>y>>z;
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		sum^=a[i]; b[i]^=a[i],c[i]^=a[i];
		f1[b[i]]++,f2[c[i]]++,f3[b[i]^c[i]]++;
	}
	fwt(f1,k),fwt(f2,k),fwt(f3,k);
	for(int i=0;i<1<<k;i++)
	{
		int c0=mul(add(n,f1[i],f2[i],f3[i]),i4);
		int c1=mul(add(sub(n,c0),sub(f1[i],c0)),i2);
		int c2=mul(add(sub(n,c0),sub(f2[i],c0)),i2);
		int c3=mul(add(sub(n,c0),sub(f3[i],c0)),i2);
		int w0=add(x,y,z),w1=sub(add(x,y),z),w2=sub(add(x,z),y),w3=sub(x,add(y,z));
		ans[i]=mul(qpow(w0,c0),qpow(w1,c1),qpow(w2,c2),qpow(w3,c3));
	}
	ifwt(ans,k);
	for(int i=0;i<1<<k;i++) printf("%d%c",ans[i^sum]," \n"[i==(1<<k)-1]);
	return 0;
}