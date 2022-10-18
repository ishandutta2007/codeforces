#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
#define pb push_back
#define mp make_pair
#define ls (u<<1)
#define rs (u<<1|1)
int n,q,s;
int tin[N<<2],tout[N<<2];
vector<pair<int,int> > e[N<<2];
int cnt;
void add(int u,int v,int w){e[u].pb(mp(v,w));}
void build(int u,int l,int r)
{
	if(l==r)
	{
		tin[u]=l,tout[u]=l;
		return ;
	}
	tin[u]=++cnt;
	tout[u]=++cnt;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	add(tin[u],tin[ls],0);
	add(tout[ls],tout[u],0);
	add(tin[u],tin[rs],0);
	add(tout[rs],tout[u],0);
}
void updin(int u,int l,int r,int L,int R,int p,int w)
{
	if(L<=l&&r<=R)
	{
		add(p,tin[u],w);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=L) updin(ls,l,mid,L,R,p,w);
	if(mid<R) updin(rs,mid+1,r,L,R,p,w);
}
void updout(int u,int l,int r,int L,int R,int p,int w)
{
	if(L<=l&&r<=R)
	{
		add(tout[u],p,w);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=L) updout(ls,l,mid,L,R,p,w);
	if(mid<R) updout(rs,mid+1,r,L,R,p,w);
}
struct Node
{
	int num,dat;
	bool operator < (const Node &x) const
	{
		return dat>x.dat;
	}
};
int dis[N<<2];
void dijkstra()
{
	for(int i=1;i<=cnt;i++)
	{
		dis[i]=INF;
	}
	dis[s]=0;
	priority_queue<Node> q;
	q.push((Node){s,0});
	while(!q.empty())
	{
		Node u=q.top();
		q.pop();
		if(u.dat!=dis[u.num]) continue;
		int t=u.num;
		int ss=e[t].size();
		for(int i=0;i<ss;i++)
		{
			int to=e[t][i].first;
			if(dis[t]+e[t][i].second<dis[to])
			{
				dis[to]=dis[t]+e[t][i].second;
				q.push((Node){to,dis[to]});
			}
		}
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>q>>s;
	cnt=n;
	build(1,1,n);
//	cout<<"Passed\n";
	int opt,v,l,r,w;
	for(int i=1;i<=q;i++)
	{
		opt=read();
		if(opt==1)
		{
			l=read(),r=read(),w=read();
			add(l,r,w);
		}
		if(opt==2)
		{
			v=read(),l=read(),r=read(),w=read();
			updin(1,1,n,l,r,v,w);
		}
		if(opt==3)
		{
			v=read(),l=read(),r=read(),w=read();
			updout(1,1,n,l,r,v,w);
		}
//		cout<<"passed "<<i<<endl;
	}
//	cout<<"Passed\n";
	dijkstra();
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==INF) printf("-1 ");
		else printf("%lld ",dis[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}