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
char s[100005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		if(n>2)
		{
			printf("NO\n");
			continue;
		}
		else if(n==1)printf("YES\n");
		else
		{
			if(s[1]==s[2])printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}