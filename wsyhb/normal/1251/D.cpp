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
int l[max_n],r[max_n];
priority_queue<int,vector<int>,greater<int> > q;
int n;
long long s;
inline bool check(int v)
{
	while(q.size())
		q.pop();
	long long cost=0;
	int need=(n+1)>>1;
	for(int i=1;i<=n;++i)
	{
		if(r[i]<v)
			cost+=l[i];
		else if(l[i]>v)
		{
			cost+=l[i];
			--need;
		}
		else
			q.push(l[i]);
	}
	if(int(q.size())<need)
		return false;
	if(need<0)
		need=0;
	cost+=1ll*need*v;
	while(int(q.size())>need)
	{
		cost+=q.top();
		q.pop();
	}
	return cost<=s;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&s);
		for(int i=1;i<=n;++i)
			scanf("%d%d",l+i,r+i);
		int L=1,R=1e9,mid,res=0;
		while(L<=R)
		{
			mid=(L+R)>>1;
			if(check(mid))
				res=mid,L=mid+1;
			else
				R=mid-1;
		}
		printf("%d\n",res);
	}
	return 0;
}