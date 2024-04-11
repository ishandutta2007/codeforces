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
	inline void Write(int x)
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
const int n=22;
struct edge
{
	int x,y,z;
	inline edge(int a,int b,int c)
	{
		x=a,y=b,z=c;
	}
	inline void print()
	{
		printf("%d %d %d\n",x,y,z);
	}
};
vector<edge> ans;
inline void add_edge(int a,int b,int c)
{
	ans.push_back(edge(a,b,c));
	assert(a<b&&c>0);
//	fprintf(stderr,"a=%d b=%d c=%d\n",a,b,c);
}
const int max_n=22+5;
int l[max_n],r[max_n];
void init()
{
	for(int i=2;i<=21;++i)
	{
		l[i]=1,r[i]=1<<(i-2);
		int now=l[i];
		for(int j=1;j<i;++j)
		{
			int len=now-l[j];
			add_edge(j,i,len);
			now=r[j]+len+1;
		}
	}
}
int main()
{
	init();
	int L=IO::read_int(),R=IO::read_int();
	add_edge(1,n,L);
	++L;
	int now=L,cnt=R-L+1;
	for(int i=2;i<=21;++i)
	{
		if(cnt&(1<<(i-2)))
		{
			int len=now-l[i];
			add_edge(i,n,len);
			now=r[i]+len+1;
		}
	}
	puts("YES");
	printf("%d %d\n",n,int(ans.size()));
	for(int i=0;i<int(ans.size());++i)
		ans[i].print();
	return 0;
}