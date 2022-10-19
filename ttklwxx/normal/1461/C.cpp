#include<iostream>
#include<cstdio>
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
int a[200005];
int main()
{
	int t,n,m,k,r;
	double ans,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		k=n;
		while(k>=1&&a[k]==k)k--;
		ans=1;
		for(int i=1;i<=m;i++)
		{
			r=read();
			scanf("%lf",&x);
			if(r>=k)ans*=(1-x); 
		}
		if(k==0)printf("1.000000\n");
		else printf("%.6lf\n",1-ans);
	}
	return 0;
}