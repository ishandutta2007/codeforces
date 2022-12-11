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
const int max_n=1e5+5;
int p[max_n],h[max_n];
vector<int> edge[max_n];
int f[max_n],cnt[max_n];
bool flag;
void dfs(int x,int fa)
{
	f[x]=-p[x];
	cnt[x]=p[x];
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs(y,x);
			if(!flag)
				return;
			f[x]+=f[y];
			cnt[x]+=cnt[y];
		}
	}
//	printf("f[x]=%d cnt[x]=%d\n",f[x],cnt[x]);
	if(f[x]>h[x]||(h[x]-f[x])%2||(h[x]-f[x])/2>cnt[x])
	{
//		printf("x=%d\n",x);
		flag=false;
		return;
	}
	cnt[x]-=(h[x]-f[x])/2;
	f[x]=h[x];
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
			scanf("%d",p+i);
		for(int i=1;i<=n;++i)
			scanf("%d",h+i);
		for(int i=1;i<=n;++i)
			edge[i].clear();
		for(int i=1;i<=n-1;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		flag=true;
		dfs(1,0);
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}