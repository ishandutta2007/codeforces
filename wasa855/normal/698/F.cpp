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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 1000005
int fac[N],a[N],n;
int pr[N],vis[N],cnt;
void sieve()
{
	for(int i=2;i<N;i++)
	{
		if(!vis[i]) pr[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(i*pr[j]>=N) break;
			vis[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
}
int c(int x)
{
	if(x==1) return 1;
	return n/x;
}
vector<int> d[N];
int c1[N],c2[N],qwq[N];
int a1[N],a2[N];
signed main()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	sieve();
	for(int i=1;i<=cnt;i++)
	{
		int u=pr[i];
		for(int j=u;j<=n;j+=u) d[j].pb(u);
	}
	d[1].pb(1);
	for(int i=1;i<=cnt;i++) c2[c(pr[i])]++;
	c2[1]++;
	for(int i=1;i<=n;i++)
	{
		qwq[i]=1;
		for(int v:d[i]) qwq[i]*=v;
	}
	for(int i=1;i<=n;i++) c1[qwq[i]]++;
//	for(int i=1;i<=n;i++) printf("%d%c",c1[i]," \n"[i==n]);
//	for(int i=1;i<=n;i++) printf("%d%c",c2[i]," \n"[i==n]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=0) continue;
		int u=d[a[i]].back(),v=d[i].back();
		if(c(u)!=c(v)) cout<<"0\n",exit(0);
		c1[qwq[a[i]]]--;
		if(a1[u]&&a1[u]!=v) cout<<"0\n",exit(0);
		if(a2[v]&&a2[v]!=u) cout<<"0\n",exit(0);
		c2[c(u)]-=!a1[u]&&!a2[v];
		a1[u]=v,a2[v]=u;
	}
//	for(int i=1;i<=n;i++) printf("%d%c",c1[i]," \n"[i==n]);
//	for(int i=1;i<=n;i++) printf("%d%c",c2[i]," \n"[i==n]);
	int ans=1;
	for(int i=1;i<=n;i++) ans=mul(ans,fac[c1[i]],fac[c2[i]]);
	cout<<ans<<endl;
	return 0;
}