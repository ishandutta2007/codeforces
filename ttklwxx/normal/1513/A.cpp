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
int main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		if(k>(n-1)/2)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=2*k+1;i++)
		{
			if(i%2==1)printf("%d ",n-2*k+(i-1)/2);
			else printf("%d ",n-i/2+1);
		}
		for(int i=1;i<=n-2*k-1;i++)printf("%d ",i);
		printf("\n");
	} 
	return 0;
}