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
char b[200005];
int main()
{
	int t,n,p,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",b+1);
		p=0;
		for(int i=1;i<=n;i++)
		{
			x=b[i]-'0';
			if(x+1==p)printf("0"),p=x;
			else printf("1"),p=x+1;
		}
		printf("\n");
	} 
	return 0;
}