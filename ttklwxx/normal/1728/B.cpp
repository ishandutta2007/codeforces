#include<bits/stdc++.h>
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
int a[1005];
int main()
{
	int t,n,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		a[n-2]=1;
		a[n-1]=n-1;
		a[n]=n;
		for(int i=2;i<=n-2;i++)a[i-1]=i;
		while(1)
		{
			random_shuffle(a+1,a+n-2);
			x=0;
			for(int i=1;i<=n-3;i++)
			{
				if(x<a[i])x+=a[i];
				else x=0;
			}
			if(x!=0)break;
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}