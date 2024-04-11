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
int n,q;
const int max_n=2e5+5;
int p[max_n];
struct Node
{
	int op,x,id;//op=1:pre op=2:suf
	inline Node(int a=1,int b=0,int c=0)
	{
		op=a,x=b,id=c;
	}
};
vector<Node> vl[max_n],vr[max_n];
inline long long C2(int x)
{
	return 1ll*x*(x-1)>>1;
}
namespace BIT
{
	int c[max_n];
	inline void modify(int k,int v)
	{
		if(k>0)
		{
			for(int i=k;i<=n;i+=i&(-i))
				c[i]+=v;
		}
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=c[i];
		return res;
	}
}
const int max_q=2e5+5;
long long ans[max_q];
int main()
{
	n=IO::read_int(),q=IO::read_int();
	for(int i=1;i<=n;++i)
		p[i]=IO::read_int();
	for(int i=1;i<=q;++i)
	{
		int l=IO::read_int(),d=IO::read_int(),r=IO::read_int(),u=IO::read_int();
		ans[i]=C2(l-1)+C2(n-r)+C2(d-1)+C2(n-u);
		if(l>1&&d>1)
			vl[l-1].push_back(Node(1,d-1,i));
		if(l>1&&u<n)
			vl[l-1].push_back(Node(2,u+1,i));
		if(r<n&&d>1)
			vr[r+1].push_back(Node(1,d-1,i));
		if(r<n&&u<n)
			vr[r+1].push_back(Node(2,u+1,i));
	}
//	fprintf(stderr,"vl:\n");
	for(int i=1;i<=n;++i)
	{
		BIT::modify(p[i],1);
//		fprintf(stderr,"i=%d\n",i);
		for(int j=0;j<int(vl[i].size());++j)
		{
			int op=vl[i][j].op,x=vl[i][j].x,id=vl[i][j].id;
//			fprintf(stderr,"op=%d x=%d id=%d\n",op,x,id);
			if(op==1)
				ans[id]-=C2(BIT::query(x));
			else
				ans[id]-=C2(i-BIT::query(x-1));
		}
	}
//	fprintf(stderr,"vr:\n");
	for(int i=1;i<=n;++i)
	{
//		fprintf(stderr,"i=%d\n",i);
		for(int j=0;j<int(vr[i].size());++j)
		{
			int op=vr[i][j].op,x=vr[i][j].x,id=vr[i][j].id;
//			fprintf(stderr,"op=%d x=%d id=%d\n",op,x,id);
			if(op==1)
				ans[id]-=C2(BIT::query(x));
			else
				ans[id]-=C2((n-i+1)-BIT::query(x-1));
		}
		BIT::modify(p[i],-1);
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",C2(n)-ans[i]); 
	return 0;
}