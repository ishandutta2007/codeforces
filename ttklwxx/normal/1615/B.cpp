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
int sl[200005][21];
int main()
{
	int t,l,r,ans=0;
	t=read();
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<=20;j++)sl[i][j]=sl[i-1][j];
		for(int j=0;j<=20;j++)
		{
			if(i&(1<<j))sl[i][j]++;
		}
	}
	for(int greg=1;greg<=t;greg++)
	{
		l=read();
		r=read();
		ans=0;
		for(int i=0;i<=20;i++)ans=max(ans,sl[r][i]-sl[l-1][i]);
		printf("%d\n",r-l+1-ans);
	} 
	return 0;
}