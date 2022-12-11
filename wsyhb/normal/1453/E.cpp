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
	int read_int()
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
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
}
int len_min[max_n],len_max[max_n];
void dfs1(int x,int fa)
{
	len_min[x]=1e9;
	len_max[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs1(y,x);
			len_min[x]=min(len_min[x],len_min[y]+1);
			len_max[x]=max(len_max[x],len_min[y]+1);
		}
	}
	if(len_min[x]==1e9)
		len_min[x]=1;
}
int ans;
bool vis[max_n];
void dfs2(int x,int fa)
{
	vis[x]=false;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs2(y,x);
			if(x!=1)
			{
				if(!vis[x]&&len_min[x]==len_min[y]+1)
					vis[x]=true;
				else
					ans=max(ans,len_min[y]+1);
			}
			else
			{
				if(!vis[x]&&len_max[x]==len_min[y]+1)
				{
					vis[x]=true;
					ans=max(ans,len_min[y]);
				}
				else
					ans=max(ans,len_min[y]+1);
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		e=0;
		for(int i=1;i<=n;++i)
			Last[i]=0;
		for(int i=1;i<=n-1;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		dfs1(1,0);
		ans=1;
		dfs2(1,0);
		printf("%d\n",ans);
	}
	return 0;
}