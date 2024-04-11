#include<iostream>
#include<cstdio>
#include<cmath>
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
int gcd(int a,int b)
{
	while(a^=b^=a^=b%=a);
	return b;
}
signed main()
{
    int t,x,m,ans;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	x=read();
    	m=read();
    	m/=gcd(x,m);
    	ans=m;
    	for(int j=2;j<=sqrt(m);j++)
    	{
    		if(m%j==0)
    		{
    			ans=ans/j*(j-1);
    			while(m%j==0)m/=j;
			}
		}
		if(m>1)ans=ans/m*(m-1);
		printf("%lld\n",ans);
	}
    return 0;
}