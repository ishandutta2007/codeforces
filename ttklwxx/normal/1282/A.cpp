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
    int t,a,b,c,r;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	a=read();
    	b=read();
    	if(a>b)swap(a,b);
    	c=read();
    	r=read();
    	printf("%lld\n",b-a-max(0LL,min(c+r,b)-max(c-r,a))); 
	}
    return 0;
}