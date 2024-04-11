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
const int max_size=76e5+5;
int cnt[max_size],ls[max_size],rs[max_size],cnt_node;
void build(int &p,int l,int r,int k,int v)
{
	if(!p)
		p=++cnt_node;
	cnt[p]+=v;
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(k<=mid)
			build(ls[p],l,mid,k,v);
		else
			build(rs[p],mid+1,r,k,v);
	}
}
void merge(int &p,int &q,int l,int r)
{
	if(!p||!q)
	{
		p|=q,q=0;
		return;
	}
	cnt[p]+=cnt[q],cnt[q]=0;
	if(l<r)
	{
		int mid=(l+r)>>1;
		merge(ls[p],ls[q],l,mid);
		merge(rs[p],rs[q],mid+1,r);
	}
	q=0;
}
void modify(int &p,int &q,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)
	{
		merge(p,q,l,r);
		return;
	}
	if(!p)
		p=++cnt_node;
	int mid=(l+r)>>1;
	if(a<=mid)
		modify(ls[p],ls[q],l,mid,a,b);
	if(b>mid)
		modify(rs[p],rs[q],mid+1,r,a,b);
	cnt[p]=cnt[ls[p]]+cnt[rs[p]];
	cnt[q]=cnt[ls[q]]+cnt[rs[q]];
}
const int max_n=2e5+5;
int ans[max_n];
void solve(int p,int l,int r,int k)
{
//	fprintf(stderr,"p=%d l=%d r=%d k=%d\n",p,l,r,k);
	if(!p)
		return;
	if(l==r)
	{
		ans[l]=k;
		return;
	}
	int mid=(l+r)>>1;
	solve(ls[p],l,mid,k);
	solve(rs[p],mid+1,r,k);
}
const int max_a=100+5;
int root[max_a];
int main()
{
	int n=IO::read_int();
	for(int i=1;i<=n;++i)
	{
		int x=IO::read_int();
		build(root[x],1,n,i,1);
	}
	int q=IO::read_int();
	while(q--)
	{
		int l=IO::read_int(),r=IO::read_int(),x=IO::read_int(),y=IO::read_int();
		if(x!=y)
			modify(root[y],root[x],1,n,l,r);
	}
	for(int i=1;i<=100;++i)
		solve(root[i],1,n,i);
	for(int i=1;i<=n;++i)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}