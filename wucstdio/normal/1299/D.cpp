#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[200005];
struct Ji
{
	int v[5];
	bool flag;
	int&operator[](int i){return v[i];}
	void ins(int x)
	{
		for(int i=4;i>=0;i--)
		  if(x&(1<<i))x^=v[i];
		if(!x)
		{
			flag=1;
			return;
		}
		for(int i=4;i>=0;i--)
		{
			if(x&(1<<i))
			{
				v[i]=x;
				for(int j=4;j>i;j--)
				  if(v[j]&(1<<i))
				    v[j]^=v[i];
				break;
			}
		}
	}
}base[100005],base2[100005];
int n,m,tot,edgenum,head[100005],dep[100005],val[100005];
int fa[100005],pa[100005],in[100005];
bool vis[100005];
vector<Ji>pos;
ll f[33][17][9][5][3],g[33][17][9][5][3];
bool flag[33][17][9][5][3];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	vis[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||vis[to])continue;
		if(to==1)continue;
		pa[to]=node;
		val[to]=val[node]^e[hd].len;
		dep[to]=dep[node]+1;
		dfs1(to);
	}
}
void dfs2(int node,Ji&b)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(pa[to]==node)dfs2(to,b);
		else if(dep[to]>dep[node])
		{
			b.ins(e[hd].len^val[to]^val[node]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
		if(u!=1&&v!=1)
		{
			u=find(u),v=find(v);
			if(u!=v)fa[v]=u;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(find(i)==i)
		{
			in[i]=++tot;
			dfs1(i);
			dfs2(i,base[tot]);
		}
	}
	memset(vis,0,sizeof(vis));
	dfs1(1);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=tot;i++)base2[i]=base[i];
	for(int hd=head[1];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(pa[to]!=1)base2[in[find(to)]].ins(val[to]^e[hd].len),vis[in[find(to)]]=1;
	}
	f[0][0][0][0][0]=1;
	flag[0][0][0][0][0]=1;
	Ji st;
	st.v[0]=st.v[1]=st.v[2]=st.v[3]=st.v[4]=st.flag=0;
	pos.push_back(st);
	for(int i=1;i<=tot;i++)
	{
//		printf("%d:%d\n",i,vis[i]);
//		for(int j=4;j>=0;j--)printf("%d ",base[i][j]);
//		printf("\n");
//		if(vis[i])
//		{
//			for(int j=4;j>=0;j--)printf("%d ",base2[i][j]);
//			printf("\n");
//		}
		for(auto now:pos)
		{
			ll v=f[now[4]][now[3]][now[2]][now[1]][now[0]];
			g[now[4]][now[3]][now[2]][now[1]][now[0]]+=v;
			if(!vis[i])
			{
				st=now;
				st.flag|=base[i].flag;
				for(int j=0;j<5;j++)
				  if(base[i][j])
				    st.ins(base[i][j]);
				if(!st.flag)
				{
					if(!flag[st[4]][st[3]][st[2]][st[1]][st[0]])pos.push_back(st);
					g[st[4]][st[3]][st[2]][st[1]][st[0]]+=v;
					flag[st[4]][st[3]][st[2]][st[1]][st[0]]=1;
				}
			}
			else
			{
				st=now;
				st.flag|=base[i].flag;
				for(int j=0;j<5;j++)
				  if(base[i][j])
				    st.ins(base[i][j]);
				if(!st.flag)
				{
					if(!flag[st[4]][st[3]][st[2]][st[1]][st[0]])pos.push_back(st);
					g[st[4]][st[3]][st[2]][st[1]][st[0]]+=2*v;
					flag[st[4]][st[3]][st[2]][st[1]][st[0]]=1;
				}
				st=now;
				st.flag|=base2[i].flag;
				for(int j=0;j<5;j++)
				  if(base2[i][j])
				    st.ins(base2[i][j]);
				if(!st.flag)
				{
					if(!flag[st[4]][st[3]][st[2]][st[1]][st[0]])pos.push_back(st);
					g[st[4]][st[3]][st[2]][st[1]][st[0]]+=v;
					flag[st[4]][st[3]][st[2]][st[1]][st[0]]=1;
				}
			}
		}
		for(auto now:pos)
		{
			ll v=g[now[4]][now[3]][now[2]][now[1]][now[0]]%MOD;
			f[now[4]][now[3]][now[2]][now[1]][now[0]]=v;
			g[now[4]][now[3]][now[2]][now[1]][now[0]]=0;
		}
	}
	ll ans=0;
	for(auto now:pos)
		ans+=f[now[4]][now[3]][now[2]][now[1]][now[0]];
	printf("%lld\n",ans%MOD);
	return 0;
}