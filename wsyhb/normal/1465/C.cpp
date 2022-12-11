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
const int max_m=1e5+5;
int x[max_m],y[max_m];
const int max_n=1e5+5;
int id1[max_n],id2[max_n];
int ans;
void solve(int i)
{
	if(x[i]==y[i])
		return;
	if(!id1[y[i]])
	{
		id1[x[i]]=0;
		id1[y[i]]=i;
		x[i]=y[i];
		++ans;
		if(id2[x[i]])
			solve(id2[x[i]]);
	}
	else if(!id2[x[i]])
	{
		id2[y[i]]=0;
		id2[x[i]]=i;
		y[i]=x[i];
		++ans;
		if(id1[y[i]])
			solve(id1[y[i]]);
	}
}
int f[max_n],sz[max_n];
int get_fa(int x)
{
	return f[x]!=x?f[x]=get_fa(f[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		f[x]=y;
		sz[y]+=sz[x];
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
			id1[i]=id2[i]=0;
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",x+i,y+i);
			id1[x[i]]=i,id2[y[i]]=i;
		}
		ans=0;
		for(int T=1;T<=1000;++T) 
			for(int i=1;i<=m;++i)
				solve(i);
		for(int i=1;i<=m;++i)
		{
			if(x[i]!=y[i])
				++ans;
		}
		for(int i=1;i<=n;++i)
			f[i]=i,sz[i]=1;
		for(int i=1;i<=m;++i)
			merge(x[i],y[i]);
		for(int i=1;i<=n;++i)
		{
			get_fa(i);
			if(f[i]==i&&sz[i]>1)
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}