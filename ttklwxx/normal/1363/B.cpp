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
char str[100001];
int qz[100001];
int main()
{
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='0')qz[i]=qz[i-1];
			else qz[i]=qz[i-1]+1;
		}
		ans=1000000000;
		for(int i=0;i<=n;i++)
		{
			ans=min(ans,i-qz[i]+qz[n]-qz[i]);
			ans=min(ans,qz[i]+n-i-qz[n]+qz[i]);
		}
		printf("%d\n",ans);
	} 
	return 0;
}