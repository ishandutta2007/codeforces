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
char str[10];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int l=1,r=n,mid,res=-1;
	while(l<r)
	{
		mid=(l+r)>>1;
		printf("1 %d %d\n",mid,mid+1);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T')
			res=mid,r=mid-1;
		else
			l=mid+1;
	}
	if(res==-1)
		res=l;
	else if(l==r)
	{
		printf("1 %d %d\n",res,l);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='N')
			res=l;
	}
//	fprintf(stderr,"res=%d\n",res);
	int x=res;
	l=1,r=x-1,res=-1;
	while(r-l+1>=3)
	{
		mid=((l+r)>>1)-1;
		printf("1 %d %d\n",mid,mid+1);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T')
			res=mid,r=mid-1;
		else
			l=mid+1;
	}
	if(res!=-1)
	{
		printf("1 %d %d\n",res,x);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T')
		{
			printf("2 %d %d\n",x,res);
			return 0;
		}
	}
	for(int i=l;i<=r;++i)
	{
		printf("1 %d %d\n",i,x);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T')
		{
			printf("2 %d %d\n",x,i);
			return 0;
		}
	}
	l=x+1,r=n,res=-1;
	while(r-l+1>=3)
	{
		mid=(l+r+1)>>1;
		printf("1 %d %d\n",mid,mid+1);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T')
			res=mid,r=mid-1;
		else
			l=mid+1;
	}
	if(res!=-1)
	{
		printf("1 %d %d\n",res,x);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T')
		{
			printf("2 %d %d\n",x,res);
			return 0;
		}
	}
	for(int i=l;i<=r;++i)
	{
		printf("1 %d %d\n",i,x);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T')
		{
			printf("2 %d %d\n",x,i);
			return 0;
		}
	}
	return 0;
}