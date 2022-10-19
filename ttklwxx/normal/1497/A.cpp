#include<iostream>
#include<cstdio>
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
int a[1005],sl[1005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),sl[a[i]]++;
		for(int i=0;i<=100;i++)
		{
			if(sl[i]!=0)
			{
				sl[i]--;
				printf("%d ",i);
			}
		}
		for(int i=0;i<=100;i++)
		{
			while(sl[i]!=0)
			{
				sl[i]--;
				printf("%d ",i);
			}
		}
		printf("\n");
	} 
	return 0;
}