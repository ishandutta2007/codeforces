#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 80
int a[N],b[N],id[N];
int f[N][N],fr[N][N];
bool c[N];
void work()
{
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return b[x]<b[y];});
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) f[i][j]=-inf;
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) fr[i][j]=0;
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(f[i-1][j]!=-inf) f[i][j]=f[i-1][j]+b[id[i]]*(k-1);
			if(j!=0&&f[i-1][j-1]!=-inf)
			{
				int R=f[i-1][j-1]+b[id[i]]*(j-1)+a[id[i]];
				if(R>f[i][j]) f[i][j]=R,fr[i][j]=1;
			}
		}
	}
	int cur=k;
	for(int i=n;i>=1;i--)
	{
		if(fr[i][cur]) c[i]=1,cur--;
		else c[i]=0;
	}
	// for(int i=1;i<=n;i++) printf("%d ",c[i]); cout<<"\n";
	cout<<n+n-k<<endl;
	int cnt=0,las=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i])
		{
			cnt++;
			if(cnt==k) {las=i; break;}
			printf("%d ",id[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!c[i]) printf("%d -%d ",id[i],id[i]);
	}
	cout<<id[las]<<"\n";
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}