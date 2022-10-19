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
signed main()
{
	int t,c,h,mb,x,k;
	t=read();
	for(int i=1;i<=t;i++)
	{
		h=read()*2;
		c=read()*2;
		mb=read()*2;
		x=(c+h);
		if(mb>=h)
		{
			printf("1\n");
			continue;
		}
		if(mb<=x/2)
		{
			printf("2\n");
			continue;
		}
		k=(h-mb)/(2*mb-x);
		//printf("%lf\n",fabs((double)(k*x+h)/(2*k+1)-mb));
		//printf("%lf\n",fabs((double)((k+1)*x+h)/(2*k+3)-mb));
		if(abs((k*x+h)*(2*k+3)-mb*(2*k+1)*(2*k+3))<=abs((((k+1)*x+h)*(2*k+1)-mb*(2*k+1)*(2*k+3))))
		{
			printf("%lld\n",2*k+1);
		}
		else
		{
			printf("%lld\n",2*k+3);
		}
	}
	return 0;
}