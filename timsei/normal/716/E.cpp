using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#define N 100005
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
#define ll long long
#define int ll
ll inv[N];
ll n,m,cnt,tot,dis[N],S[N];
ll ne[N*2],to[N*2],C[N*2],fir[N],Max[N],now;
ll ans,x,y,z;
map<ll,ll>M1;
map<ll,ll>M2;
bool vis[N];
ll depth[N];
bool flag;
int d;
int root;
vector<int>son,val;
ll fire[N];
void add(ll x,ll y,ll z)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;C[cnt]=z;
}
void getsize(ll x,ll f)
{
	S[x]=1;Max[x]=0;
	forw(i,x)
	{
		ll V=to[i];
		if(!vis[V]&&V!=f) 
		{
			getsize(V,x);
			S[x]+=S[V];
			Max[x]=max(Max[x],S[V]);
		}
	}
}
void getroot(ll x,ll f)
{
	Max[x]=max(Max[x],tot-S[x]);if(Max[x]<now){now=Max[x];root=x;}
	forw(i,x)
	{
		int V=to[i];
		if(!vis[V]&&V!=f)getroot(V,x);
	}
}
void dfs1(int x,int f,int now,int deep)
{
	if(flag&&!now) ans++;
	M1[now]++;
	forw(i,x)
	{
		if(!vis[to[i]]&&to[i]!=f)
		{
			dfs1(to[i],x,(C[i]*fire[deep]+now)%m,deep+1);
		}
	}
}
void dfs2(int x,int f,int now,int deep)
{
	if(flag&&!now) ans++;
//	cout<<x<<" "<<f<<" "<<now<<" "<<deep<<endl;
	ll LONDON_BRIDGE=(m+(((ll)m-now)%m*inv[deep]))%m;
	if(M1.count(LONDON_BRIDGE)) ans+=M1[LONDON_BRIDGE];
	forw(i,x)
	{
		if(!vis[to[i]]&&to[i]!=f)
		{
			dfs2(to[i],x,(C[i]+now*10)%m,deep+1);
		}
	}
}
void calc(int x)
{
	son.clear();
	flag=0;
	M1.clear();
	val.clear();
	forw(i,x)
	{
		int V=to[i];
		if(!vis[V])
		{
			son.push_back(to[i]);
			val.push_back(C[i]);
			dfs2(to[i],-1,C[i]%m,1);
			dfs1(to[i],-1,C[i]%m,1);
		}
	}
	M1.clear();
	flag=1;
	int hh=son.size();
	for(int i=hh-1;i>=0;i--)
	{
		dfs2(son[i],-1,val[i]%m,1);
		dfs1(son[i],-1,val[i]%m,1);
	}
}
void doit(ll x)
{
	getsize(x,-1);
	root=0;now=2e9;tot=S[x];
	getroot(x,-1);
	vis[root]=1;
	calc(root);
	forw(i,root)
	{
		if(!vis[to[i]])
		{
			doit(to[i]);
		}
	}
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;y=0;
		return ;
	}
	exgcd(b,a%b,x,y);
	ll xx=x,yy=y;
	x=yy;y=(xx-(a/b)*yy);
}
ll po[20001];
main()
{
	cin>>n>>m;
	if(m==1)
	{
		ans=(n*(n-1));
		cout<<ans<<endl;return 0;
	}
	for(ll i=1;i<=n-1;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	inv[0]=1;fire[0]=1;
	for(int i=1;i<=100004;i++)
	{
		fire[i]=(fire[i-1]*10)%m;
		exgcd(fire[i],m,x,y);
		inv[i]=(x%m+m)%m;
	}
	doit(0);
	cout<<ans<<endl;
}