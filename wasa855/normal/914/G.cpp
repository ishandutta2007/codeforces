#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
inline void div2(int &x)
{
	if(x&1) x=(x+mod)>>1;
	else x>>=1;
}
#define N 200005
int cnt[N],fi[N];
int a[N],b[N],c[N],t[N],x[N],h[N],n=17;
int f[18][N];
void fwt_or(int a[],int typ)
{
	for(int i=1;i<(1<<n);i<<=1)
	{
		for(int j=0;j<(1<<n);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				if(typ==1) a[i+j+k]=add(a[i+j+k],a[j+k]);
				else a[i+j+k]=sub(a[i+j+k],a[j+k]);
			}
		}
	}
}
void fwt_xor(int a[],int typ)
{
	for(int i=1;i<(1<<n);i<<=1)
	{
		for(int j=0;j<(1<<n);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				int x=a[j+k],y=a[i+j+k];
				a[j+k]=add(x,y),a[i+j+k]=sub(x,y);
				if(typ==-1) div2(a[i+j+k]),div2(a[j+k]);
			}
		}
	}
}
void fwt_and(int a[],int typ)
{
	for(int i=1;i<(1<<n);i<<=1)
	{
		for(int j=0;j<(1<<n);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				if(typ==1) a[k+j]=add(a[i+j+k],a[j+k]);
				else a[k+j]=sub(a[j+k],a[i+j+k]);
			}
		}
	}
}
void solve()
{
	for(int i=0;i<(1<<n);i++) f[cnt[i]][i]=x[i];
	// for(int i=0;i<n;i++)
	// {
		// for(int j=0;j<(1<<n);j++) printf("%d ",f[i][j]);
		// cout<<"\n";
	// }
	for(int i=0;i<=n;i++) fwt_or(f[i],1);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<(1<<n);j++) h[j]=0;
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<(1<<n);k++) h[k]=add(h[k],mul(f[j][k],f[i-j][k]));
		}
		fwt_or(h,-1);
		for(int j=0;j<(1<<n);j++) if(cnt[j]==i) a[j]=add(a[j],h[j]);
	}
}
signed main()
{
	int k=read();
	// if(k>2) return 0;
	for(int i=1;i<=k;i++) t[read()]++;
	for(int i=0;i<(1<<n);i++) cnt[i]=__builtin_popcount(i);
	// cout<<cnt[(1<<n)-1]<<endl;
	fi[1]=1; for(int i=2;i<(1<<n);i++) fi[i]=add(fi[i-1],fi[i-2]);
	for(int i=0;i<(1<<n);i++) x[i]=t[i];
	solve();
	for(int i=0;i<(1<<n);i++) a[i]=mul(a[i],fi[i]);
	for(int i=0;i<(1<<n);i++) b[i]=mul(t[i],fi[i]);
	for(int i=0;i<(1<<n);i++) x[i]=t[i];
	fwt_xor(x,1);
	for(int i=0;i<(1<<n);i++) x[i]=mul(x[i],x[i]);
	fwt_xor(x,-1);
	for(int i=0;i<(1<<n);i++) c[i]=mul(x[i],fi[i]);
	fwt_and(a,1); fwt_and(b,1); fwt_and(c,1);
	for(int i=0;i<(1<<n);i++) a[i]=mul(a[i],b[i],c[i]);
	fwt_and(a,-1);
	// for(int i=0;i<(1<<n);i++) printf("%d ",a[i]); cout<<"\n";
	int ans=0;
	for(int i=0;i<=n;i++) ans=add(ans,a[1<<i]);
	cout<<ans<<endl;
	return 0;
}