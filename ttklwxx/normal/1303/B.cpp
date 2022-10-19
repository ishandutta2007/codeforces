#include<iostream>
#include<cstdio>
#include<cstring>
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
    int t,n,g,b,sth;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	g=read();
    	b=read();
    	sth=(n+1)/2;
    	if(sth%g!=0)printf("%lld\n",max(n,sth/g*(g+b)+sth%g));
    	else printf("%lld\n",max(n,sth/g*(g+b)-b));
	}
    return 0;
}