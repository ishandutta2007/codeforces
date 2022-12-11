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
const int max_n=300+5;
char Map[max_n][max_n];
int cnt_o[4],cnt_x[4];
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
		for(int i=0;i<=2;++i)
			cnt_o[i]=cnt_x[i]=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				int x=(i+j)%3;
				if(Map[i][j]=='O')
					++cnt_o[x];
				else if(Map[i][j]=='X')
					++cnt_x[x];
			}
		int ans=1e9,ans1=0,ans2=0;
		for(int i=0;i<=2;++i)
			for(int j=0;j<=2;++j)
			{
				if(i!=j&&cnt_o[i]+cnt_x[j]<ans)
				{
					ans=cnt_o[i]+cnt_x[j];
					ans1=i,ans2=j;
				}
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				if(Map[i][j]!='.')
				{
					int x=(i+j)%3;
					if(x==ans1)
						Map[i][j]='X';
					else if(x==ans2)
						Map[i][j]='O';
				}
			}
		for(int i=1;i<=n;++i)
			printf("%s\n",Map[i]+1);
	}
	return 0;
}