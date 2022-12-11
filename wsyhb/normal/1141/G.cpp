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
int End[max_n<<1],Last[max_n],Next[max_n<<1],id[max_n<<1],d[max_n],e;
inline void add_edge(int x,int y,int k)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	id[e]=k;
	++d[y];
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
	id[e]=k;
	++d[x];
}
int pos[max_n];
bool cmp(int x,int y)
{
	return d[x]>d[y];
}
int c[max_n];
bool mark[max_n];
typedef pair<int,int> P;
map<P,bool> vis;
int col_now[max_n];
void dfs(int x,int fa)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		int now=id[i];
		if(y!=fa)
		{
			if(mark[x])
			{
				c[now]=1;
				vis[P(y,1)]=true;
			}
			else
			{
				while(vis[P(x,col_now[x])])
					++col_now[x];
				vis[P(x,col_now[x])]=true;
				vis[P(y,col_now[x])]=true;
				c[now]=col_now[x]++;
			}
			dfs(y,x);
		}
	}
}
int main()
{
	int n=IO::read_int(),k=IO::read_int();
	for(int i=1;i<=n-1;++i)
	{
		int x=IO::read_int(),y=IO::read_int();
		add_edge(x,y,i);
	}
	for(int i=1;i<=n;++i)
		pos[i]=i;
	sort(pos+1,pos+n+1,cmp);
	int ans=d[pos[k+1]];
	for(int i=1;i<=k;++i)
		mark[pos[i]]=true;
	for(int i=1;i<=n;++i)
		col_now[i]=1;
	dfs(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=n-1;++i)
		printf("%d%c",c[i],i<n-1?' ':'\n');
	return 0;
}