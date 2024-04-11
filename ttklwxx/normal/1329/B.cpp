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
int a[60],ans[60];
signed main()
{
	int t,d,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	    d=read();
	    m=read();
	    for(int j=0;(1LL<<j)<=d;j++)
	    {
	    	a[j]=min(d,(1LL<<(j+1))-1)-(1<<j)+1;
	    	a[j]%=m;
		}
		ans[0]=a[0];
		if(d==1){printf("%lld\n",a[0]);continue;}
		for(int j=1;(1LL<<j)<=d;j++)
		{
			ans[j]=1LL*a[j]*(ans[j-1]+1)%m;
			ans[j]=(ans[j]+ans[j-1])%m;
			if((1LL<<(j+1))>d)printf("%lld\n",ans[j]);
		}
    }
	return 0;
}