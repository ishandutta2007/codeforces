#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
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
char s[10005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		sort(s+1,s+n+1);
		printf("%s\n",s+1);
	}
	return 0;
}