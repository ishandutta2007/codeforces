#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[1001];
int main()
{
	int t,a,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		a=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')a++;
		if(min(a,n-a)%2==0)printf("NET\n");
		else printf("DA\n");
	}
	return 0;
}