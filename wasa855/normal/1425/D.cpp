// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=2005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
const int MAXN=N;
ll fac[MAXN],inv[MAXN],ifac[MAXN];
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<MAXN;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		ifac[i]=ifac[i-1]*inv[i]%mod;
	}
}
inline ll C(int n,int m)
{
	if(n<m||m<0) return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int x[N],y[N],val[N];
int X1[N],Y1[N],X2[N],Y2[N];
int sum[N][N];
inline int Query(int x1,int y1,int x2,int y2)
{
	if(x1>x2||y1>y2) return 0;
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
	init();
	int n,m,R;read(n,m,R);
	for(int i=1;i<=n;++i)
	{
		read(x[i],y[i],val[i]);
		++sum[x[i]][y[i]];
		X1[i]=max(1,x[i]-R);
		Y1[i]=max(1,y[i]-R);
		X2[i]=min(1000,x[i]+R);
		Y2[i]=min(1000,y[i]+R);
	}
	for(int i=1;i<=1000;++i) for(int j=1;j<=1000;++j) sum[i][j]+=sum[i-1][j];
	for(int i=1;i<=1000;++i) for(int j=1;j<=1000;++j) sum[i][j]+=sum[i][j-1];
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			int x1=max(X1[i],X1[j]);
			int y1=max(Y1[i],Y1[j]);
			int x2=min(X2[i],X2[j]);
			int y2=min(Y2[i],Y2[j]);
			int s=Query(x1,y1,x2,y2);
			int a=Query(X1[i],Y1[i],X2[i],Y2[i])-s;
			int b=Query(X1[j],Y1[j],X2[j],Y2[j])-s;
			ll v=1ll*val[i]*val[j]%mod;
			add(ans,1ll*v*((C(n,m)-C(n-s-b,m)-C(n-s-a,m)+C(n-s-a-b,m)+mod+mod)%mod)%mod);
		}
	}
	add(ans,ans);
	for(int i=1;i<=n;++i)
	{
		ll v=1ll*val[i]*val[i]%mod;
		int s=Query(X1[i],Y1[i],X2[i],Y2[i]);
		add(ans,1ll*v*(C(n,m)-C(n-s,m)+mod)%mod);
	}
	printf("%d\n",ans);
	return 0;
}