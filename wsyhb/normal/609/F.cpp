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
struct Frog
{
	int x,id,cnt;
	long long t;
}f[max_n];
inline bool cmp(const Frog &a,const Frog &b)
{
	return a.x<b.x;
}
long long val[max_n<<2];
void build(int p,int l,int r)
{
	if(l==r)
	{
		val[p]=f[l].x+f[l].t;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	val[p]=max(val[p<<1],val[p<<1|1]);
}
int res;
void query(int p,int l,int r,int v)
{
	if(val[p]<v)
		return;
	if(l==r)
	{
		if(f[l].x<=v)
			res=l;
		return;
	}
	int mid=(l+r)>>1;
	if(val[p<<1]>=v)
		query(p<<1,l,mid,v);
	else
		query(p<<1|1,mid+1,r,v);
}
void modify(int p,int l,int r,int k)
{
	if(l==r)
	{
		val[p]=f[l].x+f[l].t;
		return;
	}
	int mid=(l+r)>>1;
	if(k<=mid)
		modify(p<<1,l,mid,k);
	else
		modify(p<<1|1,mid+1,r,k);
	val[p]=max(val[p<<1],val[p<<1|1]);
}
int ans_cnt[max_n];
long long ans_t[max_n];
typedef pair<int,int> P;
multiset<P> s;
multiset<P>::iterator it,it1;
int main()
{
	int n=IO::read_int(),m=IO::read_int();
	for(int i=1;i<=n;++i)
		f[i].x=IO::read_int(),f[i].t=IO::read_int(),f[i].id=i;
	sort(f+1,f+n+1,cmp);
	build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int p=IO::read_int(),b=IO::read_int();
		res=-1;
		query(1,1,n,p);
		if(res!=-1)
		{
			++f[res].cnt;
			f[res].t+=b;
			it=s.lower_bound(P(f[res].x,0));
			while(it!=s.end())
			{
				int p=(*it).first,b=(*it).second;
				if(p>f[res].x+f[res].t)
					break;
				++f[res].cnt;
				f[res].t+=b;
				it1=it++;
				s.erase(it1);
			}
			modify(1,1,n,res);
		}
		else
			s.insert(P(p,b));
	}
	for(int i=1;i<=n;++i)
		ans_cnt[f[i].id]=f[i].cnt,ans_t[f[i].id]=f[i].t;
	for(int i=1;i<=n;++i)
		printf("%d %lld\n",ans_cnt[i],ans_t[i]);
	return 0;
}