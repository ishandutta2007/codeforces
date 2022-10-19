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
    int n,a,b;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	a=read();
    	b=read();
    	if((a+b)%3!=0)
    	{
    		printf("NO\n");
    		continue;
		}
		if(2*a>=b&&2*b>=a)printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}