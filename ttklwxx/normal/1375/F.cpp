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
int sth[4];
signed main()
{
	int a,b,c,x;
	a=read();
	b=read();
	c=read();
	sth[1]=a;
	sth[2]=b;
	sth[3]=c;
	if(sth[1]>sth[2])swap(sth[1],sth[2]);
	if(sth[1]>sth[3])swap(sth[1],sth[3]);
	if(sth[2]>sth[3])swap(sth[2],sth[3]);
	printf("First\n");
	fflush(stdout);
	printf("%lld\n",2*sth[3]-sth[1]-sth[2]);
	fflush(stdout);
	x=read();
	if(x==0)return 0;
	if(x==1&&a!=sth[3])
	{
		printf("%lld\n",sth[3]-sth[1]-sth[2]+a);
		fflush(stdout);
		x=read();
		return 0;
	}
	else if(x==2&&b!=sth[3])
	{
		printf("%lld\n",sth[3]-sth[1]-sth[2]+b);
		fflush(stdout);
		x=read();
		return 0;
	}
	else if(x==3&&c!=sth[3])
	{
		printf("%lld\n",sth[3]-sth[1]-sth[2]+c);
		fflush(stdout);
		x=read();
		return 0;
	}
	else
	{
		sth[3]+=(2*sth[3]-sth[1]-sth[2]);
		printf("%lld\n",2*sth[3]-sth[1]-sth[2]);
		fflush(stdout);
		x=read();
		if(x==0)return 0;
		if(x==1)printf("%lld\n",sth[3]-sth[1]-sth[2]+a);
		else if(x==2)printf("%lld\n",sth[3]-sth[1]-sth[2]+b);
		else printf("%lld\n",sth[3]-sth[1]-sth[2]+c);
		fflush(stdout);
		x=read();
		return 0;
	}
	return 0;
}