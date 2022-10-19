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
char s[200005];
int main()
{
	int t,n,k,tans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		tans=0;
		for(int i=1;i<=n/2;i++)
		{
			if(s[i]=='0')tans++;
		}
		if(n%2==0)
		{
			if(tans>0)printf("BOB\n");
			else printf("DRAW\n");
		}
		else if(s[(n+1)/2]=='0') 
		{
			if(tans==0)printf("BOB\n");
			else printf("ALICE\n");
		}
		else
		{
			if(tans>0)printf("BOB\n");
			else printf("DRAW\n");
		}
	}
	return 0;
}