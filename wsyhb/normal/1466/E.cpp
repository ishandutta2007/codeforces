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
const int P=1e9+7;
const int max_n=5e5+5;
const int max_log=60+5;
bool mark[max_n][max_log];
int cnt[max_log];
vector<int> pos[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int j=0;j<60;++j)
			cnt[j]=0;
		for(int i=1;i<=n;++i)
		{
			long long x;
			scanf("%lld",&x);
			pos[i].clear();
			for(int j=0;j<60;++j)
			{
				if(x&(1ll<<j))
				{
					mark[i][j]=true;
					++cnt[j];
					pos[i].push_back(j);
				}
				else
					mark[i][j]=false;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			long long sum1=0;
			for(int a=0;a<int(pos[i].size());++a)
			{
				int now=pos[i][a];
				sum1=(sum1+(1ll<<now)%P*cnt[now])%P;
			}
			long long sum2=0;
			for(int a=0;a<60;++a)
			{
				if(mark[i][a])
					sum2=(sum2+(1ll<<a)%P*n)%P;
				else
					sum2=(sum2+(1ll<<a)%P*cnt[a])%P;
			}
			ans=(ans+sum1*sum2)%P;
		}
		printf("%lld\n",ans);
	}
	return 0;
}