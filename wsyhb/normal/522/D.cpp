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
map<int,int> pos;
const int max_n=5e5+5;
int l[max_n],r[max_n];
int Log[max_n],f[20][max_n];
inline void init(int n)
{
	Log[0]=-1;
	for(int i=1;i<=n;++i)
	{
		Log[i]=Log[i>>1]+1;
		f[0][i]=r[i]-l[i];
	}
	for(int i=1;i<=Log[n];++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
}
inline int query(int l,int r)
{
	int k=Log[r-l+1];
	return min(f[k][l],f[k][r-(1<<k)+1]);
}
int main()
{
	int n=IO::read_int(),m=IO::read_int(),cnt=0;
	for(int i=1;i<=n;++i)
	{
		int x=IO::read_int();
		int id=pos[x];
		if(id!=0)
		{
			if(id>l[cnt])
				l[++cnt]=id,r[cnt]=i;
		}
		pos[x]=i;
	}
	init(cnt);
	for(int i=1;i<=m;++i)
	{
		int L=IO::read_int(),R=IO::read_int();
		int x=lower_bound(l+1,l+cnt+1,L)-l;
		int y=upper_bound(r+1,r+cnt+1,R)-r-1;
		if(x<=y)
			printf("%d\n",query(x,y));
		else
			puts("-1");
	}
	return 0;
}