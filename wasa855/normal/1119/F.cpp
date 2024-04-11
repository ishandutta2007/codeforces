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
const ll lim=25000000000LL;
#define N 250005
struct Node
{
	int ls,rs,cnt;
	ll val;
};
Node t[N*32];
int cnt;
stack<int> s;
int New()
{
	if(s.empty()) return ++cnt;
	int x=s.top(); s.pop();
	return x;
}
void Del(int x)
{
	t[x].ls=t[x].rs=t[x].cnt=t[x].val=0;
	s.push(x);
}
void insert(int &u,ll l,ll r,ll pl,int v)
{
	if(!u) u=New();
	t[u].val+=pl*v,t[u].cnt+=v;
	if(l==r) return ;
	ll mid=(l+r)/2;
	if(pl<=mid) insert(t[u].ls,l,mid,pl,v);
	else insert(t[u].rs,mid+1,r,pl,v);
}
ll query(int u,ll l,ll r,int k)
{
	if(!k) return 0;
	// printf("%d %lld %lld %d\n",u,l,r,k);
	if(!u) return INF;
	if(k>t[u].cnt) return INF;
	if(l==r) return l*k;
	ll mid=(l+r)/2;
	if(t[t[u].ls].cnt>=k) return query(t[u].ls,l,mid,k);
	else return t[t[u].ls].val+query(t[u].rs,mid+1,r,k-t[t[u].ls].cnt);
}
void del(int u)
{
	if(!u) return ;
	if(t[u].ls) del(t[u].ls);
	if(t[u].rs) del(t[u].rs);
	Del(u);
}
int rt[N];
set<pii> G[N];
int dgr[N],n,vis[N];
int nd[N],X,bn[N];
vector<int> v[N];
ll f[N][2];
void dfs(int u,int fa,ll val)
{
	if(vis[u]==X) return ;
	vis[u]=X;
	for(auto [v,w]:G[u]) if(v!=fa) dfs(v,u,w);
	int cnt=dgr[u];
	ll sum=0;
	for(auto [v,w]:G[u])
	{
		// printf("** %d %d\n",v,w);
		if(v==fa||bn[v]) continue;
		if(f[v][1]<=f[v][0]) sum+=f[v][1],cnt--;
		else
		{
			sum+=f[v][0],insert(rt[u],1,lim,f[v][1]-f[v][0],1);
			assert(f[v][1]-f[v][0]<=lim);
		}
	}
	if(cnt<=X)
	{
		f[u][0]=sum;
		f[u][1]=sum+val;
	}
	else
	{
		f[u][0]=sum+query(rt[u],1,lim,cnt-X);
		f[u][1]=sum+query(rt[u],1,lim,cnt-X-1)+val;
	}
	for(auto [v,w]:G[u])
	{
		if(v==fa||bn[v]) continue;
		if(f[v][1]>f[v][0]) insert(rt[u],1,lim,f[v][1]-f[v][0],-1);
	}
}
signed main()
{
	// cout<<sizeof(t)/1024.0/1024.0<<endl;
	cin>>n;
	ll Sum=0;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		G[u].insert(mp(v,w)),G[v].insert(mp(u,w));
		dgr[u]++,dgr[v]++;
		Sum+=w;
	}
	for(int i=1;i<=n;i++) nd[i]=i;
	sort(nd+1,nd+n+1,[&](int x,int y){return dgr[x]<dgr[y];});
	printf("%lld ",Sum);
	int cur=0;
	// for(int i=1;i<=n;i++) printf("%d ",nd[i]); cout<<"\n";
	for(int i=1;i<n;i++)
	{
		X=i;
		// printf("-- %d\n",i);
		while(cur!=n&&dgr[nd[cur+1]]<=X)
		{
			// printf("++ %d\n",cur);
			cur++; bn[nd[cur]]=1;
			for(auto [v,w]:G[nd[cur]])
			{
				insert(rt[v],1,lim,w,1);
				G[v].erase(mp(nd[cur],w));
			}
			G[nd[cur]].clear();
			del(rt[nd[cur]]);
		}
		ll ans=0;
		for(int j=cur+1;j<=n;j++)
		{
			if(vis[nd[j]]!=X)
			{
				// printf("*** %d ",nd[j]);
				dfs(nd[j],0,INF);
				ans+=f[nd[j]][0];
			}
		}
		// cout<<"\n"<<i<<" :\n";
		// for(int j=1;j<=n;j++) printf("%d %d\n",f[j][0],f[j][1]);
		printf("%lld ",ans);
	}
	return 0;
}