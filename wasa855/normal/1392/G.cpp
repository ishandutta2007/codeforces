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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
#define N (1<<20)
int a[N],b[N],l[N],r[N],n,m,k;
int v1[N],v2[N];
int f[N],g[N],p[N],rev[N],t[N];
int getv(int a[])
{
	int ans=0;
	for(int i=1;i<=k;i++) t[i]=a[p[i]];
	for(int i=1;i<=k;i++) if(t[i]) ans|=(1<<(i-1));
	return ans;
}
void doit(int x,int y)
{
	int A=p[x],B=p[y];
	swap(p[x],p[y]),swap(rev[A],rev[B]);
}
signed main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) a[i]=rdchar()-'0';
	for(int i=1;i<=k;i++) b[i]=rdchar()-'0';
	for(int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	
	for(int i=1;i<=k;i++) p[i]=i,rev[i]=i;
	for(int i=1;i<=n;i++) doit(l[i],r[i]);
	// for(int i=1;i<=k;i++) printf("%d%c",p[i]," \n"[i==k]);
	for(int i=1;i<=n;i++)
	{
		v1[i]=getv(a);
		int x=rev[l[i]],y=rev[r[i]];
		doit(x,y);
		// for(int i=1;i<=k;i++) printf("%d%c",p[i]," \n"[i==k]);
	}
	// for(int i=1;i<=n;i++) printf("%d%c",v1[i]," \n"[i==n]);
	
	for(int i=1;i<=k;i++) p[i]=i,rev[i]=i;
	for(int i=1;i<=n;i++) doit(l[i],r[i]);
	for(int i=1;i<=n;i++)
	{
		int x=rev[l[i]],y=rev[r[i]];
		doit(x,y);
		// for(int i=1;i<=k;i++) printf("%d%c",p[i]," \n"[i==k]);
		v2[i]=getv(b);
	}
	
	// for(int i=1;i<=n;i++) printf("%d%c",v2[i]," \n"[i==n]);
	for(int i=0;i<1<<k;i++) f[i]=inf;
	for(int i=1;i<=n;i++) f[v1[i]]=min(f[v1[i]],i);
	for(int i=1;i<=n;i++) g[v2[i]]=i;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<1<<k;j++)
		{
			if(!(j>>i&1)) f[j]=min(f[j],f[j^(1<<i)]);
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<1<<k;j++)
		{
			if(!(j>>i&1)) g[j]=max(g[j],g[j^(1<<i)]);
		}
	}
	int ans=0,al=1,ar=n;
	for(int i=0;i<1<<k;i++)
	{
		if(g[i]-f[i]+1>=m)
		{
			if(__builtin_popcount(i)>ans)
			{
				ans=__builtin_popcount(i);
				al=f[i],ar=g[i];
			}
		}
	}
	int c1=0,c2=0;
	for(int i=1;i<=k;i++) if(a[i]) c1++;
	for(int i=1;i<=k;i++) if(b[i]) c2++;
	cout<<ans*2+k-c1-c2<<endl;
	printf("%d %d\n",al,ar);
	return 0;
}