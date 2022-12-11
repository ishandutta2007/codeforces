#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1e5+5;
char buf[buffer_size],*S,*T;
inline char read_char()
{
	if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
	return S!=T?*(S++):EOF;
}
inline int read_int()
{
	bool flag=false;
	char c=read_char();
	while(c<'0'||c>'9')
	{
		flag=(c=='-'?true:flag);
		c=read_char();
	}
	int x=0;
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=read_char();
	}
	return flag?-x:x;
}
const int P=1e9+7;
const int max_n=2e5+5;
char s[max_n];
int power[max_n];
int la[max_n],lb[max_n],lc[max_n],l[max_n],ra[max_n],rb[max_n],rc[max_n],r[max_n];
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	power[0]=1;
	for(int i=1;i<=n;++i)
		power[i]=3ll*power[i-1]%P;
	for(int i=1;i<=n;++i)
	{
		la[i]=la[i-1]+(s[i]=='a');
		lb[i]=lb[i-1]+(s[i]=='b');
		lc[i]=lc[i-1]+(s[i]=='c');
		l[i]=l[i-1]+(s[i]=='?');
	}
	for(int i=n;i>=1;--i)
	{
		ra[i]=ra[i+1]+(s[i]=='a');
		rb[i]=rb[i+1]+(s[i]=='b');
		rc[i]=rc[i+1]+(s[i]=='c');
		r[i]=r[i+1]+(s[i]=='?');
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='b'||s[i]=='?')
		{
			int k=l[n]-(s[i]=='?');
			ans=(ans+1ll*la[i-1]*rc[i+1]%P*power[k])%P;
			if(k>=1)
			{
				ans=(ans+1ll*la[i-1]*r[i+1]%P*power[k-1])%P;
				ans=(ans+1ll*l[i-1]*rc[i+1]%P*power[k-1])%P;
			}
			if(k>=2)
				ans=(ans+1ll*l[i-1]*r[i+1]%P*power[k-2])%P;
		}
	printf("%d",ans);
	return 0;
}