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
int Inv(int x){return qpow(x,mod-2);}
#define N 1000005
int a[N],cnt[N],val[N],n;
int fac[N],inv[N],ifac[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
void work()
{
	n=read(); for(int i=1;i<=n;i++) cnt[i]=val[i]=0;
	for(int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;
	int m=0;
	for(int i=1;i<=n;i++) if(cnt[i]) a[++m]=cnt[i];
	int g=0; for(int i=1;i<=m;i++) g=__gcd(g,a[i]);
	for(int i=1;i<=n;i++) val[__gcd(n,i)]++;
	int ans=0;
	if(m==1) {printf("1\n"); return ;}
	int tmp=0;
	for(int i=1;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=m;i++) cnt[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(g%(n/i)==0&&val[i])
		{
			int v=n/i,res=0;
			int prd=fac[i-2];
			// for(int j=1;j<=m;j++) prd=mul(prd,ifac[a[j]/v]);
			for(int k=g;k<=n;k+=g) prd=mul(prd,qpow(ifac[k/v],cnt[k]));
			for(int k=g;k<=n;k+=g) if(k/v>=2)
			{
				int tmp=mul(prd,fac[k/v],ifac[k/v-2]);
				res=add(res,mul(tmp,cnt[k]));
			}
			res=mul(res,n);
			ans=add(ans,mul(val[i],res));
			tmp=add(tmp,mul(prd,mul(i,i-1),val[i]));
		}
	}
	// printf("^ %d %d\n",ans,tmp);
	ans=mul(ans,Inv(tmp));
	printf("%d\n",sub(n,ans));
}
signed main()
{
	init();
	int T=read(); while(T--) work();
	return 0;
}