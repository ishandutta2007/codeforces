#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
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
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline void div2(int &x)
{
	if(x&1) x=(x+mod)>>1;
	else x>>=1;
}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 300005
int n,m,mid,l;
int b[40],siz;
void insert(int x)
{
	for(int i=m;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(b[i]) x^=b[i];
			else
			{
				b[i]=x; siz++;
				return ;
			}
		}
	}
}
int popcnt(int x){return __builtin_popcountll(x);}
int f[20][N],g[N],ans[N];
void dfs1(int dep,int sum)
{
	if(dep==mid)
	{
		g[sum]++; return ;
	}
	dfs1(dep+1,sum);
	if(b[dep]) dfs1(dep+1,sum^b[dep]);
}
void dfs2(int dep,int sum)
{
	if(dep==35)
	{
		f[popcnt(sum>>l)][sum&((1<<l)-1)]++; return ;
	}
	dfs2(dep+1,sum);
	if(b[dep]) dfs2(dep+1,sum^b[dep]);
}
void fwt(int a[],int typ)
{
	for(int i=1;i<(1<<l);i<<=1)
	{
		for(int j=0;j<(1<<l);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				int x=a[j+k],y=a[i+j+k];
				a[j+k]=add(x,y),a[i+j+k]=sub(x,y);
				if(typ==-1) div2(a[j+k]),div2(a[i+j+k]);
			}
		}
	}
}
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
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) insert(read());
	mid=(m+1)/2; l=max(mid,m-mid);
	dfs1(0,0); dfs2(mid,0);
	fwt(g,1);
	for(int i=0;i<=l;i++)
	{
		fwt(f[i],1);
		for(int j=0;j<(1<<l);j++) f[i][j]=mul(f[i][j],g[j]);
		fwt(f[i],-1);
		for(int j=0;j<(1<<l);j++) ans[popcnt(j)+i]=add(ans[popcnt(j)+i],f[i][j]);
	}
	int qaq=qpow(2,n-siz);
	for(int i=0;i<=m;i++) printf("%lld ",mul(qaq,ans[i]));
	return 0;
}