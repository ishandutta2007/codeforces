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
const int max_n=3e5+5;
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
bool vis[max_n],mark[max_n];
void dfs(int x,int fa)
{
	vis[x]=true;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			if(vis[y])
			{
				if(mark[x]&&mark[y])
					mark[x]=0;
			}
		}
	}
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			if(!vis[y])
			{
				mark[y]=mark[x]^1;
				dfs(y,x);
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
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			Last[i]=0;
		e=0;
		for(int i=1;i<=m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		for(int i=1;i<=n;++i)
			vis[i]=false;
		mark[1]=false;
		dfs(1,0);
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			puts("YES");
			int cnt=0;
			for(int i=1;i<=n;++i)
				cnt+=mark[i];
			printf("%d\n",cnt);
			for(int i=1;i<=n;++i)
			{
				if(mark[i])
					printf("%d ",i);
			}
			puts("");
			continue;
		}
		for(int i=1;i<=n;++i)
			vis[i]=false;
		mark[1]=true;
		dfs(1,0);
		flag=true;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			puts("YES");
			int cnt=0;
			for(int i=1;i<=n;++i)
				cnt+=mark[i];
			printf("%d\n",cnt);
			for(int i=1;i<=n;++i)
			{
				if(mark[i])
					printf("%d ",i);
			}
			puts("");
			continue;
		}
		puts("NO");
	}
	return 0;
}