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
const int max_n=1e5+5;
int a[max_n];
map<long long,bool> vis;
void solve(int l,int r)
{
	long long sum=0;
	for(int i=l;i<=r;++i)
		sum+=a[i];
	vis[sum]=true;
	int mid=(a[l]+a[r])>>1;
	int id=l-1;
	for(int i=l;i<=r;++i)
	{
		if(a[i]<=mid)
			id=i;
		else
			break;
	}
	bool flag1=(l<=id),flag2=(id+1<=r);
	if(!flag1||!flag2)
		return;
	solve(l,id);
	solve(id+1,r);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		vis.clear();
		sort(a+1,a+n+1);
		solve(1,n);
		for(int i=1;i<=q;++i)
		{
			long long s;
			scanf("%lld",&s);
			if(vis[s])
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}