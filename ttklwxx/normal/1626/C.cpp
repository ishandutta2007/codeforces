#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[400005];
int k[200005],h[200005];
int l[200005];
int sl[200005],sr[200005],ttop;
signed main()
{
	int t,n,x,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)k[i]=read();
		for(int i=1;i<=n;i++)h[i]=read();
		x=0;
		ans=0;
		ttop=0;
		for(int i=1;i<=n;i++)
		{
			l[i]=k[i]-h[i]+1;
			while(ttop>=1&&l[i]<=sr[ttop])
			{
				l[i]=min(l[i],sl[ttop]);
				ttop--;
			}
			sl[++ttop]=l[i];
			sr[ttop]=k[i];
		}
		for(int i=1;i<=ttop;i++)ans+=(sr[i]-sl[i]+1)*(sr[i]-sl[i]+2)/2;
		printf("%lld\n",ans);
	}
	return 0;
}