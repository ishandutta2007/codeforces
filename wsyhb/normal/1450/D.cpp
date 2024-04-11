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
int n;
const int max_n=3e5+5;
int a[max_n];
const int max_log=18+5;
int f[max_log][max_n],Log[max_n];
void init()
{
	for(int i=1;i<=n;++i)
		f[0][i]=a[i];
	Log[0]=-1;
	for(int i=1;i<=n;++i)
		Log[i]=Log[i>>1]+1;
	for(int i=1;i<=Log[n];++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
}
int get_min(int l,int r)
{
	int x=Log[r-l+1];
	return min(f[x][l],f[x][r-(1<<x)+1]);
}
bool vis[max_n];
char ans[max_n];
int main()
{
	int t=IO::read_int();
	while(t--)
	{
		n=IO::read_int();
		for(int i=1;i<=n;++i)
			a[i]=IO::read_int();
		init();
		for(int i=1;i<=n;++i)
		{
			ans[i]='0';
			vis[i]=false;
		}
		ans[n+1]='\0';
		for(int i=1;i<=n;++i)
			vis[a[i]]=true;
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)
			ans[1]='1';
		if(get_min(1,n)==1)
			ans[n]='1';
		int l=1,r=n;
		for(int x=1;x<n;++x)
		{
			if(a[l]==x)
				++l;
			else if(a[r]==x)
				--r;
			else
				break;
			if(get_min(l,r)==x+1)
				ans[n-x]='1';
		}
		printf("%s\n",ans+1);
	}
	return 0;
}