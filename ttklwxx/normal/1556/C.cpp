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
int a[100005];
signed main()
{
	int n,ls,rs;
	unsigned long long ans=0; 
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i+=2)
	{
		ls=0;
		rs=0;
		for(int j=i+1;j<=n;j+=2)
		{
			ans=ans+(unsigned long long)max(min(a[i]-max(rs,(int)1)+1,a[j]-max(ls,(int)1)+1),(int)0);
			if(ls<a[j])
			{
				rs=rs+a[j]-ls;
				ls=a[j+1];
			}
			else
			{
				rs=rs;
				ls=ls-a[j]+a[j+1];
			}
		}
	}
	printf("%llu\n",ans);
	return 0;
}