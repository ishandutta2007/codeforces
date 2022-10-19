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
int tans[200005],a[200005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),tans[i]=0;
		for(int i=1;i<=n;i+=2)
		{
			tans[i]=-a[i+1];
			tans[i+1]=a[i];
		}
		if(n%2==1)
		{
			if(tans[n-1]!=a[n])
			{
				tans[n]=a[n-1];
				tans[n-1]-=a[n];
			}
			else
			{
				tans[n]=-a[n-1];
				tans[n-1]+=a[n];
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",tans[i]);
		printf("\n");
	}
	return 0;
}