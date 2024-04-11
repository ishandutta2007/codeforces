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
char s[1001][1001];
int main()
{
	int t,n,m,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		ans=0;
		for(int i=1;i<=m;i++)if(s[n][i]=='D')ans++;
		for(int i=1;i<=n;i++)if(s[i][m]=='R')ans++;
		printf("%d\n",ans);
	}
	return 0;
}