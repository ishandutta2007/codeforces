#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
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
int a[200005],cnta;
int b[200005],cntb;
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int t,n,x,y;
	double ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		cnta=cntb=0;
		ans=0;
		for(int i=1;i<=2*n;i++)
		{
			x=read();
			y=read();
			if(x==0)
			{
				b[++cntb]=jdz(y);
			}
			else
			{
				a[++cnta]=jdz(x);
			}
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)ans=ans+sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.10lf\n",ans);
	} 
	return 0;
}