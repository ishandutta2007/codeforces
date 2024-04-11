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
const int max_n=5e5+5;
vector<int> edge[max_n];
int t[max_n],pos[max_n],now[max_n];
bool cmp(int x,int y)
{
	return t[x]<t[y];
}
bool vis[max_n];
int st[max_n],_top;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",t+i);
		pos[i]=i;
	}
	sort(pos+1,pos+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		int x=pos[i];
		for(int j=0;j<int(edge[x].size());++j)
		{
			int y=edge[x][j];
			if(now[y]!=0&&!vis[now[y]])
			{
				vis[now[y]]=true;
				st[++_top]=now[y];
			}
		}
		for(int j=1;j<=n;++j)
		{
			if(!vis[j])
			{
				now[x]=j;
				break;
			}
		}
		while(_top>0)
			vis[st[_top--]]=false;
		if(now[x]!=t[x])
		{
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d%c",pos[i],i<n?' ':'\n');
	return 0;
}