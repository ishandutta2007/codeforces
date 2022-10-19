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
    int a,b,c,d,e,f,ans=0;
    a=read();
    b=read();
    c=read();
    d=read();
    e=read();
    f=read();
    for(int i=0;i<=min(a,d);i++)
    {
    	ans=max(ans,i*e+min(min(b,c),d-i)*f);
	}
	printf("%lld\n",ans);
    return 0;
}