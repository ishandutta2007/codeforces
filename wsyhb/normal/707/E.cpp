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
struct node
{
	int x,y,w;
	inline node(int a=0,int b=0,int v=0)
	{
		x=a,y=b,w=v;
	}
};
int n,m,k;
const int max_n=2e3+5;
const int max_m=2e3+5;
const int max_k=2e3+5;
vector<node> g[max_k];
const int max_cnt_ask=2e3+5;
int X1[max_cnt_ask],Y1[max_cnt_ask],X2[max_cnt_ask],Y2[max_cnt_ask];
const int max_q=1e6+5;
int id[max_q],cnt_ask;
namespace BIT
{
	long long val[max_n][max_m];
	inline void modify(int x,int y,int v)
	{
		if(x>0&&y>0)
		{
			for(int i=x;i<=n;i+=i&(-i))
				for(int j=y;j<=m;j+=j&(-j))
					val[i][j]+=v;
		}
	}
	inline long long query(int x,int y)
	{
		long long res=0;
		for(int i=x;i>0;i-=i&(-i))
			for(int j=y;j>0;j-=j&(-j))
				res+=val[i][j];
		return res;
	}
}
long long ans[max_cnt_ask][max_k];
bool mark_off[max_k];
int main()
{
	n=IO::read_int(),m=IO::read_int(),k=IO::read_int();
	for(int i=1;i<=k;++i)
	{
		int sz=IO::read_int();
		g[i].resize(sz);
		for(int j=0;j<sz;++j)
			g[i][j].x=IO::read_int(),g[i][j].y=IO::read_int(),g[i][j].w=IO::read_int();
	}
	int q=IO::read_int();
	for(int i=1;i<=q;++i)
	{
		char op;
		do
		{
			op=IO::read_char();
		}while(op!='H'&&op!='K');
		if(op=='H')
			id[i]=IO::read_int();
		else
		{
			++cnt_ask;
			X1[cnt_ask]=IO::read_int(),Y1[cnt_ask]=IO::read_int(),X2[cnt_ask]=IO::read_int(),Y2[cnt_ask]=IO::read_int();
		}
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<int(g[i].size());++j)
			BIT::modify(g[i][j].x,g[i][j].y,g[i][j].w);
		for(int j=1;j<=cnt_ask;++j)
			ans[j][i]=BIT::query(X2[j],Y2[j])-BIT::query(X2[j],Y1[j]-1)-BIT::query(X1[j]-1,Y2[j])+BIT::query(X1[j]-1,Y1[j]-1);
		for(int j=0;j<int(g[i].size());++j)
			BIT::modify(g[i][j].x,g[i][j].y,-g[i][j].w);
	}
	cnt_ask=0;
	for(int i=1;i<=q;++i)
	{
		if(id[i]>0)
			mark_off[id[i]]^=1;
		else
		{
			++cnt_ask;
			long long Ans=0;
			for(int j=1;j<=k;++j)
			{
				if(!mark_off[j])
					Ans+=ans[cnt_ask][j];
			}
			printf("%lld\n",Ans);
		}
	}
	return 0;
}