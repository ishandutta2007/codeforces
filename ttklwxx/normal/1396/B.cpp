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
int a[1001];
int main()
{
	int t,n,s=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		s=0;
		for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>s/2)
			{
				flag=true;
				break;
			}
		}
		if(flag==true||s%2==1)printf("T\n");
		else printf("HL\n");
	}
	return 0;
}