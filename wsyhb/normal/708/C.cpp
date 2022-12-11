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
int n;
const int N=4e5+5;
vector<int> edge[N];
int size[N],max_size[N],max_son[N];
void dfs_init(int x,int fa)
{
	size[x]=1;
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs_init(y,x);
			size[x]+=size[y];
		}
	}
}
void dfs1(int x,int fa)
{
	max_size[x]=n-size[x]<=(n>>1)?n-size[x]:max_size[fa];
	max_size[x]=max(max_size[x],max_son[fa]);
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs1(y,x);
			max_son[x]=max(max_son[x],size[y]<=(n>>1)?size[y]:max_son[y]);
		}
	}
}
void dfs2(int x,int fa)
{
	max_son[x]=0;
	max_size[x]=max(max_size[x],max_size[fa]);
	max_size[x]=max(max_size[x],max_son[fa]);
	for(int i=int(edge[x].size())-1;i>=0;i--)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs2(y,x);
			max_son[x]=max(max_son[x],size[y]<=(n>>1)?size[y]:max_son[y]);
		}
	}
}
int ans[N];
void dfs(int x,int fa)
{
	if(n-size[x]>(n>>1)&&n-size[x]-max_size[x]>(n>>1)) ans[x]=-1;
	max_son[x]=0;
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs(y,x);
			max_son[x]=max(max_son[x],size[y]<=(n>>1)?size[y]:max_son[y]);
			if(size[y]>(n>>1)&&size[y]-max_son[y]>(n>>1)) ans[x]=-1;
		}
	}
}
int main()
{
	n=read_int();
	for(int i=1;i<n;i++)
	{
		int x=read_int(),y=read_int();
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs_init(1,0);
	dfs1(1,0);
	dfs2(1,0);
	dfs(1,0);
	for(int i=1;i<=n;i++) printf("%d%c",ans[i]+1,i<n?' ':'\n');
	return 0;
}