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
#define N 300005
int a[N];
int pr[N],vis[N],mu[N],cnt;
void sieve()
{
	mu[1]=1; int n=N-5;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) mu[i]=-1,pr[++cnt]=i;
		for(int j=1;j<=cnt&&i*pr[j]<=n;j++)
		{
			vis[i*pr[j]]=1;
			if(i%pr[j]==0) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	// for(int i=1;i<=n;i++) if(mu[i]<0) mu[i]+=mod;
}
namespace getval
{
	int f[N],g[N],tf[N],tg[N],th[N],h[N];
	void trans(int m)
	{
		for(int i=1;i<=m;i++) tf[i]=tg[i]=0;
		for(int i=1;i<=m;i++) for(int j=i;j<=m;j+=i) tf[i]=add(tf[i],f[j]);
		for(int i=1;i<=m;i++) for(int j=i;j<=m;j+=i) tg[i]=add(tg[i],g[j]);
		for(int i=1;i<=m;i++) th[i]=mul(tf[i],tg[i]),h[i]=0;
		for(int i=1;i<=m;i++) for(int j=i;j<=m;j+=i)
		{
			if(mu[j/i]==1) h[i]=add(h[i],th[j]);
			else if(mu[j/i]==-1) h[i]=sub(h[i],th[j]);
		}
		// for(int i=1;i<=m;i++) printf("%d%c",mu[i]," \n"[i==m]);
		// for(int i=1;i<=m;i++) printf("%d%c",th[i]," \n"[i==m]);
		// for(int i=1;i<=m;i++) printf("%d%c",h[i]," \n"[i==m]);
	}
	int Main(int n)
	{
		int maxn=0; for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		for(int i=1;i<=maxn;i++) f[i]=0;
		int m=maxn;
		for(int i=1;i<=n;i++) f[a[i]]++,g[a[i]]++;
		if(g[1]) return 1;
		for(int i=2;i<=7;i++)
		{
			trans(m);
			if(h[1]) return i;
			for(int j=1;j<=m;j++) g[j]=h[j];
		}
		return -1;
	}
};
signed main()
{
	int n=read(),g=0; sieve();
	for(int i=1;i<=n;i++) a[i]=read(),g=__gcd(g,a[i]);
	cout<<getval::Main(n)<<endl;
	return 0;
}