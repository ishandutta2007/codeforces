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
inline void add(int &a,int b)
{
	a=a+b-(a+b>=P?P:0);
}
inline void mul(int &a,int b)
{
	a=1ll*a*b%P;
}
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=P?P:0);
}
inline int get_product(int a,int b)
{
	return 1ll*a*b%P;
}
const int max_n=5e3+5;
const int max_k=5e3+5;
int a[max_n],cnt[max_n];
int dp[max_n][max_n];//dp[i][j]:i steps from j
int main()
{
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		dp[0][i]=1;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=get_sum(dp[i-1][j-1],dp[i-1][j+1]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=k;++j)
			add(cnt[i],get_product(dp[j][i],dp[k-j][i]));
	int ans=0;
	for(int i=1;i<=n;++i)
		add(ans,get_product(a[i],cnt[i]));
	while(q--)
	{
		int i,x;
		scanf("%d%d",&i,&x);
		add(ans,P-get_product(a[i],cnt[i]));
		a[i]=x;
		add(ans,get_product(a[i],cnt[i]));
		printf("%d\n",ans);
	}
	return 0;
}