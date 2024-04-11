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
const int max_n=1e3+5;
char Map[max_n][max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%s",Map[i]+1);
		bool flag=false;
		for(int i=1;i<=n&&!flag;++i)
			for(int j=i+1;j<=n;++j)
			{
				if(Map[i][j]==Map[j][i])
				{
					puts("YES");
					for(int k=1;k<=m+1;++k)
						printf("%d%c",k&1?i:j,k<=m?' ':'\n');
					flag=true;
					break;
				}
			}
		if(flag)
			continue;
		if(m&1)
		{
			puts("YES");
			for(int k=1;k<=m+1;++k)
				printf("%d%c",k&1?1:2,k<=m?' ':'\n');
		}
		else
		{
			int a=-1,b=-1,c=-1;
			for(int i=1;i<=n;++i)
			{
				int pa=-1,pb=-1;
				for(int j=1;j<=n;++j)
				{
					if(Map[i][j]=='a')
					{
						pa=j;
						break;
					}
				}
				for(int j=1;j<=n;++j)
				{
					if(Map[i][j]=='b')
					{
						pb=j;
						break;
					}
				}
				if(pa!=-1&&pb!=-1)
				{
					a=pb,b=i,c=pa;
					break;
				}
			}
			if(a==-1&&b==-1&&c==-1)
				puts("NO");
			else
			{
				puts("YES");
				if(m%4==2)
				{
					for(int k=1;k<=m+1;++k)
					{
						int ans;
						if(k%4==1)
							ans=a;
						else if(k%4==2)
							ans=b;
						else if(k%4==3)
							ans=c;
						else
							ans=b;
						printf("%d%c",ans,k<=m?' ':'\n');
					}
				}
				else
				{
					for(int k=1;k<=m+1;++k)
					{
						int ans;
						if(k%4==1)
							ans=b;
						else if(k%4==2)
							ans=c;
						else if(k%4==3)
							ans=b;
						else
							ans=a;
						printf("%d%c",ans,k<=m?' ':'\n');
					}
				}
			}
		}
	}
	return 0;
}