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
	int read_int()
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
const int max_n=1e5+5;
char S[max_n];
int power[30],cnt[30];
int main()
{
	int n;
	long long T;
	scanf("%d%lld%s",&n,&T,S+1);
	for(int i=0;i<=26;++i)
		power[i]=1<<i;
	T-=power[S[n]-'a'];
	T+=power[S[n-1]-'a'];
	for(int i=1;i<=n-2;++i)
	{ 
		T+=power[S[i]-'a'];
		++cnt[S[i]-'a'+1];
	}
	if(T<0)
	{
		puts("No");
		return 0;
	}
	for(int i=0;i<26;++i)
	{
		if(T&power[i])
		{
			if(cnt[i]==0)
			{
				puts("No");
				return 0;
			}
			--cnt[i];
			T-=power[i];
		}
		cnt[i+1]+=cnt[i]>>1;
	}
	for(int i=0;i<=cnt[26];++i)
	{
		if(T==1ll*i*power[26])
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}