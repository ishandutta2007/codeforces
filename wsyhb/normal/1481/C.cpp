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
int a[max_n],b[max_n];
int p[max_n];
vector<int> id[max_n];
const int max_m=1e5+5;
int c[max_m],ans[max_m];
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
			p[i]=0;
			id[i].clear();
		}
		for(int i=1;i<=m;++i)
			ans[i]=0;
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",b+i);
			p[b[i]]=i;
			if(a[i]!=b[i])
				id[b[i]].push_back(i);
		}
		for(int i=1;i<=m;++i)
		{
			scanf("%d",c+i);
			if(id[c[i]].size())
			{
				ans[i]=id[c[i]].back();
				id[c[i]].pop_back();
			}
		}
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			if(id[i].size())
			{
				flag=false;
				break;
			}
		}
		if(!flag)
		{
			puts("NO");
			continue; 
		}
		int pos=0;
		for(int i=m;i>=1;--i)
		{
			if(ans[i])
				pos=ans[i];
			else
			{
				if(p[c[i]])
					pos=ans[i]=p[c[i]];
				else
				{
					if(!pos)
					{
						flag=false;
						break;
					}
					ans[i]=pos;
				}
			} 
		}
		if(flag)
		{
			puts("YES");
			for(int i=1;i<=m;++i)
				printf("%d%c",ans[i],i<n?' ':'\n');
		}
		else
			puts("NO");
	}
	return 0;
}