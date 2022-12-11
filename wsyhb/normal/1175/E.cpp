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
struct Interval
{
	int l,r;
}p[max_n];
bool cmp(Interval a,Interval b)
{
	return a.l!=b.l?a.l<b.l:a.r>b.r;
}
int L[max_n],R[max_n],k;
const int max_log=17+5;
int f[max_log][max_n];
int main()
{
	int n=IO::read_int(),m=IO::read_int();
	for(int i=1;i<=n;++i)
		p[i].l=IO::read_int(),p[i].r=IO::read_int();
	sort(p+1,p+n+1,cmp);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(p[i].r>now)
		{
			L[++k]=p[i].l;
			R[k]=p[i].r;
			now=p[i].r;
		}
	}
	for(int i=1;i<=k;++i)
	{
		int x=upper_bound(L+i,L+k+1,R[i])-L-1;
		f[0][i]=x;
	}
	for(int i=1;i<=17;++i)
		for(int j=k;j>=1;--j)
			f[i][j]=f[i-1][f[i-1][j]];
	for(int t=1;t<=m;++t)
	{
		int x=IO::read_int(),y=IO::read_int();
		int now=upper_bound(L+1,L+k+1,x)-L-1;
		if(now==0)
		{
			puts("-1");
			continue;
		}
		if(R[now]>=y)
		{
			puts("1");
			continue;
		}
		int ans=1;
		for(int i=17;i>=0;--i)
		{
			if(R[f[i][now]]<y)
			{
				now=f[i][now];
				ans+=1<<i;
			}
		}
		if(R[f[0][now]]>=y)
		{
			++ans;
			printf("%d\n",ans);
		}
		else
			puts("-1");
	}
	return 0;
}