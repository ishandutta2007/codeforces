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
char s[2005];
int main()
{
	int t,n,a,b,sl,sy;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		a=read();
		b=read();
		scanf("%s",s+1);
		sl=0;
		sy=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'&&s[i+1]!='0')sl++;
			if(s[i]=='1'&&s[i+1]!='1')sy++;
		}
		if(b<0)
		{
			printf("%d\n",a*n+b*(min(sl,sy)+1));
		}
		else
		{
			printf("%d\n",a*n+b*n);
		}
	}
	return 0;
}