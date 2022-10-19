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
char s[100001],minn[100001];
int n;
bool bi(int i)
{
	if((n-i+1)%2==0)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[j]<minn[j-i+1])return true;
			if(s[j]>minn[j-i+1])return false;
		}
		for(int j=1;j<=i-1;j++)
		{
			if(s[j]<minn[j+n-i+1])return true;
			if(s[j]>minn[j+n-i+1])return false;
		}
		return false;
	}
	else
	{
		for(int j=i;j<=n;j++)
		{
			if(s[j]<minn[j-i+1])return true;
			if(s[j]>minn[j-i+1])return false;
		}
		for(int j=i-1;j>=1;j--)
		{
			if(s[j]<minn[n-j+1])return true;
			if(s[j]>minn[n-j+1])return false;
		}
		return false;
	}
}
int main()
{
	int t,mpos;
	t=read();
	for(int htr=1;htr<=t;htr++)
	{
		n=read();
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)minn[j]=s[j];
		minn[n+1]=0;
		mpos=1;
		for(int i=1;i<=n;i++)
		{
			if(bi(i))
			{
				if((n-i+1)%2==0)
				{
					for(int j=i;j<=n;j++)minn[j-i+1]=s[j];
					for(int j=1;j<=i-1;j++)minn[j+n-i+1]=s[j];
					mpos=i;
				}
				else
				{
					for(int j=i;j<=n;j++)minn[j-i+1]=s[j];
					for(int j=i-1;j>=1;j--)minn[n+1-j]=s[j];
					mpos=i;
				}
			}
		} 
		printf("%s\n",minn+1);
		printf("%d\n",mpos);
	}
	return 0;
}