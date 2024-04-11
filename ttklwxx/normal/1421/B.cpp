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
char s[305][305];
int main()
{
	int t,x,sth,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		if(s[1][2]==s[2][1])
		{
			sth=0;
			if(s[n][n-1]==s[1][2])sth++;
			if(s[n-1][n]==s[1][2])sth++;
			printf("%d\n",sth);
			if(s[n][n-1]==s[1][2])printf("%d %d\n",n,n-1);
			if(s[n-1][n]==s[1][2])printf("%d %d\n",n-1,n);
		}
		else
		{
			sth=1;
			if(s[n][n-1]!=s[n-1][n])sth++;
			printf("%d\n",sth);
			if(s[1][2]==s[n-1][n])printf("1 2\n");
			else printf("2 1\n");
			if(sth==2)printf("%d %d\n",n,n-1);
		}
	}
	return 0;
}