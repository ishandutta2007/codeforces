#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
inline char read_char()
{
    if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
    return S!=T?*(S++):EOF;
}
inline int read_int()
{
    bool flag=false;
    char c=read_char();
    while(c<'0'||c>'9')
    {
        flag=(c=='-'?true:flag);
        c=read_char();
    }
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=read_char();
    }
    return flag?-x:x;
}
int n;
const int max_n=1e5+5;
vector<int> edge[max_n];
int size[max_n],fath[max_n];
vector<int> g;
void dfs_find_g(int x,int fa)
{
	fath[x]=fa;
	size[x]=1;
	int max_size=0;
	for(int i=0;i<edge[x].size();++i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs_find_g(y,x);
			size[x]+=size[y];
			max_size=max(max_size,size[y]);
		}
	}
	max_size=max(max_size,n-size[x]);
	if(max_size<=(n>>1)) g.push_back(x);
}
int ans;
void dfs(int x,int fa)
{
	fath[x]=fa;
	if(x==g[1]) return;
	for(int i=0;i<edge[x].size();++i)
	{
		int y=edge[x][i];
		if(y!=fa) dfs(y,x);
	}
	if(fa&&edge[x].size()==1) ans=x;
}
int main()
{
	int t=read_int();
	while(t--)
	{
		n=read_int();
		for(int i=1;i<=n;++i)
			edge[i].clear();
		for(int i=1;i<n;++i)
		{
			int x=read_int(),y=read_int();
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		g.clear();
		dfs_find_g(1,0);
		if(g.size()==1)
		{
			printf("%d %d\n",2,fath[2]);
			printf("%d %d\n",2,fath[2]);
		}
		else
		{
			dfs(g[0],0);
			printf("%d %d\n",ans,fath[ans]);
			printf("%d %d\n",ans,g[1]);
		}
	}
	return 0;
}