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
int a[100001];
int main()
{
	int n,t,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int j=0;;j++)if((1<<(j+1))>n)
		{
			ans=j;
			break;
		}
		n--;
		printf("%d\n",ans);
		a[0]=1; 
		for(int j=1;j<=ans;j++)
		{
			a[j]=n/((1<<(ans-j+1))-1);
			if((n%((1<<(ans-j+1))-1))!=0)a[j]++;
			n-=a[j];
			printf("%d ",a[j]-a[j-1]);
		}
		printf("\n");
	}
	return 0;
}