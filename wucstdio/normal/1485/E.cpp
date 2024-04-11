#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
struct Data
{
	int id;
	ll val;
	ll f;
}a[200005];
struct Edge
{
	int to;
	int nxt;
}e[400005];
int t,n,edgenum,tot,pa[200005],head[200005],dep[200005];
ll v[200005],f[200005],pre[200005],suf[200005];
vector<int>s[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int maxd;
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	maxd=max(maxd,dep[node]);
	s[dep[node]].push_back(node);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
	}
}
bool cmp(Data a,Data b)
{
	return a.val<b.val;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=2;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			add(i,x);
			add(x,i);
		}
		for(int i=2;i<=n;i++)scanf("%lld",&v[i]);
		dfs(1);
		tot=0;
		for(auto x:s[maxd])
		{
			a[++tot].f=0;
			a[tot].val=v[x];
			a[tot].id=x;
		}
		sort(a+1,a+tot+1,cmp);
		pre[0]=suf[tot+1]=-2147483647;
		for(int i=1;i<=tot;i++)
			pre[i]=max(pre[i-1],a[i].f-a[i].val);
		for(int i=tot;i>=1;i--)
			suf[i]=max(suf[i+1],a[i].f+a[i].val);
		for(int i=maxd-1;i>=1;i--)
		{
			ll minn=2147483647,maxx=0;
			for(auto x:s[i+1])
			{
				minn=min(minn,v[x]);
				maxx=max(maxx,v[x]);
			}
			for(auto x:s[i])
			{
				f[x]=0;
				ll mn=2147483647,mx=0;
				for(int hd=head[x];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					if(to==pa[x])continue;
					f[x]=max(f[x],f[to]+max(maxx-v[to],v[to]-minn));
					mx=max(mx,v[to]);
					mn=min(mn,v[to]);
				}
				for(int hd=head[x];hd;hd=e[hd].nxt)
				{
					int l=1,r=tot;
					while(l<=r)
					{
						int mid=(l+r)/2;
						if(a[mid].val<=(mx+mn)/2)l=mid+1;
						else r=mid-1;
					}
					f[x]=max(f[x],max(pre[r]+mx,suf[l]-mn));
				}
			}
			tot=0;
			for(auto x:s[i])
			{
				a[++tot].f=f[x];
				a[tot].val=v[x];
				a[tot].id=x;
			}
			sort(a+1,a+tot+1,cmp);
			pre[0]=suf[tot+1]=-2147483647;
			for(int i=1;i<=tot;i++)
				pre[i]=max(pre[i-1],a[i].f-a[i].val);
			for(int i=tot;i>=1;i--)
				suf[i]=max(suf[i+1],a[i].f+a[i].val);
		}
		printf("%lld\n",f[1]);
		for(int i=1;i<=maxd;i++)s[i].clear();
		for(int i=1;i<=n;i++)f[i]=head[i]=pa[i]=dep[i]=0;
		edgenum=0;
		maxd=0;
	}
	return 0;
}