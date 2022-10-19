#include<iostream>
#include<cstdio>
#include<cmath>
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
char s[400001];
int main()
{
	int t,n,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		s[n+1]=s[1];
		ans=0; 
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='>')
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			printf("%d\n",n);
			continue;
		}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='<')
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			printf("%d\n",n);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='-'||s[i+1]=='-')
			{
				ans++;
				continue;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}