#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 2000005
int t[25][N/10],r[N];
int a[N],b[N];
int n,m;
int div2(int x){return x&1?(x+mod)>>1:x>>1;}
void fwt(int *a,int typ)
{
	for(int i=1;i<(1<<n);i<<=1)
	{
		for(int j=0;j<(1<<n);j+=(i<<1))
		{
			for(int k=0;k<i;k++)
			{
				int u=a[j+k],v=a[i+j+k];
				a[j+k]=add(u,v),a[i+j+k]=sub(u,v);
				if(typ==-1) a[j+k]=div2(a[j+k]),a[i+j+k]=div2(a[i+j+k]);
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%1d",&t[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[j][i]) r[i]|=(1<<(j-1));
		}
	}
	for(int i=1;i<=m;i++) a[r[i]]++;
	int lim=1<<n;
	for(int i=1;i<lim;i++) b[i]=b[i>>1]+(i&1);
	for(int i=1;i<lim;i++) if(b[lim-i-1]<b[i]) b[i]=b[lim-i-1];
	// for(int i=0;i<lim;i++) printf("%d ",a[i]); cout<<"\n";
	// for(int i=0;i<lim;i++) printf("%d ",b[i]); cout<<"\n";
	fwt(a,1),fwt(b,1);
	for(int i=0;i<lim;i++) a[i]=mul(a[i],b[i]);
	fwt(a,-1);
	int ans=inf;
	for(int i=0;i<lim;i++) if(a[i]<ans) ans=a[i];
	cout<<ans<<endl;
	return 0;
}