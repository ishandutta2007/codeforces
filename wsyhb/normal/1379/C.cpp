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
int n,m,range;
const int max_m=1e5+5;
struct node
{
	int a,b;
}p[max_m];
bool cmp(node x,node y)
{
	return x.b<y.b;
}
int Hash[max_m];
struct BIT
{
	long long c[max_m];
	inline void init()
	{
		for(int i=1;i<=range;++i)
			c[i]=0;
	}
	inline void modify(int k,int v)
	{
		k=range+1-k;
		if(k>0)
		{
			for(int i=k;i<=range;i+=i&(-i))
				c[i]+=v;
		}
	}
	inline long long query(int k)
	{
		k=range+1-k;
		long long res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=c[i];
		return res;
	}
}cnt,sum;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&p[i].a,&p[i].b);
			Hash[i]=p[i].a;
		}
		sort(p+1,p+m+1,cmp);
		sort(Hash+1,Hash+m+1);
		range=unique(Hash+1,Hash+m+1)-Hash-1;
		for(int i=1;i<=m;++i)
			p[i].a=lower_bound(Hash+1,Hash+range+1,p[i].a)-Hash;
//		for(int i=1;i<=m;++i)
//			printf("i=%d %d %d\n",i,p[i].a,p[i].b);
//		for(int i=1;i<=range;++i)
//			printf("i=%d %d\n",i,Hash[i]);
		cnt.init();
		sum.init();
		long long ans=0;
		for(int i=1;i<=m;++i)
		{
			int x=lower_bound(Hash+1,Hash+range+1,p[i].b)-Hash; 
			int cnt_now=cnt.query(x);
			if(cnt_now<=n-1)
				ans=max(ans,sum.query(x)+Hash[p[i].a]+1ll*(n-1-cnt_now)*p[i].b);
			else
			{
				int L=1,R=range,mid,res=range+1;
				while(L<=R)
				{
					mid=(L+R)>>1;
					if(cnt.query(mid)<=n-1)
						res=mid,R=mid-1;
					else
						L=mid+1;
				}
				ans=max(ans,sum.query(res)+Hash[p[i].a]+1ll*(n-1-cnt.query(res))*Hash[res-1]);
			}
			cnt.modify(p[i].a,1);
			sum.modify(p[i].a,Hash[p[i].a]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}