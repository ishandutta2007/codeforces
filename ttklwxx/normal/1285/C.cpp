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
    int n;
    n=read();
    for(int i=sqrt(n);i>=1;i--)
    {
    	if(n%i!=0)continue;
    	if(gcd(i,n/i)==1)
    	{
    		printf("%lld %lld\n",i,n/i);
    		return 0;
		}
	}
    return 0;
}