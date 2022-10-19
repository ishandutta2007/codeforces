#include<iostream>
#include<cstdio>
#include<cmath>
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
int a[1000005],cnt;
int b[1000005],cntb;
int solve()
{
	if(cnt==1)return a[1];
	if(cnt==2)
	{
		printf("? %d %d\n",a[1],a[2]);
		fflush(stdout);
		int sth=read();
		if(sth==1)return a[1];
		else return a[2];
	}
	cntb=0;
	for(int i=1;i<=cnt;i+=4)
	{
		printf("? %d %d\n",a[i],a[i+2]);
		fflush(stdout);
		int sth=read();
		if(sth==0)
		{
			printf("? %d %d\n",a[i+1],a[i+3]);
			fflush(stdout);
			int sth=read();
			if(sth==1)b[++cntb]=a[i+1];
			else b[++cntb]=a[i+3];
		}
		else if(sth==1)
		{
			printf("? %d %d\n",a[i],a[i+3]);
			fflush(stdout);
			int sth=read();
			if(sth==1)b[++cntb]=a[i];
			else b[++cntb]=a[i+3];
		}
		else
		{
			printf("? %d %d\n",a[i+1],a[i+2]);
			fflush(stdout);
			int sth=read();
			if(sth==1)b[++cntb]=a[i+1];
			else b[++cntb]=a[i+2];
		}
	}
	cnt=cntb;
	for(int i=1;i<=cnt;i++)a[i]=b[i];
	return solve();
}
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		cnt=0;
		for(int i=1;i<=(1<<n);i++)a[++cnt]=i;
		int x=solve();
		printf("! %d\n",x);
		fflush(stdout);
	}
}