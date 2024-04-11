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
const int max_q=3e5+5;
int t[max_q],d[max_q];
const int max_t=1e6+5;
struct Node
{
	long long sum,wait;
	inline Node(long long x=0,long long y=0)
	{
		sum=x,wait=y;
	}
}tree[max_t<<2];
inline Node operator + (const Node &a,const Node &b)
{
	return Node(a.sum+b.sum,max(a.wait+b.sum,b.wait));
}
void build(int p,int l,int r)
{
	tree[p].wait=r;
	if(l<r)
	{
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
	}
}
void modify(int p,int l,int r,int k,int v)
{
	if(l==r)
	{
		tree[p].sum+=v;
		tree[p].wait+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(k<=mid)
		modify(p<<1,l,mid,k,v);
	else
		modify(p<<1|1,mid+1,r,k,v);
	tree[p]=tree[p<<1]+tree[p<<1|1];
}
Node res;
void query(int p,int l,int r,int k)
{
	if(r<=k)
	{
		res=res+tree[p];
		return;
	}
	int mid=(l+r)>>1;
	query(p<<1,l,mid,k);
	if(k>mid)
		query(p<<1|1,mid+1,r,k);
}
int main()
{
	build(1,1,1e6);
	int q=IO::read_int();
	for(int i=1;i<=q;++i)
	{
		char op;
		do
		{
			op=IO::read_char();
		}while(op!='+'&&op!='-'&&op!='?');
		if(op=='+')
		{
			t[i]=IO::read_int(),d[i]=IO::read_int();
			modify(1,1,1e6,t[i],d[i]);
		}
		else if(op=='-')
		{
			int k=IO::read_int();
			modify(1,1,1e6,t[k],-d[k]); 
		}
		else
		{
			int t=IO::read_int();
			res=Node();
			query(1,1,1e6,t);
			printf("%lld\n",res.wait-t); 
		}
	}
	return 0;
}