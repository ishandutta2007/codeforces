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
#define N 10005
namespace Flow
{
	struct edge{
		int v,nxt;
		int w;
	}c[N*100];
	int front[N*10],edge_cnt;
	int cur[N*10],dep[N*10],S,T;
	int _q[N*10],_l,_r;
	int node_cnt;
	inline void add(int u,int v,int w)
	{
		c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;
		c[++edge_cnt]=(edge){u,front[v],0},front[v]=edge_cnt;
	}
	inline void init(){memset(front,255,sizeof(front)),edge_cnt=-1;}
	bool bfs()
	{
		memset(dep,255,(node_cnt+3)<<2);
		memcpy(cur,front,(node_cnt+3)<<2);
		dep[S]=0;
		_q[_l=_r=1]=S;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=front[x];~i;i=c[i].nxt)
			{
				if(c[i].w&&!~dep[c[i].v])
				{
					dep[c[i].v]=dep[x]+1;
					_q[++_r]=c[i].v;
				}
			}
		}
		return ~dep[T];
	}
	int dfs(int x,int flow)
	{
		if(x==T||!flow) return flow;
		int f=0,rf;
		for(int &i=cur[x];~i;i=c[i].nxt)
		{
			if(dep[c[i].v]==dep[x]+1&&(rf=dfs(c[i].v,min(flow,c[i].w))))
			{
				flow-=rf,f+=rf;
				c[i].w-=rf,c[i^1].w+=rf;
				if(!flow) return f;
			}
		}
		return f;
	}
	int dinic()
	{
		int ans=0;
		while(bfs()) ans+=dfs(S,inf);
		return ans;
	}
}
using namespace Flow;
int _cnt,n,Q;
int ls[N*4],rs[N*4],rt1,rt2;
void build1(int &u,int l,int r)
{
	if(l==r) {u=l; return ;}
	u=++_cnt;
	int mid=(l+r)/2;
	build1(ls[u],l,mid),build1(rs[u],mid+1,r);
	add(ls[u],u,10000),add(rs[u],u,10000);
}
void build2(int &u,int l,int r)
{
	if(l==r) {u=l+n; return ;}
	u=++_cnt;
	int mid=(l+r)/2;
	build2(ls[u],l,mid),build2(rs[u],mid+1,r);
	add(u,ls[u],10000),add(u,rs[u],10000);
}
void query1(int u,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		add(u,v,10000);
		return ;
	}
	int mid=(l+r)/2;
	if(mid>=L) query1(ls[u],l,mid,L,R,v);
	if(mid<R) query1(rs[u],mid+1,r,L,R,v);
}
void query2(int u,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R)
	{
		add(v,u,inf);
		return ;
	}
	int mid=(l+r)/2;
	if(mid>=L) query2(ls[u],l,mid,L,R,v);
	if(mid<R) query2(rs[u],mid+1,r,L,R,v);
}
int nxt[N],pre[N],cnt[N];
vector<pii> v1[N],v2[N];
void work(int x,int y)
{
	if(!nxt[y]) return ;
	int u=++_cnt;
	// printf("[%d %d] -> [%d %d]\n",pre[y],x-1,y,nxt[y]);
	query1(rt1,1,n,pre[y],x-1,u),query2(rt2,1,n,y,nxt[y],u);
	pre[y]=nxt[y]=0;
}
signed main()
{
	init();
	cin>>n>>Q;
	_cnt=n+n;
	build1(rt1,1,n),build2(rt2,1,n);
	while(Q--)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		v1[x1].eb(y1,y2),v2[x2+1].eb(y1,y2);
	}
	for(int i=1;i<=n;i++)
	{
		for(auto [a,b]:v1[i]) for(int j=a;j<=b;j++) cnt[j]++;
		for(auto [a,b]:v2[i]) for(int j=a;j<=b;j++) cnt[j]--;
		for(int j=1;j<=n;j++)
		{
			if(cnt[j]) work(i,j);
			else
			{
				int k=j;
				while(k<n&&!cnt[k+1]) k++;
				if(nxt[j]!=k)
				{
					work(i,j);
					nxt[j]=k,pre[j]=i;
				}
				for(int c=j+1;c<=k;c++) work(i,c);
				j=k;
			}
		}
	}
	for(int i=1;i<=n;i++) work(n+1,i);
	S=_cnt+1,T=_cnt+2; node_cnt=T;
	for(int i=1;i<=n;i++) add(S,i,1),add(i+n,T,1);
	// cout<<_cnt<<endl;
	// cout<<ss<<endl;
	// return 0;
	cout<<dinic()<<endl;
	return 0;
}