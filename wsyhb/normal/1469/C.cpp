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
int h[max_n],l[max_n],r[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",h+i);
		bool flag=true;
		l[1]=r[1]=h[1]+k;
		for(int i=2;i<=n;++i)
		{
			l[i]=h[i]+k,r[i]=h[i]+2*k-1;
//			printf("i=%d l[i]=%d r[i]=%d\n",i,l[i],r[i]);
			if(r[i-1]<=l[i]-k||l[i-1]-k>=r[i])
			{
				flag=false;
				break;
			}
			l[i]=max(l[i],l[i-1]-k+1);
			r[i]=min(r[i],r[i-1]-1+k);
//			printf("i=%d l[i]=%d r[i]=%d\n",i,l[i],r[i]);
		}
		if(l[n]>h[n]+k||r[n]<h[n]+k)
			flag=false;
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}