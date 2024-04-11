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
const int max_n=2e3+5;
char Map[max_n][max_n];
vector<int> row[10],col[10];
int ans[10];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%s",Map[i]+1);
		for(int d=0;d<=9;++d)
		{
			row[d].clear();
			for(int i=1;i<=n;++i)
			{
				bool flag=false;
				for(int j=1;j<=n;++j)
					if(Map[i][j]-'0'==d)
					{
						flag=true;
						break;
					}
				if(flag)
					row[d].push_back(i);
			}
			col[d].clear();
			for(int j=1;j<=n;++j)
			{
				bool flag=false;
				for(int i=1;i<=n;++i)
				{
					if(Map[i][j]-'0'==d)
					{
						flag=true;
						break;
					}
				}
				if(flag)
					col[d].push_back(j);
			}
		}
		for(int d=0;d<=9;++d)
		{
			int ans=0;
			for(int i=1;i<=n;++i)
			{
				int l=0,r=0;
				for(int j=1;j<=n;++j)
				{
					if(Map[i][j]-'0'==d)
					{
						l=j;
						break;
					}
				}
				for(int j=n;j>=1;--j)
				{
					if(Map[i][j]-'0'==d)
					{
						r=j;
						break;
					}
				}
				if(l<r)
					ans=max(ans,(r-l)*max(i-1,n-i));
				if(l&&row[d].size())
					ans=max(ans,max(n-l,r-1)*max(i-row[d][0],row[d][int(row[d].size())-1]-i));
			}
			for(int j=1;j<=n;++j)
			{
				int l=0,r=0;
				for(int i=1;i<=n;++i)
				{
					if(Map[i][j]-'0'==d)
					{
						l=i;
						break;
					}
				}
				for(int i=n;i>=1;--i)
				{
					if(Map[i][j]-'0'==d)
					{
						r=i;
						break;
					}
				}
				if(l<r)
					ans=max(ans,(r-l)*max(j-1,n-j));
				if(l&&col[d].size())
					ans=max(ans,max(n-l,r-1)*max(j-col[d][0],col[d][int(col[d].size())-1]-j));
			}
			printf("%d%c",ans,d<9?' ':'\n');
		}
	}
	return 0;
}