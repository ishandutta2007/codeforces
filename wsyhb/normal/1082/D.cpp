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
const int max_n=500+5;
int a[max_n];
vector<int> node1,node2;
typedef pair<int,int> P;
vector<P> ans;
int main()
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		sum+=a[i];
	}
	if(sum<2*n-2)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]==1)
			node1.push_back(i);
		else
			node2.push_back(i);
	}
	for(int i=0;i+1<int(node2.size());++i)
	{
		ans.push_back(P(node2[i],node2[i+1]));
		--a[node2[i]],--a[node2[i+1]];
	}
	int d=int(node2.size())-1;
	if(node1.size())
	{
		++d;
		ans.push_back(P(node1.back(),node2[0]));
		node1.pop_back();
		--a[node2[0]];
	}
	if(node1.size())
	{
		++d;
		ans.push_back(P(node1.back(),node2.back()));
		node1.pop_back();
		--a[node2.back()];
	}
	while(node1.size())
	{
		int x=node1.back();
		node1.pop_back();
		while(a[node2.back()]==0)
		{
			node2.pop_back();
			assert(node2.size());
		}
		ans.push_back(P(x,node2.back()));
		--a[node2.back()];
	}
	printf("YES %d\n",d);
	printf("%d\n",int(ans.size()));
	for(int i=0;i<int(ans.size());++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}