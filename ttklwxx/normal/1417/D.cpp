#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100005];
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
	int t,n,het,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		het=0;
		for(int i=1;i<=n;i++)a[i]=read(),het+=a[i];
		if(het%n!=0)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",3*n-3);
		het/=n;
		for(int i=2;i<=n;i++)
		{
			x=(i-a[i]%i)%i;
			printf("%d %d %d\n",1,i,x);
			printf("%d %d %d\n",i,1,(a[i]+x)/i);
		}
		for(int i=2;i<=n;i++)printf("%d %d %d\n",1,i,het);
	}
	return 0;
}