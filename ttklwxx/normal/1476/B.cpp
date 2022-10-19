#include<iostream>
#include<cstdio>
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
int p[1005];
signed main()
{
	int t,n,k,ans=0,sth=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)p[i]=read();
		ans=0;
		sth=p[1];
		for(int i=2;i<=n;i++)ans=max(ans,p[i]*100-sth*k),sth+=p[i];
		if(ans==0)printf("0\n");
		else printf("%lld\n",(ans-1)/k+1);
	}
	return 0;
}