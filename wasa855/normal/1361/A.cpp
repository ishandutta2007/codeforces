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
#define N 500005
vector<int> G[N];
int a[N],u[N],v[N];
int mex(vector<int> v)
{
	vector<bool> vis(v.size()+5);
	for(int i:v)
	{
		if(i<=v.size()+2) vis[i]=1;
	}
	for(int i=1;i<(int)vis.size();i++)
	{
		if(!vis[i]) return i;
	}
	return -1;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;i++) u[i]=read(),v[i]=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) G[u[i]].pb(a[v[i]]),G[v[i]].pb(a[u[i]]);
	for(int i=1;i<=n;i++)
	{
		if(mex(G[i])!=a[i]) {cout<<"-1\n"; return 0;}
	}
	vector<pii> b(n);
	for(int i=1;i<=n;i++) b[i-1]=mp(a[i],i);
	sort(b.begin(),b.end());
	for(pii i:b) printf("%d ",i.sec);
	return 0;
}