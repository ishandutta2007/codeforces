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
int a[100001],lmin[100001],rmin[100001];
int main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		lmin[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[lmin[i-1]]>a[i])lmin[i]=i;
			else lmin[i]=lmin[i-1];
		}
		rmin[n]=n;
		for(int i=n-1;i>=1;i--)
		{
			if(a[rmin[i+1]]>a[i])rmin[i]=i;
			else rmin[i]=rmin[i+1];
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(a[lmin[i]]!=a[i]&&a[rmin[i]]!=a[i])
			{
				printf("YES\n");
				printf("%d %d %d\n",lmin[i],i,rmin[i]);
				flag=true;
				break;
			}
		}
		if(flag==false)printf("NO\n");
	} 
	return 0;
}