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
int n,m,q;
const int max_n=2e5+5;
namespace segment_tree
{
	set<int> sa[max_n],sb[max_n];
	struct Node
	{
		int a,b;
		bool flag;
	}tree[max_n<<2];
	inline void merge(int p)
	{
		tree[p].a=min(tree[p<<1].a,tree[p<<1|1].a);
		tree[p].b=max(tree[p<<1].b,tree[p<<1|1].b);
		tree[p].flag=tree[p<<1].flag|tree[p<<1|1].flag|(tree[p<<1].a<=tree[p<<1|1].b);
	}
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			sa[l].insert(m+1);
			sb[l].insert(0);
			tree[p].a=m+1;
			tree[p].b=0;
			tree[p].flag=false;
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		merge(p);
	}
	void modify_insert_a(int p,int l,int r,int k,int v)
	{
		if(l==r)
		{
			sa[l].insert(v);
			tree[p].a=min(tree[p].a,v);
			tree[p].flag=(tree[p].a<=tree[p].b);
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify_insert_a(p<<1,l,mid,k,v);
		else
			modify_insert_a(p<<1|1,mid+1,r,k,v);
		merge(p); 
	}
	void modify_insert_b(int p,int l,int r,int k,int v)
	{
		if(l==r)
		{
			sb[l].insert(v);
			tree[p].b=max(tree[p].b,v);
			tree[p].flag=(tree[p].a<=tree[p].b);
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify_insert_b(p<<1,l,mid,k,v);
		else
			modify_insert_b(p<<1|1,mid+1,r,k,v);
		merge(p);
	}
	void modify_erase_a(int p,int l,int r,int k,int v)
	{
		if(l==r)
		{
			sa[l].erase(v);
			tree[p].a=*sa[l].begin();
			tree[p].flag=(tree[p].a<=tree[p].b);
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify_erase_a(p<<1,l,mid,k,v);
		else
			modify_erase_a(p<<1|1,mid+1,r,k,v);
		merge(p);
	}
	void modify_erase_b(int p,int l,int r,int k,int v)
	{
		if(l==r)
		{
			sb[l].erase(v);
			tree[p].b=*(--sb[l].end());
			tree[p].flag=(tree[p].a<=tree[p].b);
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			modify_erase_b(p<<1,l,mid,k,v);
		else
			modify_erase_b(p<<1|1,mid+1,r,k,v);
		merge(p);
	}
}
typedef pair<int,int> P;
map<P,bool> mark;
int main()
{
	n=IO::read_int(),m=IO::read_int(),q=IO::read_int();
	segment_tree::build(1,1,n);
	for(int i=1;i<=q;++i)
	{
		int x=IO::read_int(),y=IO::read_int();
		bool flag_parity=x&1;
		bool flag_mark=mark[P(x,y)];
		mark[P(x,y)]=!flag_mark;
		x=(x+1)>>1,y=(y+1)>>1;
		if(flag_parity)
		{
			if(flag_mark)
				segment_tree::modify_erase_a(1,1,n,x,y);
			else
				segment_tree::modify_insert_a(1,1,n,x,y);
		}
		else
		{
			if(flag_mark)
				segment_tree::modify_erase_b(1,1,n,x,y);
			else
				segment_tree::modify_insert_b(1,1,n,x,y);
		}
		if(segment_tree::tree[1].flag)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}