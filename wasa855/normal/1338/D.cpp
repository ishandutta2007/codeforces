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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
vector<int> G[N];
bool cmp(int x,int y){return x>y;}
int f[N][3],dep[N],maxd[N],n,ans; // not choose , choose 
// 
void dfs(int u,int fa)
{
	int maxn=0,cnt=0;
	vector<int> a,b,c;
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u); cnt++;
		a.pb(f[v][0]);
		b.pb(f[v][1]);
		c.pb(max(f[v][0],f[v][1]));
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	sort(c.begin(),c.end(),cmp);
	if(a.size()==0)
	{
		f[u][1]=1; return ;
	}
	if(a.size()==1)
	{
		f[u][1]=1+a[0];
		f[u][0]=max(a[0],b[0]);
		return ;
	}
	if(u==1)
	{
		int R=cnt-2+c[0]+c[1];
		if(R>ans) ans=R;
		R=a[0]+a[1]+1;
		if(R>ans) ans=R;
		f[u][0]=cnt-1+c[0];
		f[u][1]=1+a[0];
	}
	else
	{
		int R=cnt-1+c[0]+c[1];
		if(R>ans) ans=R;
		R=a[0]+a[1]+1;
		if(R>ans) ans=R;
		f[u][0]=cnt-1+c[0];
		f[u][1]=1+a[0];
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	cout<<max(ans,max(f[1][0],f[1][1]))<<endl;
	return 0;
}