#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buf_size=1<<22;
	char buf[buf_size],*S,*T;
	inline char read_char()
	{
		if(S==T)
			T=(S=buf)+fread(buf,1,buf_size,stdin);
		return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
		char c;
		do
			c=read_char();
		while(c<'0'||c>'9');
		int x=0;
		while(c>='0'&&c<='9')
		{
			x=x*10+(c^48);
			c=read_char();
		}
		return x;
	}
}
int n,q;
const int max_n=3e5+5;
const int max_q=4e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],Len[max_n<<1],e=1;
inline void add_edge(int x,int y,int z1,int z2)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e,Len[e]=z1;
	End[++e]=x,Next[e]=Last[y],Last[y]=e,Len[e]=z2;
}
int a[max_n],U[max_q],V[max_q];
int fath[max_n],dep[max_n],sz[max_n],son[max_n],edge[max_n];
void dfs1(int x,int fa)
{
	fath[x]=fa;
	dep[x]=dep[fa]+1;
	sz[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			edge[y]=i;
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]])
				son[x]=y;
		}
	}
}
int top[max_n];
void dfs2(int x,int top_now)
{
	top[x]=top_now;
	if(son[x])
		dfs2(son[x],top_now);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fath[x]&&y!=son[x])
			dfs2(y,y);
	}
}
inline int get_LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fath[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
long long dp_in[max_n],dp_out[max_n];
void dfs3(int x,int fa)
{
	dp_in[x]=a[x];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs3(y,x);
			long long v=dp_in[y]-Len[i]-Len[i^1];
			if(v>0)
				dp_in[x]+=v;
		}
	}
}
void dfs4(int x,int fa)
{
	if(fa)
	{
		dp_out[x]=dp_in[fa];
		long long v=dp_in[x]-Len[edge[x]]-Len[edge[x]^1];
		if(v>0)
			dp_out[x]-=v;
		v=dp_out[fa]-Len[edge[fa]]-Len[edge[fa]^1];
		if(v>0)
			dp_out[x]+=v;
	}
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs4(y,x);
	}
}
long long s1[max_n],s2[max_n],s3[max_n],s4[max_n];
void dfs5(int x,int fa)
{
	s1[x]=s1[fa]+dp_in[x];
	s2[x]=s2[fa];
	long long v=dp_in[x]-Len[edge[x]]-Len[edge[x]^1];
	if(v>0)
		s2[x]-=v;
	s3[x]=s3[fa]+Len[edge[x]];
	s4[x]=s4[fa]+Len[edge[x]^1];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs5(y,x);
	}
}
inline void solve()
{
	dfs3(1,0),dfs4(1,0),dfs5(1,0);
	for(int t=1;t<=q;++t)
	{
		int u=U[t],v=V[t],p=get_LCA(u,v);
		long long ans=s1[u]-s1[fath[p]]+s1[v]-s1[p];
		ans+=s2[u]-s2[p]+s2[v]-s2[p];
		long long val=dp_out[p]-Len[edge[p]]-Len[edge[p]^1];
		if(val>0)
			ans+=val;
		ans-=s4[u]-s4[p];
		ans-=s3[v]-s3[p];
		printf("%lld\n",ans);
	}
}
int main()
{
	n=IO::read_int(),q=IO::read_int();
	for(int i=1;i<=n;++i)
		a[i]=IO::read_int();
	for(int i=1;i<=n-1;++i)
	{
		int x=IO::read_int(),y=IO::read_int(),z=IO::read_int();
		add_edge(x,y,z,z);
	}
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=q;++i)
		U[i]=IO::read_int(),V[i]=IO::read_int();
	solve();
	return 0;
}