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
int a[200005];
int main()
{
	int t,n,sl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		sl=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			sl=(sl+a[i]-1)%2;
		}
		if(sl==0)printf("maomao90\n");
		else printf("errorgorn\n");
	} 
	return 0;
}