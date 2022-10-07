#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
namespace fastIO
{ 
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	bool IOerror=0;
	inline char nc()
	{
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend)
		{
			p1=buf;
			pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	inline void read(int &x)
	{
		bool sign=0;
		char ch=nc();
		x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
	}
	inline void read(ll &x)
	{
		bool sign=0;
		char ch=nc();
		x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
	}
	char ss[1000000*8],tt[20];
	int ssl,ttl;
	inline int Flush()
	{
		fwrite(ss+1,sizeof(char),ssl,stdout);
		ssl=0;
		return 0;
	}
	inline int print(int x)
	{
		if(!x)ss[++ssl]='0';
		for(ttl=0;x;x/=10)tt[++ttl]=char(x%10+'0');
		for(;ttl;ttl--)ss[++ssl]=tt[ttl];
		return ss[++ssl]='\n';
	}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
using namespace std;
const ll base=233,invb=844009174,MOD=998244353;
struct Edge
{
	int to;
	int nxt;
}e[600005];
int n,m,edgenum,head[300005],pa[300005],dep[300005],son[300005],len[300005],top[300005],anc[21][300005],digit[300005];
ll ha1[300005],ha2[300005],pwb[300005],pwi[300005];
vector<int>up[300005],down[300005];
char s[300005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	dep[node]=dep[pa[node]]+1;
	len[node]=1;
	ha1[node]=ha1[pa[node]]*base+s[node];
	ha2[node]=ha2[pa[node]]+pwb[dep[node]-1]*s[node];
	ha1[node]%=MOD;
	ha2[node]%=MOD;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		if(len[to]+1>len[node])
		{
			len[node]=len[to]+1;
			son[node]=to;
		}
	}
}
void dfs2(int node,int t)
{
	top[node]=t;
	if(son[node])dfs2(son[node],t);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||to==son[node])continue;
		dfs2(to,to);
	}
	if(son[pa[node]]!=node)
	{
		int u=node;
		for(int i=1;i<=len[node];i++)
		{
			down[node].push_back(u);
			u=son[u];
		}
		u=node;
		for(int i=1;i<=len[node];i++)
		{
			up[node].push_back(u);
			u=pa[u];
		}
	}
}
void pre()
{
	for(int i=1;i<=n;i++)anc[0][i]=pa[i];
	for(int i=1;i<=20;i++)
	  for(int j=1;j<=n;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
	for(int i=2;i<=n;i++)
	  digit[i]=digit[i>>1]+1;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=0;dep[u]-dep[v];i++)
	{
		if((1<<i)&(dep[u]-dep[v]))
		  u=anc[i][u];
	}
	if(u==v)return u;
	for(int i=18;i>=0;i--)
	  if(anc[i][u]!=anc[i][v])
	    u=anc[i][u],v=anc[i][v];
	return pa[u];
}
int kth(int node,int k)
{
	if(k==0)return node;
	node=anc[digit[k]][node];
	k&=(1<<digit[k])-1;
	if(k<=dep[node]-dep[top[node]])return down[top[node]][dep[node]-dep[top[node]]-k];
	else return up[top[node]][k-dep[node]+dep[top[node]]];
}
ll ask(int node,int to)
{
	if(dep[node]>dep[to])
	{
		to=pa[to];
		return (ha2[node]-ha2[to])*pwi[dep[to]];
	}
	else
	{
		node=pa[node];
		return ha1[to]-ha1[node]*pwb[dep[to]-dep[node]];
	}
}
ll ask(int u,int x,int lca,int v)
{
	if(u==lca)return ask(lca,v);
	if(v==lca)return ask(u,lca);
	ll v1=ask(u,x),v2=ask(lca,v);
	v1%=MOD;
	return v1*pwb[dep[v]-dep[lca]+1]+v2;
}
int a,b,c,d,x1,x2,l1,l2;
bool check(int l)
{
	if(l>dep[a]+dep[b]-dep[l1]*2+1)return 0;
	if(l>dep[c]+dep[d]-dep[l2]*2+1)return 0;
	ll v1=l>dep[a]-dep[l1]?ask(a,x1,l1,kth(b,dep[b]-dep[l1]-(l-dep[a]+dep[l1]-1))):ask(a,kth(a,l-1));
	ll v2=l>dep[c]-dep[l2]?ask(c,x2,l2,kth(d,dep[d]-dep[l2]-(l-dep[c]+dep[l2]-1))):ask(c,kth(c,l-1));
	v1%=MOD;
	if(v1<0)v1+=MOD;
	v2%=MOD;
	if(v2<0)v2+=MOD;
	return v1==v2;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	pwb[0]=pwi[0]=1;
	for(int i=1;i<=n;i++)
	{
		pwb[i]=pwb[i-1]*base;
		pwi[i]=pwi[i-1]*invb;
		pwb[i]%=MOD;
		pwi[i]%=MOD;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u),read(v);
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	dfs2(1,1);
	pre();
	read(m);
	while(m--)
	{
		read(a),read(b),read(c),read(d);
		l1=LCA(a,b),l2=LCA(c,d);
		x1=kth(a,max(0,dep[a]-dep[l1]-1)),x2=kth(c,max(0,dep[c]-dep[l2]-1));
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))l=mid+1;
			else r=mid-1;
		}
		print(r);
	}
	Flush();
	return 0;
}