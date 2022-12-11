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
const int max_n=1e5+5;
struct node
{
	int t,id;
}p[max_n<<1];
bool cmp(node x,node y)
{
	return x.t<y.t;
}
int main()
{
	int n,h,m,k;
	scanf("%d%d%d%d",&n,&h,&m,&k);
	for(int i=1;i<=n;++i)
	{
		int h_i,m_i;
		scanf("%d%d",&h_i,&m_i);
		p[i].t=(1ll*h_i*m+m_i)%(m>>1);
		p[i].id=i;
		p[i+n].t=p[i].t+(m>>1);
		p[i+n].id=i;
	}
	sort(p+1,p+n*2+1,cmp);
	int ans=n,ans_l=1,ans_r=n,ans_t=0;
	int l=0,r=0;
	for(int i=1;i<=n;++i)
	{
		if(l<i)
			l=i;
		while(r<=n*2&&p[r].t<p[i-1].t+k)
			++r;
		while(p[l].t==p[i-1].t)
			++l;
		if(r-l<ans)
		{
			ans=r-l;
			ans_l=l,ans_r=r-1;
			ans_t=(p[i-1].t+k)%(m>>1);
		}
	}
	printf("%d %d\n",ans,ans_t);
	for(int i=ans_l;i<=ans_r;++i)
		printf("%d ",p[i].id);
	puts("");
	return 0;
}