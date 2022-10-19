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
int b[800004];
char s[5];
char ans[800004];
int cnt;
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans[0]=0;
		cnt=0;
		for(int i=1;i<=n-2;i++)
		{
			scanf("%s",s+1);
			if(s[1]==ans[cnt])ans[++cnt]=s[2];
			else 
			{
				ans[++cnt]=s[1];
				ans[++cnt]=s[2];
			}
		}
		if(cnt==n-1)ans[n]='a';
		ans[n+1]='\0';
		printf("%s\n",ans+1);
	}
	return 0;
}