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
const int max_n=50+5;
int w[max_n<<1];
vector<int> v;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n*2;++i)
		cin>>w[i];
	sort(w+1,w+2*n+1);
	int ans=1e9;
	for(int i=1;i<=n*2;++i)
		for(int j=i+1;j<=n*2;++j)
		{
			v.clear();
			for(int k=1;k<=n*2;++k)
			{
				if(k!=i&&k!=j)
					v.push_back(w[k]);
			}
			int tot=0;
			for(int i=0;i+1<int(v.size());i+=2)
				tot+=v[i+1]-v[i];
			ans=min(ans,tot);
		}
	cout<<ans<<endl;
	return 0;
}