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
const int max_n=2e5+5;
int a[max_n];
vector<int> In,De;
int res[max_n];
int main()
{
	int n=IO::read_int();
	for(int i=1;i<=n;++i)
		a[i]=IO::read_int();
	for(int i=1;i<=n;++i)
		res[i]=-1;
	for(int i=1;i<=n;++i)
	{
		int j=i+1;
		bool flag=(a[i+1]<a[i]);
		while(j<=n&&(a[j]<a[j-1])==flag)
			++j;
		--j;
		for(int k=i;k<j;++k)
		{
			if(res[k]==-1)
			{
				res[k]=flag;
				if(flag)
					De.push_back(a[k]);
				else
					In.push_back(a[k]);
			}
		}
		if(flag)
		{
			if(In.empty()||a[j]>In.back())
			{
				res[j]=0;
				In.push_back(a[j]);
			}
			else
			{
				res[j]=1;
				De.push_back(a[j]);
			}
		}
		else
		{
			if(De.empty()||a[j]<De.back())
			{
				res[j]=1;
				De.push_back(a[j]);
			}
			else
			{
				res[j]=0;
				In.push_back(a[j]);
			}
		}
		if(j==n)
			break;
		i=j-1;
	}
	bool flag=true;
	for(int i=0;i+1<int(In.size());++i)
	{
		if(In[i]>=In[i+1])
		{
			flag=false;
			break;
		}
	}
	if(!flag)
	{
		puts("NO");
		return 0;
	}
	for(int i=0;i+1<int(De.size());++i)
	{
		if(De[i]<=De[i+1])
		{
			flag=false;
			break;
		}
	}
	if(!flag)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d%c",res[i],i<n?' ':'\n');
	return 0;
}