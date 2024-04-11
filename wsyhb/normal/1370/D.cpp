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
int n,k;
const int max_n=2e5+5;
int a[max_n],b[max_n];
vector<int> id;
inline bool check(int x)
{
	id.clear();
	for(int i=1;i<=n&&int(id.size())<(k+1)/2;++i)
	{
		if(a[i]<=x&&(id.empty()||id.back()!=i-1))
			id.push_back(i);
	}
	if(int(id.size())==(k+1)/2)
	{
		if(k&1)
			return true;
		else
		{
			if(id.back()<n)
				return true;
		}
	}
	id.clear();
	for(int i=2;i<=n&&int(id.size())<k/2;++i)
	{
		if(a[i]<=x&&(id.empty()||id.back()!=i-1))
			id.push_back(i);
	}
	if(int(id.size())==k/2)
	{
		if(k&1)
		{
			if(id.back()<n)
				return true;
		}
		else
			return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int l=1,r=n,mid,res=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(b[mid]))
			res=mid,r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",b[res]);
	return 0;
}