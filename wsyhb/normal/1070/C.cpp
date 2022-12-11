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
const int max_n=1e6+5;
typedef pair<int,int> P;
vector<P> v[max_n];
const int max_p=1e6+5;
long long cnt[max_p<<2],sum[max_p<<2];
void modify(int p,int l,int r,int k,int v)
{
	cnt[p]+=v;
	sum[p]+=1ll*k*v;
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(k<=mid)
			modify(p<<1,l,mid,k,v);
		else
			modify(p<<1|1,mid+1,r,k,v);
	}
}
long long ans;
void query(int p,int l,int r,int v)
{
	if(l==r)
	{
		ans+=min(1ll*v,cnt[p])*l;
		return;
	}
	int mid=(l+r)>>1;
	if(cnt[p<<1]>=v)
		query(p<<1,l,mid,v);
	else
	{
		ans+=sum[p<<1];
		query(p<<1|1,mid+1,r,v-cnt[p<<1]);
	}
}
int main()
{
	int n=IO::read_int(),k=IO::read_int(),m=IO::read_int();
	for(int i=1;i<=m;++i)
	{
		int l=IO::read_int(),r=IO::read_int(),c=IO::read_int(),p=IO::read_int();
		v[l].push_back(P(c,p));
		v[r+1].push_back(P(-c,p));
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<int(v[i].size());++j)
			modify(1,1,1e6,v[i][j].second,v[i][j].first);
		query(1,1,1e6,k);
	}
	printf("%lld\n",ans);
	return 0;
}