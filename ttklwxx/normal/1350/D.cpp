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
int a[500001],qz[500001],lmin[500001],rmax[500001];
signed main()
{
	int t,n,k;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	flag=false;
	if(n==1)
	{
		if(a[1]==k)printf("yes\n");
		else printf("no\n");
		continue;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			flag=true;
			break;
		}
	}
	if(flag==false)
	{
		printf("no\n");
		continue;
	}
	flag=false;
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]>=k&&a[i+1]>=k)
		{
			flag=true;
			break;
		}
	}
	if(flag==true)
	{
		printf("yes\n");
		continue;
	}
	for(int i=1;i<=n-2;i++)
	{
		if(a[i]>=k&&a[i+2]>=k)
		{
				flag=true;
				break;
		}
    }
    if(flag==true)
    {
    	printf("yes\n");
    	continue;
	}
	printf("no\n");
	}
	return 0;
}