#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
char buffer[100001],*S,*T;
inline char read_char()
{
	if(S==T)
	{
		T=(S=buffer)+fread(buffer,1,100001,stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline int read_int()
{
	int s=0;
	bool flag=false;
	char c=read_char();
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=true;
		c=read_char();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+(c-'0');
		c=read_char();
	}
	return flag?-s:s;
}
const int N=2e5+5;
const int M=2e5+5;
int w[N];
int End[M<<1],Last[N],Next[M<<1],Len[M<<1];
int e;
void addedge(int x,int y,int z)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	Len[e]=z;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
	Len[e]=z;
}
int f,g;
double c=1e25,sum;
int size[N];
bool vis[N];
void dfs_find_g(int x,int fa,int n)
{
	size[x]=1;
	int max_size=0;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(!vis[y]&&y!=fa)
		{
			dfs_find_g(y,x,n);
			size[x]+=size[y];
			max_size=max(max_size,size[y]); 
		}
	}
	max_size=max(max_size,n-size[x]);
	g=max_size<=n>>1?x:g; 
}
double d[N];
void dfs(int x,int fa,int root,int dis)
{
	double s=sqrt(dis);
	sum+=w[x]*s*dis;
	d[root]+=w[x]*1.5*s;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa) dfs(y,x,root,dis+Len[i]);
	}
}
void solve(int x,int n)
{
	dfs_find_g(x,0,n);
	int u=g;
	vis[u]=true;
	sum=0;
	double tot=0;
	for(int i=Last[u];i;i=Next[i])
	{
		int v=End[i];
		d[v]=0;
		dfs(v,u,v,Len[i]);
		tot+=d[v];
	}
	if(sum<c) f=u,c=sum;
	for(int i=Last[u];i;i=Next[i])
	{
		int v=End[i];
		if(vis[v]||tot-2*d[v]>=0) continue;
		solve(v,size[v]<size[u]?size[v]:n-size[u]);
		break;
	}
}
int main()
{
	int n=read_int();
	for(int i=1;i<=n;i++) w[i]=read_int();
	for(int i=1;i<n;i++)
	{
		int a=read_int(),b=read_int(),l=read_int();
		addedge(a,b,l); 
	}
	solve(1,n);
	printf("%d %.8lf",f,c);
	return 0;
}