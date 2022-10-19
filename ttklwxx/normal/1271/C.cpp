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
	int n,sl1=0,sl2=0,sl3=0,sl4=0,sx,sy,x,y,maxn=-1,maxp;
	n=read();
	sx=read();
	sy=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		y=read();
		if(x>sx)sl1++;
		if(y>sy)sl2++;
		if(x<sx)sl3++;
		if(y<sy)sl4++;
	}
	if(sl1>maxn)
	{
		maxn=sl1;
		maxp=1;
	}
	if(sl2>maxn)
	{
		maxn=sl2;
		maxp=2;
	}
	if(sl3>maxn)
	{
		maxn=sl3;
		maxp=3;
	}
	if(sl4>maxn)
	{
		maxn=sl4;
		maxp=4;
	}
	printf("%lld\n",maxn);
	if(maxp==1)printf("%lld %lld\n",sx+1,sy);
	else if(maxp==2)printf("%lld %lld\n",sx,sy+1);
	else if(maxp==3)printf("%lld %lld\n",sx-1,sy);
	else printf("%lld %lld\n",sx,sy-1);
    return 0;
}