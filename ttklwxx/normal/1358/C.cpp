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
    int t,x1,x2,y1,y2;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	x1=read();
    	y1=read();
    	x2=read();
    	y2=read();
    	printf("%lld\n",(y2-y1)*(x2-x1)+1);
	}
	return 0;
}