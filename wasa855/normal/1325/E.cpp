#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1000005
int a[N],n;
pii b[N];
vector<int> G[N];
int ans=N;
int dis[N],fa[N];
pii init(int x)
{
	vector<int> R;
	for(int i=2;i*i<=x;i++)
	{
		while(x%(i*i)==0) x/=(i*i);
		if(x%i==0) R.pb(i),x/=i;
	}
	if(x!=1) R.pb(x);
	if(R.size()==0) return mp(1,1);
	if(R.size()==1) return mp(R[0],1);
	if(R.size()==2) return mp(R[0],R[1]);
}
void bfs(int u)
{
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	queue<int> q; q.push(u);
	while(!q.empty())
	{
		int x=q.front(); q.pop();
		for(int v:G[x])
		{
			if(dis[v]>dis[x]+1)
			{
				dis[v]=dis[x]+1;
				fa[v]=x;
				q.push(v);
			}
			// printf("%d %d %d %d %d %d\n",u,v,dis[u],dis[v],fa[u],fa[v]);
			if(dis[x]+dis[v]+1<ans&&!(fa[x]==v||fa[v]==x)) ans=dis[x]+dis[v]+1;
		}
	}
	// cout<<"Passed\n";
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		b[i]=init(read());
		a[i]=b[i].fir*b[i].sec;
	}
	sort(a+1,a+n+1);
	if(a[1]==1)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			cout<<2<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		// printf("%d %d\n",b[i].fir,b[i].sec);
		G[b[i].fir].pb(b[i].sec);
		G[b[i].sec].pb(b[i].fir);
	}
	for(int i=1;i<=1000;i++)
	{
		if(G[i].size()) bfs(i);
	}
	if(ans>=N) cout<<"-1\n";
	else cout<<ans<<endl;
	return 0;
}