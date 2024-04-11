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
int gcd(int m,int n)
{
	while(m^=n^=m^=n%=m);
	return n;
}
signed main()
{
    int n,r,b,k,x;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	r=read();
    	b=read();
    	k=read();
    	if(r<b)swap(r,b);
    	x=gcd(r,b);
    	r/=x;
    	b/=x;
    	if((r-2)/b+1<k)printf("OBEY\n");
    	else printf("REBEL\n");
	}
    return 0;
}