#include<iostream>
#include<cstdio>
#include<map>
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
map<int,int>ma;
int b[400001];
signed main()
{
	int n,x,ans=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		ma[b[i]-i]+=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,ma[b[i]-i]);
	}
	printf("%lld\n",ans);
	return 0;
}