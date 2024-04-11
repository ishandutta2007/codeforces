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
int dpl[400005],dpr[400005],dplo[400005],dpro[400005];
char s[400005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		dpl[0]=1;
		dplo[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='L')dpl[i]=dplo[i-1]+1;
			else dpl[i]=1;
			if(s[i]=='R')dplo[i]=dpl[i-1]+1;
			else dplo[i]=1;
		}
		dpr[n]=1;
		dpro[n]=1;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i+1]=='R')dpr[i]=dpro[i+1]+1;
			else dpr[i]=1;
			if(s[i+1]=='L')dpro[i]=dpr[i+1]+1;
			else dpro[i]=1;
		}
		for(int i=0;i<=n;i++)printf("%d ",dpl[i]+dpr[i]-1);
		printf("\n");
	}
	return 0;
}