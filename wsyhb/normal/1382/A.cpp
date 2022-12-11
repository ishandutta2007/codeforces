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
const int max_a=1e3+5;
bool vis_a[max_a],vis_b[max_a];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(vis_a,false,sizeof(vis_a));
		for(int i=1;i<=n;++i)
		{
			int x;
			cin>>x;
			vis_a[x]=true;
		}
		memset(vis_b,false,sizeof(vis_b));
		for(int i=1;i<=m;++i)
		{
			int x;
			cin>>x;
			vis_b[x]=true;
		}
		bool flag=true;
		for(int i=1;i<=1000;++i)
		{
			if(vis_a[i]&&vis_b[i])
			{
				flag=false;
				puts("YES");
				printf("1 %d\n",i);
				break;
			}
		}
		if(flag)
			puts("NO");
	} 
	return 0;
}