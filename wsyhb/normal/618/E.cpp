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
const double Pi=3.1415926535897932384626433832795;
const int max_n=3e5+5;
struct Node
{
	double sx,sy,lazy;
	inline void merge(const Node &a,const Node &b)
	{
		sx=a.sx+b.sx,sy=a.sy+b.sy;
	}
	inline void update(double ang)
	{
		lazy+=ang;
		double Cos=cos(ang),Sin=sin(ang);
		double x=sx*Cos+sy*Sin,y=sy*Cos-sx*Sin;
		sx=x,sy=y;
	}
}tree[max_n<<2];
inline void push_down(int p)
{
	tree[p<<1].update(tree[p].lazy);
	tree[p<<1|1].update(tree[p].lazy);
	tree[p].lazy=0;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		tree[p].sx=1;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p].merge(tree[p<<1],tree[p<<1|1]);
}
double res_x,res_y;
void query(int p,int l,int r,int k)
{
	if(l==r)
	{
		res_x=tree[p].sx,res_y=tree[p].sy;
		return;
	}
	if(tree[p].lazy)
		push_down(p);
	int mid=(l+r)>>1;
	if(k<=mid)
		query(p<<1,l,mid,k);
	else
		query(p<<1|1,mid+1,r,k);
}
void modify(int p,int l,int r,int k,double dx,double dy)
{
	tree[p].sx+=dx,tree[p].sy+=dy;
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(k<=mid)
			modify(p<<1,l,mid,k,dx,dy);
		else
			modify(p<<1|1,mid+1,r,k,dx,dy);
	}
}
void rotate(int p,int l,int r,int a,int b,double ang)
{
	if(a<=l&&r<=b)
	{
		tree[p].update(ang);
		return;
	}
	if(tree[p].lazy)
		push_down(p);
	int mid=(l+r)>>1;
	if(a<=mid)
		rotate(p<<1,l,mid,a,b,ang);
	if(b>mid)
		rotate(p<<1|1,mid+1,r,a,b,ang);
	tree[p].merge(tree[p<<1],tree[p<<1|1]);
}
int main()
{
	int n=IO::read_int(),m=IO::read_int();
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int x=IO::read_int(),y=IO::read_int(),z=IO::read_int();
		if(x==1)
		{
			query(1,1,n,y);
			double d=sqrt(res_x*res_x+res_y*res_y);
			modify(1,1,n,y,z*res_x/d,z*res_y/d);
		}
		else
		{
			double ang=z*Pi/180;
			rotate(1,1,n,y,n,ang);
		}
		printf("%.10lf %.10lf\n",tree[1].sx,tree[1].sy);
	}
	return 0;
}