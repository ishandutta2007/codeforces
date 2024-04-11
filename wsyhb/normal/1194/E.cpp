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
int cnt_h,cnt_v;
const int max_n=5e3+5;
struct segment
{
	int X1,Y1,X2,Y2;
	inline segment(int a=0,int b=0,int c=0,int d=0)
	{
		X1=a,Y1=b,X2=c,Y2=d; 
	}
}h[max_n],v[max_n];
inline bool cmp(const segment &p,const segment &q)
{
	return p.Y2<q.Y2;
}
int delta,range;
const int max_range=1e4+5;
namespace BIT
{
	int c[max_range];
	inline void clear()
	{
		for(int i=1;i<=range;++i)
			c[i]=0;
	}
	inline void modify(int k,int v)
	{
		for(int i=k+delta;i<=range;i+=i&(-i))
			c[i]+=v;
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k+delta;i>0;i-=i&(-i))
			res+=c[i];
		return res;
	}
}
int q[max_n],_head,_tail;
inline long long C2(int x)
{
	return 1ll*x*(x-1)>>1;
}
int main()
{
	int n=IO::read_int();
	for(int i=1;i<=n;++i)
	{
		int a=IO::read_int(),b=IO::read_int(),c=IO::read_int(),d=IO::read_int();
		if(a>c)
			swap(a,c);
		if(b>d)
			swap(b,d);
		delta=max(delta,1-a);
		range=max(range,c);
		if(a==c)
			v[++cnt_v]=segment(a,b,c,d);
		else
			h[++cnt_h]=segment(a,b,c,d);
	}
	range+=delta;
	sort(h+1,h+cnt_h+1,cmp);
	sort(v+1,v+cnt_v+1,cmp);
	long long ans=0;
	for(int i=1;i<=cnt_h;++i)
	{
		_head=1,_tail=0;
		BIT::clear();
		for(int j=1;j<=cnt_v;++j)
		{
			if(h[i].Y1>=v[j].Y1&&h[i].Y1<=v[j].Y2&&v[j].X1>=h[i].X1&&v[j].X1<=h[i].X2)
			{
				q[++_tail]=j;
				BIT::modify(v[j].X1,1);
			}
		}
		for(int j=i+1;j<=cnt_h;++j)
		{
			while(_head<=_tail&&v[q[_head]].Y2<h[j].Y1)
				BIT::modify(v[q[_head++]].X1,-1);
			int l=max(h[i].X1,h[j].X1),r=min(h[i].X2,h[j].X2);
			if(l<=r)
				ans+=C2(BIT::query(r)-BIT::query(l-1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}