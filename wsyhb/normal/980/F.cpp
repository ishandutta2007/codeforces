#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buf_size=1<<20;
    char buf[buf_size],*S,*T;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buf_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        char c=read_char();
        bool neg=false;
        while(c<'0'||c>'9')
        {
            neg=(c=='-');
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^'0');
            c=read_char();
        }
        return neg?-x:x;
    }
    char fw[buf_size];
    int pw;
    inline void flush()
    {
        fwrite(fw,1,pw,stdout);
        pw=0;
    }
    inline void write_char(char x)
    {
        fw[pw++]=x;
        if(pw==buf_size)
            flush();
    }
    inline void write_int(int x)
    {
        if(!x)
        {
            write_char('0');
            return;
        }
        if(x<0)
        {
            write_char('-');
            x=-x;
        }
        static char st[26];
        int tp=0;
        while(x)
        {
            st[++tp]=x%10^'0';
            x/=10;
        }
        while(tp>0)
            write_char(st[tp--]);
    }
}
const int max_n=5e5+5;
const int max_m=1e6+5;
int End[max_m<<1],Last[max_n],Next[max_m<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
int dfn[max_n],low[max_n],Time,st[max_n],tp,bel[max_n],tot;
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++Time;
	st[++tp]=x;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			if(!dfn[y])
			{
				tarjan(y,x);
				low[x]=min(low[x],low[y]);
			}
			else
				low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x])
	{
		++tot;
		while(!bel[x])
			bel[st[tp--]]=tot;
	}
}
bool vis[max_n];
vector<int> edge[max_n],node[max_n];
int dis[max_n],f[max_n],que[max_n],head,tail,pre[max_n],suf[max_n],pref[max_n],suff[max_n];
void dfs1(int x,int fa)
{
	int k=bel[x];
	for(vector<int>::iterator it=node[k].begin();it!=node[k].end();++it)
	{
		int u=*it;
		for(int i=0;i<int(edge[u].size());++i)
		{
			int v=edge[u][i];
			if(v!=fa)
			{
				dfs1(v,u);
				pref[v]=dis[u];
				dis[u]=max(dis[u],f[v]+1);
			}
		}
		dis[u]=0;
		for(int i=int(edge[u].size())-1;i>=0;--i)
		{
			int v=edge[u][i];
			if(v!=fa)
			{
				suff[v]=dis[u];
				dis[u]=max(dis[u],f[v]+1);
			}
		}
	}
	int L=node[k].size();
	head=1,tail=0;
	for(int x=0;x<L;++x)
	{
		int u=node[k][x];
		while(head<=tail&&x-que[head]>L/2)
			++head;
		while(head<=tail&&dis[node[k][que[tail]]]-que[tail]<=dis[u]-x)
			--tail;
		que[++tail]=x;
		f[u]=(dis[node[k][que[head]]]-que[head])+x;
		if(x-L/2-1>=0)
			f[u]=max(f[u],pre[x-L/2-1]+(L-x));
		if(x-1>=0)
			pre[x]=pre[x-1];
		else
			pre[x]=-1e9;
		pre[x]=max(pre[x],dis[u]+x);
	}
	head=1,tail=0;
	for(int x=L-1;x>=0;--x)
	{
		int u=node[k][x];
		while(head<=tail&&que[head]-x>L/2)
			++head;
		while(head<=tail&&dis[node[k][que[tail]]]+que[tail]<=dis[u]+x)
			--tail;
		que[++tail]=x;
		f[u]=max(f[u],(dis[node[k][que[head]]]+que[head])-x);
		if(x+L/2+1<L)
			f[u]=max(f[u],suf[x+L/2+1]+(L+x));
		if(x+1<L)
			suf[x]=suf[x+1];
		else
			suf[x]=-1e9;
		suf[x]=max(suf[x],dis[u]-x);
	}
}
int g[max_n];
void dfs2(int x,int fa)
{
	int k=bel[x],L=node[k].size(),pos=-1;
	for(int i=0;i<L;++i)
	{
		if(node[k][i]==x)
		{
			pos=i;
			break;
		}
	}
	if(fa)
		g[x]=max(g[fa],max(pref[x],suff[x]))+1;
	assert(pos!=-1);
	for(int i=0;i<L;++i)
	{
		int d=i>=pos?i-pos:pos-i;
		g[node[k][i]]=g[x]+min(d,L-d);
	}
//	if(k==3)
//		fprintf(stderr,"g[6]=%d\n",g[6]);
	head=1,tail=0;
	for(int x=0;x<L;++x)
	{
		int u=node[k][x];
		while(head<=tail&&x-que[head]>L/2)
			++head;
		if(head<=tail)
			g[u]=max(g[u],(dis[node[k][que[head]]]-que[head])+x);
		if(x-L/2-1>=0)
			g[u]=max(g[u],pre[x-L/2-1]+(L-x));
		if(x-1>=0)
			pre[x]=pre[x-1];
		else
			pre[x]=-1e9;
		pre[x]=max(pre[x],dis[u]+x);
		while(head<=tail&&dis[node[k][que[tail]]]-que[tail]<=dis[u]-x)
			--tail;
		que[++tail]=x;
	}
	head=1,tail=0;
	for(int x=L-1;x>=0;--x)
	{
		int u=node[k][x];
		while(head<=tail&&que[head]-x>L/2)
			++head;
		if(head<=tail)
			g[u]=max(g[u],(dis[node[k][que[head]]]+que[head])-x);
		if(x+L/2+1<L)
			g[u]=max(g[u],suf[x+L/2+1]+(L+x));
		if(x+1<L)
			suf[x]=suf[x+1];
		else
			suf[x]=-1e9;
		suf[x]=max(suf[x],dis[u]-x);
		while(head<=tail&&dis[node[k][que[tail]]]+que[tail]<=dis[u]+x)
			--tail;
		que[++tail]=x;
	}
	for(vector<int>::iterator it=node[k].begin();it!=node[k].end();++it)
	{
		int u=*it;
		for(int i=0;i<int(edge[u].size());++i)
		{
			int v=edge[u][i];
			if(v!=fa)
				dfs2(v,u);
		}
	}
}
int main()
{
//	freopen("cac.in","r",stdin);
//	freopen("cac.out","w",stdout);
	int n=IO::read_int(),m=IO::read_int();
	for(int i=1;i<=m;++i)
	{
		int x=IO::read_int(),y=IO::read_int();
		add_edge(x,y);
	}
	tarjan(1,0);
	assert(tp==0);
	for(int i=1;i<=n;++i)
	{
		if(vis[i])
			continue;
		int k=bel[i],x=i;
//		fprintf(stderr,"k=%d\n",k);
		while(!vis[x])
		{
			node[k].push_back(x);
//			fprintf(stderr,"%d ",x);
			vis[x]=true;
			for(int j=Last[x];j;j=Next[j])
			{
				int y=End[j];
				if(!vis[y]&&bel[y]==k)
				{
					x=y;
					break; 
				}
			}
		}
//		fprintf(stderr,"\n");
	}
	for(int x=1;x<=n;++x)
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(bel[x]!=bel[y])
				edge[x].push_back(y);
		}
	dfs1(1,0);
//	for(int i=1;i<=n;++i)
//		fprintf(stderr,"i=%d f[i]=%d\n",i,f[i]);
	dfs2(1,0);
//	for(int i=1;i<=n;++i)
//		fprintf(stderr,"i=%d g[i]=%d\n",i,g[i]);
	for(int i=1;i<=n;++i)
	{
		IO::write_int(max(f[i],g[i]));
		IO::write_char(i<n?' ':'\n');
	}
	IO::flush();
	return 0;
}
/*
9 9
1 4
2 3
4 3
3 5
5 6
5 7
6 7
7 8
8 9
---
6 5 4 5 3 4 4 5 6
*/
/*
10 11
8 9
9 6
6 8
5 3
3 4
4 1
1 5
9 4
8 7
2 10
1 2
---
4 5 4 3 5 5 6 5 4 6
*/