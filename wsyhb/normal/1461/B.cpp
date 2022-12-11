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
const int max_n=500+5;
char Map[max_n][max_n];
int l[max_n][max_n],r[max_n][max_n];
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
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if(Map[i][j]=='.')
					continue;
				int k=j+1;
				while(k<=m&&Map[i][k]=='*')
					++k;
				for(int p=j;p<=k-1;++p)
					l[i][p]=j,r[i][p]=k-1;
				j=k-1;
			}
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				for(int k=i;k<=n;++k)
				{
					if(Map[k][j]=='.')
						break;
					int L=j-(k-i),R=j+(k-i);
					if(l[k][j]>L||r[k][j]<R)
						break;
					++ans;
				}
		printf("%d\n",ans);
	}
	return 0;
}