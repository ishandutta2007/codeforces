#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buffer_size=1e5+5;
	char buf[buffer_size],*S,*T;
	bool flag_EOF;
	inline char read_char()
	{
	    if(S==T)
			T=(S=buf)+fread(buf,1,buffer_size,stdin);
	    return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
	    int flag=1;
	    char c=read_char();
	    while(c<'0'||c>'9')
	    {
	        if(c==EOF)
	        {
	            flag_EOF=true;
	            return 0;
	        }
	        flag=(c=='-'?-1:1);
	        c=read_char();
	    }
	    int x=0;
	    while(c>='0'&&c<='9')
	    {
	        x=x*10+(c^48);
	        c=read_char();
	    }
	    return x*flag;
	}
	char st[13];
	int _top;
	void Write(int x)
	{
		if(!x)
		{
			putchar('0');
			return;
		}
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		while(x)
		{
			st[++_top]=x%10+'0';
			x/=10;
		}
		while(_top>0)
			putchar(st[_top--]);
	}
}
const int max_n=2e5+5;
long long a[max_n];
int b[max_n];
vector<int> edge[max_n];
long long sum[max_n];
bool mark[max_n];
void dfs(int x,int fa)
{
	sum[x]=a[x];
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs(y,x);
			if(sum[y]<=0)
				mark[y]=true;
			else
				sum[x]+=sum[y];
		}
	}
}
int root[max_n];
vector<int> node[max_n];
void dfs2(int x,int fa)
{
	if(!fa)
		root[x]=x;
	else
		root[x]=root[fa];
	node[root[x]].push_back(x);
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa&&!mark[y])
			dfs2(y,x);
	}
}
vector<int> e[max_n];
int d[max_n];
inline void add_edge(int x,int y)
{
	e[x].push_back(y);
	++d[y];
}
queue<int> q;
vector<int> p;
long long ans;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",b+i);
		if(b[i]!=-1)
			edge[b[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)
	{
		if(b[i]==-1)
			dfs(i,0);
	}
	for(int i=1;i<=n;++i)
	{
		if(b[i]==-1||mark[i])
			dfs2(i,0);
	}
	for(int i=1;i<=n;++i)
	{
		if(b[i]!=-1)
		{
			if(mark[i])
			{
				int x=root[b[i]];
				for(int k=0;k<int(node[i].size());++k)
					add_edge(x,node[i][k]);
			}
			else
				add_edge(i,b[i]);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!d[i])
			q.push(i);
	}
	while(q.size())
	{
		int x=q.front();
		q.pop();
		p.push_back(x);
		for(int i=0;i<int(e[x].size());++i)
		{
			int y=e[x][i];
			--d[y];
			if(!d[y])
				q.push(y);
		}
	}
	for(int k=0;k<n;++k)
	{
		int i=p[k];
		ans+=a[i];
		if(b[i]!=-1)
			a[b[i]]+=a[i];
	}
	printf("%lld\n",ans);
	for(int i=0;i<n;++i)
		printf("%d%c",p[i],i+1<n?' ':'\n');
	return 0;
}