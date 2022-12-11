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
const int max_n=2e5+5;
int l[max_n],r[max_n];
const int range=1e9+1;
const int max_size=13e6+5;
int ls[max_size],rs[max_size],val[max_size],lazy[max_size],cnt_node=1;
inline void push_down(int p)
{
	if(!ls[p])
		ls[p]=++cnt_node;
	if(!rs[p])
		rs[p]=++cnt_node;
	val[ls[p]]+=lazy[p];
	val[rs[p]]+=lazy[p];
	lazy[ls[p]]+=lazy[p];
	lazy[rs[p]]+=lazy[p];
	lazy[p]=0;
}
void modify(int p,int l,int r,int a,int b,int v)
{
	if(a<=l&&r<=b)
	{
		val[p]+=v;
		lazy[p]+=v;
		return;
	}
	if(lazy[p])
		push_down(p);
	int mid=(l+r)>>1;
	if(a<=mid)
	{
		if(!ls[p])
			ls[p]=++cnt_node;
		modify(ls[p],l,mid,a,b,v);
	}
	if(b>mid)
	{
		if(!rs[p])
			rs[p]=++cnt_node;
		modify(rs[p],mid+1,r,a,b,v);
	}
	val[p]=min(val[ls[p]],val[rs[p]]);
}
int res;
void query(int p,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
	{
		res=min(res,val[p]);
		return;
	}
	if(lazy[p])
		push_down(p);
	int mid=(l+r)>>1;
	if(a<=mid)
		query(ls[p],l,mid,a,b);
	if(b>mid)
		query(rs[p],mid+1,r,a,b);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",l+i,r+i);
		++l[i],++r[i];
		modify(1,1,range,l[i],r[i],1);
	}
	for(int i=1;i<=n;++i)
	{
		res=1e9;
		query(1,1,range,l[i],r[i]);
		if(res>=2)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}