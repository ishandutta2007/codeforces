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
signed main()
{
    int t,n,m,ans;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	m=read();
    	ans=n*(n+1)/2;
    	n-=m;
    	m++;
    	ans-=(n%m)*(n/m+1)*(n/m+2)/2+(m-n%m)*(n/m)*(n/m+1)/2;
    	printf("%lld\n",ans);
	}
    return 0;
}