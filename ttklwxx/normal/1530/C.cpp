#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int a[200005],b[200005],sa[200005],sb[200005];
int main()
{
	int t,n,k,sth,gre;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sa[n+1]=0;
		sb[n+1]=0;
		for(int i=n;i>=1;i--)sb[i]=sb[i+1]+b[i],sa[i]=sa[i+1]+a[i];
		for(int i=0;i<=n;i++)
		{
			k=(n+i)-(n+i)/4;
			if(i>=k)sth=100*k;
			else sth=100*i+sa[n-k+1+i];
			if(k>=n)gre=sb[1];
			else gre=sb[n-k+1];
			if(sth>=gre)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}