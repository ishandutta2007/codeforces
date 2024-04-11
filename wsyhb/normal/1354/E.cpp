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
	inline void Write(int x)
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
int n,m,n1,n2,n3;
const int max_n=5e3+5;
const int max_m=1e5+5;
int End[max_m<<1],Last[max_n],Next[max_m<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
}
bool vis[max_n];
int num[max_n];
void dfs(int x)
{
	vis[x]=true;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(!vis[y])
		{
			num[y]=num[x]^1;
			dfs(y);
		}
		else if(num[x]==num[y])
		{
			puts("NO");
			exit(0);
		}
	}
}
int id_now;
int cnt[max_n][2];
void work(int x)
{
	vis[x]=true;
	++cnt[id_now][num[x]];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(!vis[y])
			work(y);
	}
}
bool f[max_n][max_n];
int Size[max_n][max_n];
vector<int> node;
int flag;
int col[max_n];
void solve(int x)
{
	vis[x]=true;
	if((num[x]^flag)==0)
		col[x]=2;
	else
	{
		if(n1>0)
		{
			col[x]=1;
			--n1;
		}
		else
		{
			col[x]=3;
			--n3;
		}
	}
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(!vis[y])
			solve(y);
	}
}
int main()
{
	n=IO::read_int(),m=IO::read_int(),n1=IO::read_int(),n2=IO::read_int(),n3=IO::read_int();
	for(int i=1;i<=m;++i)
	{
		int u=IO::read_int(),v=IO::read_int();
		add_edge(u,v);
	}
	node.push_back(0);
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			dfs(i);
			node.push_back(i);
		}
	}
	int Cnt=int(node.size())-1;
	for(int i=1;i<=n;++i)
		vis[i]=false;
	f[0][0]=true;
	for(int k=1;k<=Cnt;++k)
	{
		int i=node[k];
		id_now=k;
		work(i);
		for(int j=n;j>=0;--j)
		{
			if(j>=cnt[k][0]&&f[k-1][j-cnt[k][0]])
				f[k][j]=true,Size[k][j]=cnt[k][0];
			else if(j>=cnt[k][1]&&f[k-1][j-cnt[k][1]])
				f[k][j]=true,Size[k][j]=cnt[k][1];
		}
	}
	if(!f[Cnt][n2])
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;++i)
		vis[i]=false;
	int now=n2;
	for(int k=Cnt;k>=1;--k)
	{
		int i=node[k];
		if(Size[k][now]==cnt[k][0])
			flag=0;
		else
			flag=1;
		solve(i);
		now-=Size[k][now];
	}
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d",col[i]);
	printf("\n");
	return 0;
}