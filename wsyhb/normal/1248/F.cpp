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
const int max_n=1e6+5;
vector<int> edge[max_n];
int dfn[max_n],low[max_n],Time;
bool mark_st[max_n];
int st[max_n],_top;
vector<int> node[max_n];
int belong[max_n],scc,d[max_n];
void tarjan(int x)
{
	dfn[x]=low[x]=++Time;
	st[++_top]=x;
	mark_st[x]=true;
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(mark_st[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]>=dfn[x])
	{
		++scc;
		do
		{
			node[scc].push_back(st[_top]);
			belong[st[_top]]=scc;
			mark_st[st[_top--]]=false;
		}while(st[_top+1]!=x);
	}
}
bool ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			edge[i].clear();
			dfn[i]=low[i]=0;
			node[i].clear();
			d[i]=0;
			belong[i]=0;
			ans[i]=true;
		}
		scc=0,Time=0;
		for(int i=1;i<=m;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
		}
		for(int i=1;i<=n;++i)
		{
			if(!dfn[i])
				tarjan(i);
		}
		if(scc==1)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		for(int x=1;x<=n;++x)
		{
			for(int i=0;i<int(edge[x].size());++i)
			{
				int y=edge[x][i];
				if(belong[x]!=belong[y])
					++d[belong[x]];
			}
		}
		int res=0;
		for(int i=1;i<=scc;++i)
		{
			if(!d[i])
			{
				res=i;
				break;
			}
		}
		printf("%d %d\n",(int)node[res].size(),n-int(node[res].size()));
		for(int i=0;i<int(node[res].size());++i)
		{
			printf("%d%c",node[res][i],i+1<int(node[res].size())?' ':'\n');
			ans[node[res][i]]=false;
		}
		for(int i=1;i<=n;++i)
		{
			if(ans[i])
				printf("%d ",i);
		}
		puts("");
	}
	return 0;
}